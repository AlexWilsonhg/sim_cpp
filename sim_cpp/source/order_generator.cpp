#include "..//header//order_generator.h"

OrderGenerator::OrderGenerator(MarketConditions _market, std::vector<Restaurant> _restaurants) :
	market{ _market },
	restaurants{ _restaurants },
	rand{ std::default_random_engine(1)},
	dist{ std::normal_distribution<float>(2, 1) }
{
	InitRestaurantProbabilityList(_restaurants);
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
	std::shuffle(std::begin(restaurantProbabilityList), std::end(restaurantProbabilityList), rand);
}

std::vector<Order*> OrderGenerator::GenerateOrders()
{
	std::vector<Order*> orders;
	orders.reserve(market.ordersPerTick);
	for(int i = 0; i < market.ordersPerTick; i++)
	{	
		Restaurant& rest = restaurantProbabilityList[currentRestaurantIndex % restaurantProbabilityList.size()];
		currentRestaurantIndex++;

		Position pos = rest.pos;
		int ID = rest.ID;

		// temporary formulas 
		float pay = market.basePay + dist(rand) * market.payScaleValue;
		float miles = dist(rand) * market.mileScaleValue;
		int ticks = 3;

		orders.push_back(new Order(ID, pos, pay, miles, ticks));
	}
	return orders;
}