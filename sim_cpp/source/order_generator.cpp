#include <iostream>
#include <algorithm>
#include <random>

#include "..//header//order_generator.h"

OrderGenerator::OrderGenerator(MarketConditions _market, std::vector<Restaurant> _restaurants) :
	market{ _market },
	restaurants{ _restaurants }
{
	InitRestaurantProbabilityList(_restaurants);
}

void OrderGenerator::InitRestaurantProbabilityList(std::vector<Restaurant> restaurants)
{
	std::default_random_engine rand(1);
	
	for (const Restaurant & rest : restaurants)
	{
		for (int i = 0 ; i < rest.orderFrequency ; i++)
		{
			restaurantProbabilityList.push_back(rest);
		}
	}
	std::shuffle(std::begin(restaurantProbabilityList), std::end(restaurantProbabilityList), rand);
}

std::vector<Order> OrderGenerator::GenerateOrders()
{
	std::vector<Order> orders;
	for (const Restaurant & rest : restaurantProbabilityList)
	{
		//todo
	}
	return orders;
}