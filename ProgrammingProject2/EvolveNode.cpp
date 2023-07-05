#include <iostream>
#include <string>
#include "EvolveNode.h"
using namespace std;

// Constructor
EvolveNode::EvolveNode(string Name, string Type, int Infectivity, int Lethality, int Cost, bool Bought)
{
	EvolveName = Name;
	EvolveType = Type;
	EvolveInfectivity = Infectivity;
	EvolveLethality = Lethality;
	EvolveCost = Cost;
	EvolveBought = Bought;
}

// Getters
string EvolveNode::GetName() { return EvolveName; }
string EvolveNode::GetType() { return EvolveType; }
int EvolveNode::GetInfectivity() { return EvolveInfectivity; }
int EvolveNode::GetLethality() { return EvolveLethality; }
int EvolveNode::GetCost() { return EvolveCost; }
bool EvolveNode::GetBought() { return EvolveBought; }

// Setters
void EvolveNode::SetBought(bool Bought) { EvolveBought = Bought; return; }
