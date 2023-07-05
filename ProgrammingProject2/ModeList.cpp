#include <iostream>
#include "ModeList.h"
using namespace std;

// Constructor
ModeList::ModeList()
{
	// Sets all pointers to nullptr
	MFirst = nullptr;
	MCurrent = nullptr;
	MTemporaryDestroyer = nullptr;
}

// Attaches nodes to create the SLL
void ModeList::Attach(string Name, double Infect, double Lethal)
{
	// If there are already nodes attached in the list (top pointer is a node)
	if (!MFirst->Empty())
		// Updates the top pointer to the newly attached node
		MFirst = new ModeNode(Name, Infect, Lethal, MFirst);

	// If the node being attached is the first node (top pointer not a node)
	else
		// Sets the top pointer to the first node, this one
		MFirst = new ModeNode(Name, Infect, Lethal);
}

// Detaches (destructs) all nodes in the list
void ModeList::DetachAll()
{
	MCurrent = MFirst;	//puts the moving pointer to the top
	// As long as the current pointer is a node...
	while (!MCurrent->Empty())
	{
		// Delete the node from the Head to Tail
		MTemporaryDestroyer = MCurrent;
		MCurrent = MCurrent->GetPoint();
		delete MTemporaryDestroyer;
	}
	MFirst = nullptr;	//reset top pointer to nullptr
}

// Gets the node that matches the passed name
ModeNode* ModeList::GetMode(string Name)
{
	MCurrent = MFirst;	//puts the moving pointer to the top
	// As long as the current pointer is a node...
	while (!MCurrent->Empty())
	{
		// Checks if node's name matches the passed name
		if (MCurrent->GetName() == Name) {
			return MCurrent;	//returns the node
			break;
		}
		// If name does not match
		else {
			MCurrent = MCurrent->GetPoint();	//checks the next node
		}
	}
	// If none of the nodes match the name, return nullptr
	return nullptr;
}

// Displays all nodes in the list
void ModeList::Display()
{
	MCurrent = MFirst;	//puts the moving pointer to the top
	// As long as the current pointer is a node...
	while (!MCurrent->Empty())
	{
		// Print the node's name
		cout << MCurrent->GetName() << ", ";
		// Move to next node and repeat
		MCurrent = MCurrent->GetPoint();
	}
}

// Returns the boolean if any node matches the passed name
bool ModeList::Exist(string Name)
{
	MCurrent = MFirst;	//puts the moving pointer to the top
	// As long as the current pointer is a node...
	while (!MCurrent->Empty())
	{
		// Check if the name matches
		if (MCurrent->GetName() == Name) {
			return true;
			break;
		}
		// If the name does not match
		else {
			MCurrent = MCurrent->GetPoint();	//check the next pointer
		}
	}
	// If none of the nodes matches the name, return false
	return false;
}
