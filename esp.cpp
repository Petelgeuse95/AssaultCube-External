#include "esp.h"

bool WorldToScreen(Vector3 pos, Vector3 &posScreen, Matrix4x4 vMatrix, int windowWidth, int windowHeight)
{
	Vector4 clipCoords;

	clipCoords.x = pos.x * vMatrix.x1 + pos.y * vMatrix.x2 + pos.z * vMatrix.x3 + vMatrix.x4;
	clipCoords.y = pos.x * vMatrix.y1 + pos.y * vMatrix.y2 + pos.z * vMatrix.y3 + vMatrix.y4;
	clipCoords.z = pos.x * vMatrix.z1 + pos.y * vMatrix.z2 + pos.z * vMatrix.z3 + vMatrix.z4;
	clipCoords.w = pos.x * vMatrix.w1 + pos.y * vMatrix.w2 + pos.z * vMatrix.w3 + vMatrix.w4;

	if (clipCoords.w < 0.1f)
		return false;

	Vector3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;

	posScreen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	posScreen.y = (windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);

	return true;
}
