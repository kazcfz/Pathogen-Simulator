#pragma once
#include <iostream>
#include <stack>
#include "StrategyBase.h"
using namespace std;


// (Strategy) Sortint Stack in Descending order
class StrategySortDesc : public StrategyBase
{
public:
	// Function to sort Descending
	void Strategy(stack<string> logResults);
};
