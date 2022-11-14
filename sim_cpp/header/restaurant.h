#pragma once
#include "position.h"

struct Restaurant
{
	Restaurant(int _ID, Position _pos, int _orderFrequency) :
		ID{ _ID },
		pos{ _pos },
		orderFrequency{ _orderFrequency } {}


	int ID;
	Position pos;
	int orderFrequency;
};