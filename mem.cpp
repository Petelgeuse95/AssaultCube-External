#include "mem.h"

DWORD FindDMAAddr(HANDLE hProc, DWORD addrPtr, std::vector<unsigned int> offsets)
{
	DWORD addr = addrPtr;
	for (unsigned int i : offsets)
	{
		ReadProcessMemory(hProc, (LPCVOID)addr, &addr, sizeof(addr), 0);
		addr += offsets[i];
	}
	return addr;
}