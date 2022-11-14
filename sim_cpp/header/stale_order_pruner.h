#pragma once
#include "order.h"
#include <vector>

class StaleOrderPruner
{
public:
	StaleOrderPruner(int maxTicksInQueue);
	std::vector<Order*> Prune(std::vector<Order*> orders);

private:
	int maxTicksInQueue;
};