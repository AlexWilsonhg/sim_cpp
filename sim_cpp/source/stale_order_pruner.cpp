#include "..//header//stale_order_pruner.h"

StaleOrderPruner::StaleOrderPruner(int maxTicksInQueue)
{
	this->maxTicksInQueue = maxTicksInQueue;
}

std::vector<Order> StaleOrderPruner::Prune(std::vector<Order>& orders)
{
	std::vector<Order> ordersNotPruned;
	ordersNotPruned.reserve(orders.size());
	for (Order& order : orders)
	{
		if (order.ticksInQueue <= this->maxTicksInQueue)
		{
			ordersNotPruned.push_back(order);
		}
	}
	return ordersNotPruned;
}