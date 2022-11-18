#pragma once
#include <map>

#include "..//header//order_scheduler.h"


std::vector<Order*> OrderScheduler::AssignOrders(std::vector<Order*> orders, std::vector<Agent>& agents)
{
	std::vector<Order*> unassignedOrders;
	unassignedOrders.reserve(unassignedOrders.size());
	for (auto order = orders.begin(); order != orders.end();)
	{
		bool orderWasAssigned = false;
		std::vector<Agent*> sortedAgents = GetSortedAgentsList((*order)->pos, agents);
		for (Agent* agent : sortedAgents)
		{
			if (!agent->IsOnOrder() && agent->OrderMeetsThresholds(*order))
			{
				agent->AcceptOrder((*order));
				orderWasAssigned = true;
				break;
			}
		}
		if (orderWasAssigned)
		{
			order = orders.erase(order);
		}
		else
		{
			unassignedOrders.push_back((*order));
			order++;
		}
	}
	return unassignedOrders;
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