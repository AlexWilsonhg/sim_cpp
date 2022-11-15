#include "..//header//agent.h"

Agent::Agent(float minPay, float minPayPerMile, float maxMile, Position _pos) :

	minPayThreshold{ minPay },
	minPayPerMileThreshold{ minPayPerMile },
	maxMilesThreshold{ maxMile },
	pos{ _pos },
	currentOrder{ nullptr } {}

void Agent::AcceptOrder(Order* order)
{
	this->currentOrder = order;
}

void Agent::CompleteOrder()
{
	this->metrics.ordersComplete++;
	this->metrics.milesDriven += currentOrder->milesToComplete;
	this->metrics.totalPay += currentOrder->pay;

	delete(currentOrder);
}

bool Agent::OrderMeetsThresholds(const Order& order)
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