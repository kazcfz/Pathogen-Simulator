#pragma once
#include <iostream>
#include "Pathogen.h"
using namespace std;

// Neccessary forward declaration
class VisitorBase;

// Derived Fungus class
class Fungus : public Pathogen
{
public:
	// Constructor
	Fungus(string Name);

	// Displays Fungus' attributes
	virtual void Read();

	// Visitor accept
	void VisitorAccept(VisitorBase& aVisitor);

private:
};