#pragma once
#include <map>

#include "..//header//order_scheduler.h"


std::vector<OrderAssignment> OrderScheduler::AssignOrders(std::vector<Order>& orders, std::vector<Agent>& agents)
{
	// TODO
}

std::vector<Agent*> OrderScheduler::GetSortedAgentsList(Position pos, std::vector<Agent>& agents)
{
	std::vector<Agent*> sortedAgents;
	std::map<float, Agent*> distanceOfAgents;

	for (Agent& agent : agents)
	{
		float distance = Position::dist(agent.Pos(), pos);
		distanceOfAgents.insert({ distance, &agent });
	}

	for (auto& agent : distanceOfAgents)
	{
		sortedAgents.push_back(agent.second);
	}
	return sortedAgents;
}