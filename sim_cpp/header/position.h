#pragma once
#include <iostream>

struct Position
{
	Position(float _x, float _y) : x{ _x }, y{ _y } {}

	float x{ 0.0f };
	float y{ 0.0f };
};