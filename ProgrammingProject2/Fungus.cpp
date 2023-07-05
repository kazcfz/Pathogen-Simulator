#include <iostream>
#include "Fungus.h"
using namespace std;

// Constructor
Fungus::Fungus(string Name)
{
	// Sets unique values and Name
	SetName(Name);
	SetExpPoint(0);
	SetInfectivityLevel(1);
	SetLethalityLevel(0);
}

// Displays Fungus' attributes
void Fungus::Read()
{
	cout << endl << "=== FUNGUS STATS ===" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "EXP: " << GetExpPoint() << endl;
	cout << "Infectivity Level: " << GetInfectivityLevel() << endl;
	cout << "Lethality Level: " << GetLethalityLevel() << endl;
}

// Visitor accept
void Fungus::VisitorAccept(VisitorBase& aVisitor) { aVisitor.Visit(*this); }
