#include <iostream>

#include "..//header//position.h"
#include "..//header//order.h"
#include "..//header//restaurant.h"
#include "..//header//agent.h"
#include "..//header//market_conditions.h"
#include "..//header//order_generator.h"

#include <chrono>

int main()
{
	Restaurant rest1(1, Position(1, 1), 5);
	Restaurant rest2(2, Position(1, 1), 5);

	MarketConditions market(2.50, 100, 2, 3);

	OrderGenerator generator(market, { rest1, rest2 });

	auto start = std::chrono::high_resolution_clock::now();

	std::vector<Order> orders = generator.GenerateOrders();

	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "generated 1,000,000 orders in " << duration.count() << " microseconds";

}
