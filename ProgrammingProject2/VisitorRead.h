#pragma once
#include <iostream>
#include "VisitorBase.h"
#include "Pathogen.h"
using namespace std;

// Visit function for displaying pathogen stats
class VisitorRead : public VisitorBase
{
public:
	virtual void Visit(Pathogen& aPathogen);
	virtual void Visit(Virus& aVirus);
	virtual void Visit(Bacteria& aBacteria);
	virtual void Visit(Fungus& aFungus);
};
