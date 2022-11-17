#pragma once
#include "agent.h"
#include "order.h"

struct OrderAssignment
{
	OrderAssignment(Agent& _agent, Order& _order) : agent{ _agent }, order{ _order } {}
	Agent& agent;
	Order& order;
};