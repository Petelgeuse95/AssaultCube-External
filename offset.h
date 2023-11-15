#include <stdint.h>
#include <vector>
// Created with ReClass.NET 1.2 by KN4CK3R

struct Vector3
{
	float x, y, z;
};

class entity
{
public:
	char pad_0000[4]; //0x0000
	Vector3 posHead; //0x0004
	char pad_0010[24]; //0x0010
	Vector3 pos; //0x0028
	Vector3 angle; //0x0034
	char pad_0040[172]; //0x0040
	int32_t health; //0x00EC
	int32_t shield; //0x00F0
	char pad_00F4[273]; //0x00F4
	char name[16]; //0x0205
	char pad_0215[247]; //0x0215
	int32_t isTeam; //0x030C
	char pad_0310[84]; //0x0310
	class weapon* currWeaponPtr; //0x0364
}; //Size: 0x0368

class weapon
{
public:
	char pad_0000[16]; //0x0000
	int32_t* magPtr; //0x0010
	int32_t* ammoPtr; //0x0014
}; //Size: 0x0018

unsigned long offset_entListManager = 0x18AC04;
unsigned long offset_totalPlayer = 0x18AC0C;