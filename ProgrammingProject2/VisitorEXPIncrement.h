#pragma once
#include <iostream>
#include "VisitorBase.h"
#include "Pathogen.h"
using namespace std;

// Visit function for increasing pathogen EXP by 1
class VisitorEXPIncrement : public VisitorBase
{
	virtual void Visit(Pathogen& aPathogen);
	virtual void Visit(Virus& aVirus);
	virtual void Visit(Bacteria& aBacteria);
	virtual void Visit(Fungus& aFungus);
};
