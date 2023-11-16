#pragma once

#include"offset.h"

bool WorldToScreen(Vector3 pos, Vector3& posScreen, Matrix4x4 vMatrix, int windowWidth, int windowHeight);