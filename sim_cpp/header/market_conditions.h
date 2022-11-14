#pragma once
struct MarketConditions
{
	MarketConditions(float _basePay, int _ordersPerTick, float _payScaleValue, float _mileScaleValue) :
		basePay{ _basePay },
		ordersPerTick{ _ordersPerTick },
		payScaleValue{ _payScaleValue },
		mileScaleValue{ _mileScaleValue } {}


	float basePay;
	int ordersPerTick;
	float payScaleValue;
	float mileScaleValue;
};