#include "..//header//order_generator.h"
#include <iostream>

OrderGenerator::OrderGenerator(MarketConditions _market, std::vector<Restaurant> _restaurants) :
	market{ _market },
	restaurants{ _restaurants }
{
	InitRestaurantProbabilityList(_restaurants);
	GenerateOrders();
}

void OrderGenerator::InitRestaurantProbabilityList(std::vector<Restaurant> restaurants)
{
	for (const Restaurant & rest : restaurants)
	{
		for (int i = 0 ; i < rest.orderFrequency ; i++)
		{
			restaurantProbabilityList.push_back(rest);
		}
	}
}

std::vector<Order> OrderGenerator::GenerateOrders()
{
	std::vector<Order> orders;
	for (int i = 0; i < market.ordersPerTick; ++i)
	{
		//todo
	}
	return orders;
}