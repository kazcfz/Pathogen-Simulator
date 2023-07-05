#pragma once
#include <iostream>
#include "ModeNode.h"
using namespace std;

// Singly Linked-List ModeList to manage ModeNodes
class ModeList
{
public:
	// Constructor
	ModeList();

	// SLL Methods to manage ModeNodes
	void Attach(string Name, double Infect, double Lethal);
	void DetachAll();
	ModeNode* GetMode(string Name);
	void Display();
	bool Exist(string Name);

private:
	ModeNode* MFirst;
	ModeNode* MCurrent;
	ModeNode* MTemporaryDestroyer;
};