#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T content;
	Node* nextptr;
};

template <typename T>
class Stack {
private:
	Node<T>* head = nullptr;
	size_t numItems = 0;
public:
	void push(T input) {
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

	void pop() {
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
	};

	T top() const {
		if (numItems == 0) {
			throw invalid_argument("Stack is empty.");
		}
		else {
			return head->content;
		}
	};

	bool empty() {
		return (numItems == 0);
	};

	size_t size() const {
		return numItems;
	};
};