#include "..//header//simulation.h"

Simulation::Simulation(std::vector<Agent> _agents, OrderGenerator& _generator, OrderScheduler& _scheduler) :
	agents{ _agents },
	generator{ _generator },
	scheduler{ _scheduler }
{
	primaryAgent = &agents.at(0);
}

void Simulation::Tick()
{
	//TODO
}
