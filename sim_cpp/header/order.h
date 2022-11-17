#pragma once
#include "position.h"

struct Order
{
	Order(int restID, Position _pos, float _pay, float _milesToComplete, int _ticksToComplete) : 
		restaurantID{ restID },
		pos{ _pos },
		pay{ _pay },
		milesToComplete{ _milesToComplete },
		ticksToComplete{ _ticksToComplete },
		ticksInQueue{ 0 } {}



	int restaurantID{ 0 };
	Position pos{ 1.0f, 1.0f };
	float pay{ 0.0f };
	float milesToComplete{ 0.0f };
	int ticksToComplete{ 0 };
	int ticksInQueue{ 0 };
};