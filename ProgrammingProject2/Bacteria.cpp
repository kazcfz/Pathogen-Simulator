#include <iostream>
#include "Bacteria.h"
using namespace std;

// Constructor
Bacteria::Bacteria(string Name)
{
	// Sets unique values and Name
	SetName(Name);
	SetExpPoint(0);
	SetInfectivityLevel(3);
	SetLethalityLevel(0);
}

// Displays Bacteria's attributes
void Bacteria::Read()
{
	cout << endl << "=== BACTERIA STATS ===" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "EXP: " << GetExpPoint() << endl;
	cout << "Infectivity Level: " << GetInfectivityLevel() << endl;
	cout << "Lethality Level: " << GetLethalityLevel() << endl;
}

// Visitor accept
void Bacteria::VisitorAccept(VisitorBase& aVisitor) { aVisitor.Visit(*this); }
