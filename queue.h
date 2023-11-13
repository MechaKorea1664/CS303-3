#pragma once
using namespace std;

template <typename TPLT>
struct QueueNode {
	TPLT content;
	QueueNode* nextptr;
};

template <typename TPLT>
class Queue {
private: 
	size_t numItems;
	QueueNode<TPLT>* head;
	QueueNode<TPLT>* tail;
public:
	Queue() {
		numItems = 0;
		head = nullptr;
		tail = nullptr;
	};

	void push(TPLT) {	//Inserts a new element at the rear of the queue.
		if (numItems == 0) {
			head->content = input;
			head->nextptr = nullptr;
			tail = head;
			numItems++;
		}
		else if (numItems == 1) {
			tail->content = input;
			tail->nextptr = nullptr;
			head->nextptr = tail;
			numItems++;
		}
		else {
			QueueNode<TPLT>* newNode = new QueueNode<TPLT>;
			newNode->content = input;
			newNode->nextptr = nullptr;
			tail->nextptr = newNode;
			tail = newNode;
		}
	};
	void pop() {	//Removes the front element of the queueand returns it.
		if (numItems > 1) {
			QueueNode<TPLT>* temp = head;
			head = head->nextptr;
			tail = nullptr;
			delete temp;
			numItems--;
		}
		else if (numItems == 1) {
			delete head;
			head = nullptr;
			numItems--;
		}
	};

	TPLT front() {	//Returns the front element present in the queue without removing it.
		return head->content;
	};

	bool empty() {	//Checks if the queue is empty
		return (numItems == 0);
	};	
	size_t size() {	//Returns the total number of elements present in the queue
		return numItems;
	};
};