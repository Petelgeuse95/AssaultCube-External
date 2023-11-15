#include "proc.h"

DWORD GetProcId(WCHAR targetName[MAX_PATH])
{
	HANDLE hSnap{ 0 };
	DWORD processId{ 0 };
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap == INVALID_HANDLE_VALUE)
		return 0;

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnap, &pe32))
	{
		do
		{
			if (!wcscmp(targetName, pe32.szExeFile))
			{
				processId = pe32.th32ProcessID;
				break;
			}
		} while (Process32Next(hSnap, &pe32));
	}

	CloseHandle(hSnap);
	return processId;
}

DWORD GetModAddr(WCHAR modName[MAX_MODULE_NAME32 + 1], DWORD procId)
{
	HANDLE hSnap{ 0 };
	DWORD modAddr{ 0 };
	hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32 | TH32CS_SNAPMODULE, procId);
	if (hSnap == INVALID_HANDLE_VALUE)
		return 0;

	MODULEENTRY32 me32;
	me32.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hSnap, &me32))
	{
		do
		{
			if (!wcscmp(modName, me32.szModule))
			{
				modAddr = (DWORD)me32.modBaseAddr;	// Cast Byte* into DWORD.
				break;
			}
		} while (Module32Next(hSnap, &me32));
	}

	CloseHandle(hSnap);
	return modAddr;
}