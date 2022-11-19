#pragma once
#include "order.h"
#include "position.h"
#include "completed_order_metrics.h"

class Agent
{
public:
	Agent(float minPay, float minPayPerMile, float maxMile, Position _pos);

	void Tick();
	void AcceptOrder(Order order);
	void CompleteOrder();
	bool IsOnOrder();
	bool OrderMeetsThresholds(Order& order);
	Position Pos() { return pos; }

private:
	Order currentOrder;
	bool isOnOrder;
	CompletedOrderMetrics metrics;
	float minPayThreshold;
	float minPayPerMileThreshold;
	float maxMilesThreshold;
	Position pos;
};