#pragma once

#include "..//header//order_scheduler.h"


void OrderScheduler::AssignOrders(std::vector<Order>& orders, std::vector<Agent>& agents)
{
	std::vector<Agent*> sortedAgents;
	for (auto order = orders.begin(); order != orders.end();)
	{
		bool orderWasAssigned = false;
		// if we've already computed the sorted list of agent distances
		if (sortedAgentsList.count(order->restaurantID))
		{
			sortedAgents = GetSortedAgentsList(order->restaurantID);
		}

		else
		{
			BuildSortedAgentsList(order->restaurantID, order->pos, agents);
			sortedAgents = GetSortedAgentsList(order->restaurantID);
		}
		
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
			order++;
		}
	}
}

std::vector<Agent*> OrderScheduler::GetSortedAgentsList(int restaurantID)
{
	return sortedAgentsList[restaurantID];
}

void OrderScheduler::BuildSortedAgentsList(int restaurantID, Position pos, std::vector<Agent>& agents)
{
	std::map<float, Agent*> distanceOfAgents;

	for (Agent& agent : agents)
	{
		float distance = Position::dist(agent.Pos(), pos);
		distanceOfAgents.insert({ distance, &agent });
	}

	std::vector<Agent*> sortedAgents;

	for (auto agent : distanceOfAgents)
	{
		sortedAgents.push_back(agent.second);
	}

	sortedAgentsList.insert({ restaurantID, sortedAgents });
}