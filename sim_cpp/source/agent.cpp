#include "..//header//agent.h"

Agent::Agent(float minPay, float minPayPerMile, float maxMile, Position _pos) :

	minPayThreshold{ minPay },
	minPayPerMileThreshold{ minPayPerMile },
	maxMilesThreshold{ maxMile },
	pos{ _pos },
	isOnOrder{ false } {}

void Agent::Tick()
{
	if (IsOnOrder())
	{
		currentOrder.ticksToComplete--;
		if (currentOrder.ticksToComplete <= 0)
		{
			CompleteOrder();
		}
	}
}

void Agent::AcceptOrder(Order order)
{
	currentOrder = order;
	isOnOrder = true;
}

void Agent::CompleteOrder()
{
	this->metrics.ordersComplete++;
	this->metrics.milesDriven += currentOrder.milesToComplete;
	this->metrics.totalPay += currentOrder.pay;

	isOnOrder = false;
}	

bool Agent::IsOnOrder()
{
	return isOnOrder;
}

bool Agent::OrderMeetsThresholds(Order& order)
{
	float orderPay = order.pay;
	float orderMiles = order.milesToComplete;
	float orderPayPerMile = orderPay / orderMiles;

	if (orderPay >= this->minPayThreshold &&
		orderMiles <= this->maxMilesThreshold &&
		orderPayPerMile >= this->minPayPerMileThreshold)
	{
		return true;
	}
	return false;
}