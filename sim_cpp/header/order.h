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



	int restaurantID;
	Position pos;
	float pay;
	float milesToComplete;
	int ticksToComplete;
	int ticksInQueue;
};