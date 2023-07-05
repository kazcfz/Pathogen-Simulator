#pragma once
#include <iostream>
#include "EvolveTree.h"
#include "VisitorBase.h"
using namespace std;

// Necessary forward declaration
class VisitorBase;

// Pathogen base class
class Pathogen {
public:
	// Getters
	string GetName();
	int GetExpPoint();
	int GetInfectivityLevel();
	int GetLethalityLevel();

	// Setters
	void SetName(string Name);
	void SetExpPoint(int EXP);
	void SetInfectivityLevel(int InfectLVL);
	void SetLethalityLevel(int LethalLVL);

	// Read status of Pathogen (to be overriden by derived classes)
	virtual void Read();

	// Visitor accept
	virtual void VisitorAccept(VisitorBase& aVisitor);

private:
	string pName;
	int pEXP;
	int pInfectLVL;
	int pLethalLVL;
};
