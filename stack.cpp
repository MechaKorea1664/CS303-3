#include <iostream>
#include "stack.h"
using namespace std;

template <typename T>
void Stack<T>::push(T input) {
	Node<T>* newNode = new Node<T>;
	newNode->content = input;
	if (numItems == 0) {
		newNode->nextptr = nullptr;
		head = newNode;
	}
	else {
		newNode->nextptr = head;
		head = newNode;
	}
	numItems++;
}

template <typename T>
void Stack<T>::pop() {
	if (numItems == 0) {
		return;
	}
	else if (numItems == 1) { // might be redundant
		delete head;
		head == nullptr;
	}
	else {
		Node<T>* tempNode;
		tempNode = head;
		head = head->nextptr;
		delete tempNode;
	}
	numItems--;
}

template <typename T>
T Stack<T>::top() const {
	if (numItems == 0) {
		throw invalid_argument("Stack is empty.");
	}
	else {
		return head->content;
	}
}

template <typename T>
bool Stack<T>::empty() {
	return (numItems == 0);
}

template <typename T>
size_t Stack<T>::size() const {
	return numItems;
}