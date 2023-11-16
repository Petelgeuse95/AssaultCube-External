#include <stdint.h>
#include <vector>

struct Vector3
{
	float x, y, z;
};

struct Vector4
{
	float x, y, z, w;
};

struct Matrix4x4
{
	float x1, y1, z1, w1;
	float x2, y2, z2, w2;
	float x3, y3, z3, w3;
	float x4, y4, z4, w4;
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

unsigned long offset_width = 0x191ED8;
unsigned long offset_height = 0x191EDC;
unsigned long offset_vMatrix = 0x17dfd0;

class vMatrix
{
public:
	Matrix4x4 vMatrix; //0x0000
}; //Size: 0x0040