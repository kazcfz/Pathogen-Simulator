#pragma once
#include <iostream>
#include <stack>
#include "StrategyBase.h"
using namespace std;

// (Strategy) Sorting the Stack in Ascending Order
class StrategySortAsc : public StrategyBase
{
public:
	// Function to sort Ascending
	void Strategy(stack<string> logResults);
};
