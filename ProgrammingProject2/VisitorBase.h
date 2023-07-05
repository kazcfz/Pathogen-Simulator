#pragma once
#include <iostream>
#include "Pathogen.h"
using namespace std;

// Necessary forward declarations
class Pathogen;
class Virus;
class Bacteria;
class Fungus;
class EvolveTree;

// Visitor interface
class VisitorBase
{
public:
	virtual void Visit(Pathogen& aPathogen);
	virtual void Visit(Virus& aVirus);
	virtual void Visit(Bacteria& aBacteria);
	virtual void Visit(Fungus& aFungus);

	virtual void Visit(EvolveTree& aEvolveTree);
};
