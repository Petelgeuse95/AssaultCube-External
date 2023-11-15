#pragma once

#include <Windows.h>
#include <vector>

DWORD FindDMAAddr(HANDLE hProc, DWORD addrPtr, std::vector<unsigned int> offsets);