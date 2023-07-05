#pragma once
#include <iostream>
#include <stack>
using namespace std;

// Strategy Interface
class StrategyBase
{
public:
	virtual void Strategy(stack<string> logResults);
};
