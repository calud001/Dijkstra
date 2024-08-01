#pragma once
#include <fstream>
#include "Node.h"
#include "PriorityQueue.h"

class Controller {

private:
	
	bool nonTreatedNodesExist();
	void dijkstra();

	Node** nodes;
	int nrOfNodes;
	int nodeCap;

	PriorityQueue pq;

	void expand();

public:
	Controller();
	~Controller();
	void insert(string town);
	void insertLink(string town1, string town2, int Cost);

	void findPath(string startNode, string end);

};