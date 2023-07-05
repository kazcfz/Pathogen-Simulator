#include <iostream>
#include "Pathogen.h"
using namespace std;

// Getters
string Pathogen::GetName() { return pName; }
int Pathogen::GetExpPoint() { return pEXP; }
int Pathogen::GetInfectivityLevel() { return pInfectLVL; }
int Pathogen::GetLethalityLevel() { return pLethalLVL; }

// Setters
void Pathogen::SetName(string Name) { pName = Name; return; }
void Pathogen::SetExpPoint(int EXP) { pEXP = EXP; return; }
void Pathogen::SetInfectivityLevel(int InfectLVL) { pInfectLVL = InfectLVL; return; }
void Pathogen::SetLethalityLevel(int LethalLVL) { pLethalLVL = LethalLVL; return; }

// Displays all of pathogen's stats (to be overriden by derived classes)
void Pathogen::Read()
{
	cout << endl << "=== PATHOGEN STATS ===" << endl;
	cout << "Name: " << pName << endl;
	cout << "EXP: " << pEXP << endl;
	cout << "Infectivity Level: " << pInfectLVL << endl;
	cout << "Lethality Level: " << pLethalLVL << endl;
}

// Visitor accept
void Pathogen::VisitorAccept(VisitorBase& aVisitor) { aVisitor.Visit(*this); }
