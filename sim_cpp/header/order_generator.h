#pragma once
#include <vector>

#include "market_conditions.h"
#include "restaurant.h"
#include "order.h"

class OrderGenerator
{
public:
	OrderGenerator(MarketConditions _market, std::vector<Restaurant> _restaurants);
	std::vector<Order> GenerateOrders();

private:
	void InitRestaurantProbabilityList(std::vector<Restaurant> restaurants);

private:
	MarketConditions market;
	std::vector<Restaurant> restaurants;
	std::vector<Restaurant> restaurantProbabilityList;
	
	int currentRestaurantIndex{ 0 };

};