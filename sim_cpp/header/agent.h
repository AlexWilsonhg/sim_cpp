#pragma once
#include "order.h"
#include "position.h"
#include "completed_order_metrics.h"

class Agent
{
public:
	Agent(float minPay, float minPayPerMile, float maxMile, Position _pos);
	void AcceptOrder(Order* order);
	void CompleteOrder();
	bool OrderMeetsThresholds(Order* order);

public:
	Order* currentOrder;
	CompletedOrderMetrics metrics;
	float minPayThreshold;
	float minPayPerMileThreshold;
	float maxMilesThreshold;
	Position pos;
};