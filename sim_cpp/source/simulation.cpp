#include "..//header//simulation.h"

Simulation::Simulation(std::vector<Agent> _agents, OrderGenerator& _generator, OrderScheduler& _scheduler, StaleOrderPruner& _orderPruner) :
	agents{ _agents },
	generator{ _generator },
	scheduler{ _scheduler },
	orderPruner { _orderPruner}
{
	primaryAgent = &agents.at(0);
}

void Simulation::Tick()
{
	orderQueue = orderPruner.Prune(orderQueue);

	for (Order* order : orderQueue)
	{
		order->ticksInQueue++;
	}

	for (Agent& agent : agents)
	{
		agent.Tick();
	}

	std::vector<Order*> newOrders;
	newOrders = generator.GenerateOrders();
	orderQueue.insert(orderQueue.end(), newOrders.begin(), newOrders.end());
	
	orderQueue = scheduler.AssignOrders(orderQueue, agents);
}
