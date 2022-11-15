#include <iostream>

#include "..//header//position.h"
#include "..//header//order.h"
#include "..//header//restaurant.h"
#include "..//header//agent.h"
#include "..//header//market_conditions.h"
#include "..//header//order_generator.h"

int main()
{
    MarketConditions market(2.50, 5, 5.0f, 5.0f);
    Restaurant rest1(1, Position(1.0f, 1.0f), 15);
    Restaurant rest2(2, Position(1.0f, 1.0f), 15);
    Restaurant rest3(3, Position(1.0f, 1.0f), 6);
    Restaurant rest4(4, Position(1.0f, 1.0f), 2);
 
    OrderGenerator generator(market, { rest1, rest2, rest3, rest4 });

    std::vector<Order> orders = generator.GenerateOrders();
}
