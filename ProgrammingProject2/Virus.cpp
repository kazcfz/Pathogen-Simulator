#include <iostream>
#include "Virus.h"
using namespace std;

// Constructor
Virus::Virus(string Name)
{
	// Sets unique values and Name
	SetName(Name);
	SetExpPoint(0);
	SetInfectivityLevel(2);
	SetLethalityLevel(0);
}

// Displays Virus' attributes
void Virus::Read()
{
	cout << endl << "=== VIRUS STATS ===" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "EXP: " << GetExpPoint() << endl;
	cout << "Infectivity Level: " << GetInfectivityLevel() << endl;
	cout << "Lethality Level: " << GetLethalityLevel() << endl;
}

// Visitor accept
void Virus::VisitorAccept(VisitorBase& aVisitor) { aVisitor.Visit(*this); }
