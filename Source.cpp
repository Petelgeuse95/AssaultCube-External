#include "proc.h"
#include "mem.h"
#include "offset.h"

#include <iostream>

int main()
{
	// Get PID.
	WCHAR targetName[MAX_PATH] = L"ac_client.exe";
	DWORD processId{ 0 };
	processId = GetProcId(targetName);
	if (processId == 0)
		return -1;

	// Get Mod Address.
	WCHAR modName[MAX_MODULE_NAME32 + 1] = L"ac_client.exe";
	DWORD modBaseAddr{ 0 };
	modBaseAddr = GetModAddr(modName, processId);
	if (modBaseAddr == 0)
		return -2;

	// Get Process Handle.
	HANDLE hProcess{ 0 };
	hProcess = OpenProcess(PROCESS_VM_READ, 0, processId);
	if (hProcess == INVALID_HANDLE_VALUE)
		return -3;

	// Get Number of Total Player.
	int32_t totalPlayer{ 0 };
	DWORD totalPlayerAddr = modBaseAddr + offset_totalPlayer;
	if (!ReadProcessMemory(hProcess, (LPCVOID)totalPlayerAddr, &totalPlayer, sizeof(totalPlayer), 0))
		return -4;
	
	// Get Entity List.
	DWORD entListManagerAddr = modBaseAddr + offset_entListManager;
	DWORD entListAddr{ 0 };
	if (!ReadProcessMemory(hProcess, (LPCVOID)entListManagerAddr, &entListAddr, sizeof(entListAddr), 0))
		return -5;

	// Loop all Entities.
	DWORD entAddr{ 0 };
	std::vector<entity>players(totalPlayer);
	for (int32_t i{ 0 }; i < totalPlayer -1; i++)
	{
		entListAddr += 0x4; // Offset to next entity.
		ReadProcessMemory(hProcess, (LPCVOID)entListAddr, &entAddr, sizeof(entAddr), 0);
		ReadProcessMemory(hProcess, (LPCVOID)entAddr, &players[i], sizeof(players[i]), 0);
		std::cout << "[ " << players[i].name << " ]: " << players[i].isTeam << std::endl;
	}

	// Debug.
	std::cout << std::endl;
	std::cout << "[ CornerStone ] processId: " << processId << std::endl;
	std::cout << "[ CornerStone ] modBaseAddr: 0x" << std::uppercase << std::hex << modBaseAddr << std::endl;
	std::cout << "[ CornerStone ] totalPlayer: " << totalPlayer << std::endl;
	std::cout << "[ CornerStone ] entListAddr: 0x" << std::uppercase << std::hex << entListAddr << std::endl;

	CloseHandle(hProcess);
	return 0;
}