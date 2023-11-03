#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T content;
	Node* nextptr;
};

template<typename T>
class Stack {
private:
	Node* head = nullptr;
	size_t numItems = 0;
public:
	void push(T);
	void pop();
	T top() const;
	bool empty();
	size_t size() const;
};