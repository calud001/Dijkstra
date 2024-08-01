#include "Node.h"

void Node::expand(Node ** n, int * nrs, int nrOf, int & cap)
{
	Node** tmp = new Node*[cap + 10];
	int* tmp2 = new int[cap + 10];
	for (int i = 0; i < nrOf; i++) {
		tmp[i] = n[i];
		tmp2[i] = nrs[i];
	}
	delete[] n;
	delete[]nrs;
	nrs = tmp2;
	n = tmp;
	cap += 10;
}

Node::Node(string TOWN)
{
	this->town = TOWN;
	cost = -1;
	treated = false;
	neighbours = new Node*[500];
	lineCost = new int[500];
	amountOfNeighbours = 0;
	neighbourCap = 500;
}

Node::~Node()
{
	delete[] neighbours;
	delete[] lineCost;
}

 void Node::setCost(int value)
{
	cost = value;
}

 int Node::getCost()
{
	return cost;
}

 bool Node::isTreated()
{
	return treated;
}

 void Node::setTreated(bool hasBeenTreated)
{
	treated = hasBeenTreated;
}

 string Node::printPath()
{
	string path = "";
	if (previousNode != nullptr) {
		path = previousNode->printPath();
		path = path + "->";
	}
	
		path = path + town;

	return path;
}

 int Node::getAmountOfNeighbours()
{
	return amountOfNeighbours;
}

Node * Node::getNeighbour(int index)
{
	return neighbours[index];
}

void Node::setPreviousNeighbour(Node * n)
{
	previousNode = n;
}

int Node::getLineCostToNeighbourAtIndex(int index)
{
	return lineCost[index];
}

string Node::getTown()
{
	return this->town;
}

void Node::addNeighbour(Node * n, int value)
{
	if (amountOfNeighbours == neighbourCap) {
		expand(neighbours, lineCost, amountOfNeighbours, neighbourCap);
	}

	neighbours[amountOfNeighbours] = n;
	lineCost[amountOfNeighbours] = value;
	amountOfNeighbours++;
}
