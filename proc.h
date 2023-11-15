#pragma once

#include <Windows.h>
#include <TlHelp32.h>

DWORD GetProcId(WCHAR targetName[MAX_PATH]);

DWORD GetModAddr(WCHAR modName[MAX_MODULE_NAME32 + 1], DWORD procId);
