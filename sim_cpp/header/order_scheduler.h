#pragma once
#include <vector>

#include "order.h"
#include "agent.h"
#include "position.h"
#include "order_assignment.h"

class OrderScheduler
{
public:
	std::vector<Order> AssignOrders(std::vector<Order> orders, std::vector<Agent>& agents);
	std::vector<Agent*> GetSortedAgentsList(Position pos, std::vector<Agent>& agents);
};