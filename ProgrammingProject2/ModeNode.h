#pragma once
#include <iostream>
using namespace std;

// Node class for Game Modes
class ModeNode
{
public:
	// Constructor
	ModeNode(string Name, double Infect, double Lethal);
	ModeNode(string Name, double Infect, double Lethal, ModeNode* Point);

	// Getters
	string GetName();
	double GetInfect();
	double GetLethal();
	ModeNode* GetPoint();

	// Setters
	void SetPoint(ModeNode* Point);

	// Checks if a node is empty
	bool Empty();

private:
	string MODEName;
	double MODEInfect;
	double MODELethal;
	ModeNode* MODEPoint;
};
