#include <iostream>

#include "..//header//position.h"
#include "..//header//order.h"
#include "..//header//restaurant.h"
#include "..//header//agent.h"
#include "..//header//market_conditions.h"
#include "..//header//restaurant.h"
#include "..//header//simulation.h"

#include <chrono>

int main()
{
	std::vector<Agent> agents
	{
		Agent(2.5f, 1.0f, 10.0f, Position(1.0f, 1.0f)),
		Agent(5.0f, 1.0f, 10.0f, Position(1.0f, 1.3f)),
		Agent(6.0f, 1.25f, 10.0f, Position(1.1f, 1.0f)),
		Agent(2.5f, 1.25f, 10.0f, Position(1.0f, 1.2f)),
	};

	std::vector<Restaurant> restaurants
	{
		Restaurant(1, Position(1.0f, 1.0f), 5),
		Restaurant(2, Position(1.0f, 1.0f), 5),
	};

	MarketConditions market(2.5f, 5, 1.0f, 2.0f);
	StaleOrderPruner pruner(5);
	OrderScheduler scheduler;
	OrderGenerator generator(market, restaurants);

	Simulation sim(agents, generator, scheduler, pruner);

	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i <= 1; ++i)
	{
		sim.Tick();
	}

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << duration.count();
}
