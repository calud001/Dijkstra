#include "Controller.h"

 bool Controller::nonTreatedNodesExist()
{
	bool nonTreatedExist = false;

	for (int i = 0; i < nrOfNodes && !nonTreatedExist; i++) {
		nonTreatedExist = !nodes[i]->isTreated();
	}

	return nonTreatedExist;
}

void Controller::expand()
{
		Node** tmp = new Node*[nodeCap + 10];
		for (int i = 0; i < nrOfNodes; i++) {
			tmp[i] = nodes[i];
		}
		delete[] nodes;
		nodes = tmp;
		nodeCap += 10;
}

Controller::Controller()
{
	nrOfNodes = 0;
	nodeCap = 10;
	nodes = new Node*[10];
}

Controller::~Controller()
{

	for (int i = 0; i < nrOfNodes; i++) {
		delete nodes[i];
	}

	delete[] nodes;
}

 void Controller::dijkstra()
{
	//*
	while (nonTreatedNodesExist()) {
		
		Node* n = pq.peek();
		pq.dequeue();
		n->setTreated(true);
		for (int i = 0; i < n->getAmountOfNeighbours(); i++) {
			if (!n->getNeighbour(i)->isTreated()) {
				int cost = n->getCost() + n->getLineCostToNeighbourAtIndex(i);
				if (cost < n->getNeighbour(i)->getCost() || n->getNeighbour(i)->getCost() == -1) {
					n->getNeighbour(i)->setCost(n->getCost() + n->getLineCostToNeighbourAtIndex(i));
					n->getNeighbour(i)->setPreviousNeighbour(n);
				}
				pq.enqueue(n->getNeighbour(i));
			}
		}
	}	
	//*/

}

 void Controller::insert(string town)
{
	if (nrOfNodes == nodeCap) {
		expand();
	}
	nodes[nrOfNodes] = new Node(town);
	nrOfNodes++;
}

 void Controller::insertLink(string town1, string town2, int Cost)
{
	bool found = false;
	for (int i = 0; i < nrOfNodes && !found; i++) {
		if (nodes[i]->getTown() == town1) {
			found = true;
			bool foundOther = false;
			for (int j = 0; j < nrOfNodes && !foundOther; j++) {//get neighbour pointer
				if (nodes[j]->getTown() == town2) {
					foundOther = true;
					nodes[i]->addNeighbour(nodes[j], Cost);
				}
			}
		}
	}
}

 void Controller::findPath(string startNode, string end)
{
	bool found = false;
	for (int i = 0; i < nrOfNodes && !found; i++) {
		if (nodes[i]->getTown() == startNode) {
			found = true;
			nodes[i]->setCost(0);
			pq.enqueue(nodes[i]);
		}
	}

	if (found == false) {
		cout << "error, could not find town to start from" << endl;
		return;
	}
		
	
	dijkstra();

	found = false;
	for (int i = 0; i < nrOfNodes && !found; i++) {
		if (nodes[i]->getTown() == end) {
			found = true;
			
			ofstream out("Answer.txt", ofstream::out);
			out << "0" << endl;
			out << nodes[i]->getCost() << endl;
			out << nodes[i]->printPath() <<endl;
		}
	}

	if (found == false)
		cout << "error, could not find town to end at" << endl;
	
	return;
}
