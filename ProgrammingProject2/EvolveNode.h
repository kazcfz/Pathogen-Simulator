#pragma once
#include <iostream>
using namespace std;

// Mutation Nodes for EvolveTree
class EvolveNode
{
public:
	// Constructor
	EvolveNode(string Name, string Type, int Infectivity, int Lethality, int Cost, bool Bought);

	// Getters
	string GetName();
	string GetType();
	int GetInfectivity();
	int GetLethality();
	int GetCost();
	bool GetBought();

	// Setters
	void SetBought(bool Bought);

private:
	string EvolveName;
	string EvolveType;
	int EvolveInfectivity;
	int EvolveLethality;
	int EvolveCost;
	bool EvolveBought;
};
