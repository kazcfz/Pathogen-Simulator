#pragma once
#include <iostream>
#include "Pathogen.h"
using namespace std;

// Neccessary forward declaration
class VisitorBase;

// Derived Virus class
class Virus : public Pathogen
{
public:
	// Constructor
	Virus(string Name);

	// Displays Virus' attributes
	virtual void Read();

	// Visitor accept
	void VisitorAccept(VisitorBase& aVisitor);

private:
};
