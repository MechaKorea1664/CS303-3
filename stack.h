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
	Node* head = nullptr;
	int numItems = 0;
};