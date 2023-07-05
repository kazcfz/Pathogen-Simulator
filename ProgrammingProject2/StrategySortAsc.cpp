#include <iostream>
#include "StrategySortAsc.h"
using namespace std;

// Function to sort Ascending
void StrategySortAsc::Strategy(stack<string> logResults)
{
	// Prepare descending version of Stack
	stack<string> descVersion;

	cout << "=== Start of log ===" << endl << endl;
	// Begin with the original Stack
	// As long as the original is not empty
	while (!logResults.empty())
	{
		// Push the latest log, then remove it
		descVersion.push(logResults.top());
		logResults.pop();
	}

	// As long as the Descending Stack is not empty
	while (!descVersion.empty())
	{
		// Print the latest Descending log, then remove it
		cout << descVersion.top();
		descVersion.pop();
	}
	cout << endl << "=== End of log ===" << endl << endl;
}
