#pragma once
#include <vector>
#include <map>

#include "order.h"
#include "agent.h"
#include "position.h"
#include "order_assignment.h"

class OrderScheduler
{
public:
	void AssignOrders(std::vector<Order>& orders, std::vector<Agent>& agents);
	std::vector<Agent*> GetSortedAgentsList(int restaurantID);

private:
	void BuildSortedAgentsList(int restaurantID, Position pos, std::vector<Agent>& agents);

private:
	std::map<int, std::vector<Agent*>> sortedAgentsList;
};