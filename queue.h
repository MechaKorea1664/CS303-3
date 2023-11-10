#pragma once

template <typename T>
struct Node {
	T content;
	Node<T>* nextptr;
};

template <typename T>
class Queue {
private: 
	size_t numItems;
	Node<T>* head;
	Node<T>* tail;
public:
	Queue();
	void push(T);	//Inserts a new element at the rear of the queue.
	void pop(); 	//Removes the front element of the queueand returns it.
	T front();		//Returns the front element present in the queue without removing it.
	bool empty();	//Checks if the queue is empty
	size_t size();	//Returns the total number of elements present in the queue
};