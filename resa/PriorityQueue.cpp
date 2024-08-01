#include "PriorityQueue.h"

void PriorityQueue::expand()
{
	Node** tmp = new Node*[capacity + INCREMENT_SIZE_BY];

	for (int i = 0; i < nrOf; i++) {
		tmp[i] = listptr[i];
	}

	capacity += INCREMENT_SIZE_BY;

	delete[] listptr;

	listptr = tmp;

}


PriorityQueue::PriorityQueue()
	:indexTracker(0), nrOf(0), capacity(10)
{
	listptr = new Node*[capacity];
}


PriorityQueue::~PriorityQueue()
{


}

void PriorityQueue::enqueue(Node* element)
{
	if (nrOf + 1 == capacity) {
		expand();
	}

	listptr[nrOf] = element;

	nrOf++;

}


void PriorityQueue::dequeue()
{

	if (nrOf > 0) {

		int lowIndex = 0;

		for (int i = 1; i < nrOf; i++) {
			if (listptr[i]->getCost() < listptr[lowIndex]->getCost()) {
				lowIndex = i;
			}
		}

		listptr[lowIndex] = listptr[nrOf - 1];
		nrOf--;


	}
	else {

		throw std::exception("No items in queue");

	}

}

Node* PriorityQueue::peek() const
{


	if (nrOf > 0) {

		int lowIndex = 0;

		for (int i = 1; i < nrOf; i++) {

			if (listptr[i]->getCost() < listptr[lowIndex]->getCost()) {
				lowIndex = i;
			}
		}

		return listptr[lowIndex];

	}


	throw std::exception("No items in queue");

}


int PriorityQueue::size() const
{
	return nrOf;
}

bool PriorityQueue::isEmpty() const
{
	return (nrOf == 0);
}


