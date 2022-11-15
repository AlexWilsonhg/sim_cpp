#pragma once
#include "order_generator.h"
#include "agent.h"

class OrderScheduler {};

class Simulation
{
public:
	Simulation(std::vector<Agent> agents, OrderGenerator& generator, OrderScheduler& scheduler);
	void Tick();

private:
	OrderGenerator generator;
	OrderScheduler scheduler;

	std::vector<Agent> agents;
	Agent* primaryAgent;
};