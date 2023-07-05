#include <iostream>
#include "ModeNode.h"
using namespace std;

// Constructor for adding first node
ModeNode::ModeNode(string Name, double Infect, double Lethal)
{
	MODEName = Name;
	MODEInfect = Infect;
	MODELethal = Lethal;
	MODEPoint = nullptr;
}

// Constructor for adding nodes afterwards
ModeNode::ModeNode(string Name, double Infect, double Lethal, ModeNode* Point)
{
	MODEName = Name;
	MODEInfect = Infect;
	MODELethal = Lethal;
	MODEPoint = Point;
}

// Getters
string ModeNode::GetName() { return MODEName; }
double ModeNode::GetInfect() { return MODEInfect; }
double ModeNode::GetLethal() { return MODELethal; }
ModeNode* ModeNode::GetPoint() { return MODEPoint; }

// Setters
void ModeNode::SetPoint(ModeNode* Point) { MODEPoint = Point; return; }

// Checks if a node is empty
bool ModeNode::Empty()
{
	bool isEmpty;
	isEmpty = (this == nullptr);
	return isEmpty;
}
