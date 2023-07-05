#pragma once
#include <iostream>
#include <stack>
#include "StrategyBase.h"
using namespace std;

// The context class for Strategy
class StrategyContext
{
public:
	// Strategy Constructor
	StrategyContext(StrategyBase* aStrategy);

	// Setter
	void SetStrategy(StrategyBase* aStrategy);

	// Sorting function by Concrete Strategy classes
	void SortStrategy(stack<string> logResults);

private:
	StrategyBase* theStrategy;
};
