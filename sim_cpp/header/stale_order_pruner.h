#pragma once
#include <vector>

#include "order.h"

class StaleOrderPruner
{
public:
	StaleOrderPruner(int maxTicksInQueue);
	std::vector<Order> Prune(std::vector<Order>& orders);

private:
	int maxTicksInQueue;
};