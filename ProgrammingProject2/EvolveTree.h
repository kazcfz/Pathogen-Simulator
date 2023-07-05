#pragma once
#include <iostream>
#include "EvolveNode.h"
using namespace std;

// Necessary forward declaration
class VisitorBase;
class Pathogen;

// Tree class to handle EvolveNode mutations
class EvolveTree
{
public:
	// NIL Sentinel
	static EvolveTree NIL;

	// Constructor
	EvolveTree(EvolveNode& aEvolveNode);

	// Node Getters
	EvolveTree& LHS();
	EvolveTree& RHS();
	EvolveNode& GetEvolveNode();

	// Node Connectors
	void ConnectLHS(EvolveTree& aEvolveTree);
	void ConnectRHS(EvolveTree& aEvolveTree);

	// Node Disconnectors
	EvolveTree* DisconnectLHS();
	EvolveTree* DisconnectRHS();

	// Display the nodes
	void ReadAll(EvolveTree& aEvolveTree);
	void ReadAbsolutelyEverything(EvolveTree& aEvolveTree);

	// Find the name-matching node
	EvolveTree* Find(string Name, EvolveTree& aEvolveTree);
	EvolveTree* FindAccessible(string Name, EvolveTree& aEvolveTree);

	// Empty node checker
	bool EmptyEvolution();

	// Pathogen Getter and Setter
	Pathogen& GetPathogen();
	void SetPathogen(Pathogen& aPathogen);

	// Buy a mutation for pathogen
	void BuyEvolve(EvolveTree& aEvolveTree, string BuyEvolve);

	// Visitor accept function
	void VisitorAccept(VisitorBase& aVisitor);

private:
	EvolveNode* eNode;
	EvolveTree* eLeft;
	EvolveTree* eRight;
	Pathogen* thePathogen;

	// The default constructor
	EvolveTree():eNode((EvolveNode*)0)
	{
		eLeft = &NIL;
		eRight = &NIL;
		thePathogen = nullptr;
	}
};