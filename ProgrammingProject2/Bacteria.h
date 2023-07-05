#pragma once
#include <iostream>
#include "Pathogen.h"
using namespace std;

// Neccessary forward declaration
class VisitorBase;

// Derived Bacteria class
class Bacteria : public Pathogen
{
public:
	// Constructor
	Bacteria(string Name);

	// Displays Bacteria's attributes
	virtual void Read();

	// Visitor accept
	void VisitorAccept(VisitorBase& aVisitor);

private:
};