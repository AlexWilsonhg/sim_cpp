#pragma once
#include <iostream>
#include <cmath>

struct Position
{
	Position(float _x, float _y) : x{ _x }, y{ _y } {}
	static float dist(const Position& a, const Position& b)
	{
		return pow(b.x - a.x, 2.0f) + pow((b.y - a.y), 2.0f);
	}

	float x{ 0.0f };
	float y{ 0.0f };
};