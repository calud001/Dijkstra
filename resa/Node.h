#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node {

private:
	
	string town;
	Node* previousNode;
	int cost;
	bool treated;

	Node** neighbours;
	int* lineCost;
	int amountOfNeighbours;
	int neighbourCap;
	
	void expand(Node** n, int* nrs, int nrOf, int &cap);

public:
	Node(string TOWN);
	~Node();
	void setCost(int value);
	int getCost();
	bool isTreated();
	void setTreated(bool hasBeenTreated);
	string printPath();
	int getAmountOfNeighbours();
	Node* getNeighbour(int index);
	void setPreviousNeighbour(Node* n);
	int getLineCostToNeighbourAtIndex(int index);
	string getTown();
	void addNeighbour(Node* n, int value);
};