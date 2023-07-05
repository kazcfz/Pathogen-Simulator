#include <iostream>
#include "StrategySortDesc.h"
using namespace std;

// Function to sort Descending
void StrategySortDesc::Strategy(stack<string> logResults)
{
	cout << "=== Start of log ===" << endl << endl;
	// As long as the Stack is not empty
	while (!logResults.empty())
	{
		// Print the latest log, then remove it
		cout << logResults.top();
		logResults.pop();
	}
	cout << endl << "=== End of log ===" << endl << endl;
}
