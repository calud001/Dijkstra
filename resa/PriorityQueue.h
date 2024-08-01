#pragma once

#include <cstdlib>
#include <utility>
#include <stdexcept>

#include "Node.h"

const int INCREMENT_SIZE_BY = 50;


class PriorityQueue{


	private:

		Node** listptr;

		int capacity;
		int nrOf;
		int indexTracker;

		

		void expand();

	public:

		PriorityQueue();
		~PriorityQueue();

		void enqueue(Node* element);
		void dequeue();
		Node* peek() const;
		int size() const;
		bool isEmpty() const;

};