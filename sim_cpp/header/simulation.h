#pragma once
#include "order_generator.h"
#include "order_scheduler.h"
#include "stale_order_pruner.h"
#include "agent.h"

class Simulation
{
public:
	Simulation(std::vector<Agent> agents, OrderGenerator& generator, OrderScheduler& scheduler, StaleOrderPruner& _orderPruner);
	void Tick();

private:
	OrderGenerator generator;
	OrderScheduler scheduler;
	StaleOrderPruner orderPruner;

	std::vector<Agent> agents;
	Agent* primaryAgent;

	std::vector<Order> orderQueue;
};