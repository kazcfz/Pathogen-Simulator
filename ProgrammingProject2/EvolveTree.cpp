#include <iostream>
#include <iomanip>
#include "EvolveTree.h"
#include "VisitorBase.h"
using namespace std;

// Constructor
EvolveTree::EvolveTree(EvolveNode& aEvolveNode)
{
	eNode = &aEvolveNode;
	eLeft = &NIL;
	eRight = &NIL;
	thePathogen = nullptr;
}

// Node Getters
EvolveTree& EvolveTree::LHS() { return *eLeft; }
EvolveTree& EvolveTree::RHS() { return *eRight; }
EvolveNode& EvolveTree::GetEvolveNode() { return *eNode; }

// Node Connectors
void EvolveTree::ConnectLHS(EvolveTree& aEvolveTree) { eLeft = &aEvolveTree; }
void EvolveTree::ConnectRHS(EvolveTree& aEvolveTree) { eRight = &aEvolveTree; }

// Node Disconnector (Left)
EvolveTree* EvolveTree::DisconnectLHS()
{
	// Sets left node to &NIL
	EvolveTree* aEvolveTree = eLeft;
	eLeft = &NIL;
	return aEvolveTree;
}

// Node Disconnector (Right)
EvolveTree* EvolveTree::DisconnectRHS()
{
	// Sets right node to &NIL
	EvolveTree* aEvolveTree = eRight;
	eRight = &NIL;
	return aEvolveTree;
}

// Displays nodes the Pathogen is accesible to
void EvolveTree::ReadAll(EvolveTree& aEvolveTree)
{
	// Check if the node is not empty
	if (!aEvolveTree.EmptyEvolution()) {
		// Sets string if the mutation is already bought
		string evolved;
		if (aEvolveTree.GetEvolveNode().GetBought())
			evolved = " (Evolved)";

		// Prints the mutation's name, cost and bought status
		cout << left << setw(20) << aEvolveTree.GetEvolveNode().GetName() << aEvolveTree.GetEvolveNode().GetCost() << " EXP " << evolved << endl;
	}

	// If this node is already bought
	if (aEvolveTree.GetEvolveNode().GetBought()) {
		// If the left/right nodes are not empty
		// Repeat the function with the left/right nodes
		if (!aEvolveTree.LHS().EmptyEvolution())
			EvolveTree::ReadAll(aEvolveTree.LHS());
		if (!aEvolveTree.RHS().EmptyEvolution())
			EvolveTree::ReadAll(aEvolveTree.RHS());
	}
}

// Displays all the nodes in the tree
void EvolveTree::ReadAbsolutelyEverything(EvolveTree& aEvolveTree)
{
	// Check if the node is not empty
	if (!aEvolveTree.EmptyEvolution())
		// Prints the mutation's name, cost and bought status
		cout << left << setw(20) << aEvolveTree.GetEvolveNode().GetName() << aEvolveTree.GetEvolveNode().GetCost() << " EXP " << endl;

	// If the left/right nodes are not empty
	// Repeat the function with the left/right nodes
	if (!aEvolveTree.LHS().EmptyEvolution())
		EvolveTree::ReadAbsolutelyEverything(aEvolveTree.LHS());
	if (!aEvolveTree.RHS().EmptyEvolution())
		EvolveTree::ReadAbsolutelyEverything(aEvolveTree.RHS());
}

// Find the name-matching node in the entire tree
EvolveTree* EvolveTree::Find(string Name, EvolveTree& aEvolveTree)
{
	// Check if the node is not empty
	if (!aEvolveTree.EmptyEvolution()) {
		// If the mutation name matches the passed name
		if (aEvolveTree.GetEvolveNode().GetName() == Name) {
			// Return the mutation
			return &aEvolveTree;
		}
		// If name does not match
		else {
			// If the left/right nodes are not empty
			// Repeat the function with the left/right nodes
			if (!aEvolveTree.LHS().EmptyEvolution())
				EvolveTree::Find(Name, aEvolveTree.LHS());
			if (!aEvolveTree.RHS().EmptyEvolution())
				EvolveTree::Find(Name, aEvolveTree.RHS());
		}
	}
	return &NIL;
}

// Find the name-matching node within accessible tree nodes
EvolveTree* EvolveTree::FindAccessible(string Name, EvolveTree& aEvolveTree)
{
	// Check if the node is not empty
	if (!aEvolveTree.EmptyEvolution()) {
		// If the mutation name matches the passed name
		if (aEvolveTree.GetEvolveNode().GetName() == Name) {
			// Return the mutation
			return &aEvolveTree;
		}
		// If name does not match
		else {
			// If this node is bought (means children nodes are accessible)
			if (aEvolveTree.GetEvolveNode().GetBought()) {
				// If the left/right nodes are not empty
				// Repeat the function with the left/right nodes
				if (!aEvolveTree.LHS().EmptyEvolution())
					EvolveTree::FindAccessible(Name, aEvolveTree.LHS());
				if (!aEvolveTree.RHS().EmptyEvolution())
					EvolveTree::FindAccessible(Name, aEvolveTree.RHS());
			}
		}
	}
	return &NIL;
}

// Empty node checker
bool EvolveTree::EmptyEvolution()
{
	// Checks if the node is &NIL
	bool isEvolveEmpty;
	isEvolveEmpty = (this == &NIL);
	return isEvolveEmpty;
}

// Pathogen Getter and Setter
Pathogen& EvolveTree::GetPathogen() { return *thePathogen; }
void EvolveTree::SetPathogen(Pathogen& aPathogen) { thePathogen = &aPathogen; return; }


// Function for purchasing a mutation, updates the tree node and pathogen attributes
void EvolveTree::BuyEvolve(EvolveTree& aEvolveTree, string BuyEvolve)
{
	// Searches the tree for accessible nodes that match names
	if (!aEvolveTree.EmptyEvolution()) {	//check if tree node is empty
		if (BuyEvolve == aEvolveTree.GetEvolveNode().GetName()) {	//check if name matches
			if (!aEvolveTree.GetEvolveNode().GetBought()) {	//check if mutation is already bought
				if (thePathogen->GetExpPoint() >= aEvolveTree.GetEvolveNode().GetCost()) {	//check if player has enough EXP to mutate
					// Updates the mutation node and pathogen attributes
					aEvolveTree.GetEvolveNode().SetBought(true);
					thePathogen->SetExpPoint(thePathogen->GetExpPoint() - aEvolveTree.GetEvolveNode().GetCost());
					thePathogen->SetInfectivityLevel(thePathogen->GetInfectivityLevel() + aEvolveTree.GetEvolveNode().GetInfectivity());
					thePathogen->SetLethalityLevel(thePathogen->GetLethalityLevel() + aEvolveTree.GetEvolveNode().GetLethality());

					cout << thePathogen->GetName() << " has successfully mutated " << BuyEvolve << endl << endl;
					system("pause");
				}
				// If player has insufficient EXP
				else {
					cout << "Insufficient EXP!!!" << endl;
					system("pause");
				}
			}
			// If mutation is already mutated/bought
			else {
				cout << thePathogen->GetName() << " already has " << aEvolveTree.GetEvolveNode().GetName() << ". You cannot mutate it again." << endl << endl;
				system("pause");
			}
		}
		// If name does not match
		else {
			// As long as the previous mutation is bought, and left/right nodes are not empty...
			// Repeat the search with left/right nodes
			if (aEvolveTree.GetEvolveNode().GetBought()) {
				if (!aEvolveTree.LHS().EmptyEvolution())
					EvolveTree::BuyEvolve(aEvolveTree.LHS(), BuyEvolve);
				if (!aEvolveTree.RHS().EmptyEvolution())
					EvolveTree::BuyEvolve(aEvolveTree.RHS(), BuyEvolve);
			}
		}
	}
}

// Visitor accept function
void EvolveTree::VisitorAccept(VisitorBase& aVisitor) { aVisitor.Visit(*this); }


// Sentinel Node
EvolveTree EvolveTree::NIL;
