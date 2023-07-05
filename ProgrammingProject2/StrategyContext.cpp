#include <iostream>
#include "StrategyContext.h"
using namespace std;

// Strategy Constructor
StrategyContext::StrategyContext(StrategyBase* aStrategy)
{
	theStrategy = aStrategy;
}

// Setter
void StrategyContext::SetStrategy(StrategyBase* aStrategy) { theStrategy = aStrategy; return; }

// Sorting function by Concrete Strategy classes
void StrategyContext::SortStrategy(stack<string> logResults)
{
	this->theStrategy->Strategy(logResults);
}
