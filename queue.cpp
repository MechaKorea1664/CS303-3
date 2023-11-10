#include "queue.h"
using namespace std;


template <typename T>
Queue<T>::Queue() {
	numItems = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void Queue<T>::push(T input) {
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
		Node<T>* newNode = new Node<T>;
		newNode->content = input;
		newNode->nextptr = nullptr;
		tail->nextptr = newNode;
		tail = newNode;
	}
}

template <typename T>
void Queue<T>::pop() {
	if (numItems > 1) {
		Node<T>* temp = head;
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
}

template<typename T>
T Queue<T>::front() {
	return head->content;
}

template<typename T>
bool Queue<T>::empty() {
	return (numItems == 0);
}

template<typename T>
size_t Queue<T>::size() {
	return numItems;
}