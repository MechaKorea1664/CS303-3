#include <iostream>
#include "stack.h"

using namespace std;

class Infix_To_Postfix_Converter {
private:
	string infix;
	Stack<string> left_stack;
	Stack<string> right_stack;
	Stack<char> infix_stack;
	Stack<char> op_stack;
	Stack<char> result_op_stack;
	Stack<string> result_stack;
	
	bool isInBracket;

	int currBracketLevel;

	char bracketList[6] = { '{','[','(','}',']',')' };
	char opList[5] = { '+','-','*','/','%' };

public:
	Infix_To_Postfix_Converter() {
		isInBracket = false;
		currBracketLevel = -1;
	};

	string convert_infix_to_postfix() {
		while (!infix_stack.empty()) {
			return "test";
		}
		return "test";
	};

	void set_infix(string input) {
		infix = input;
		remove_spaces_from_infix();
		pack_stack();
	};

	void print_result() {
		while (!result_stack.empty()) {
			cout << result_stack.top() << " ";
			result_stack.pop();
		}
	};

	void remove_spaces_from_infix() {
		int length = infix.length();
		string result = "";
		for (int i = 0; i < length; i++) {
			if (infix[i] == ' ') {
				continue;
			}
			result += infix[i];
		}
		infix = result;
	};

	bool check_valid_bracket_and_update_bracket_level(char currChar) {
		int currBracketIndex = -1;
		for (int i = 0; i < 6; i++) {
			if (bracketList[i] == currChar) {
				currBracketIndex = i;
			}
		}
		if (currBracketIndex == -1) {
			return false;
		}
		else if (currBracketLevel < currBracketIndex && currBracketIndex < 3) { // Opening bracket and lower level of bracket.
			currBracketLevel = currBracketIndex;
			return true;
		}
		else if (currBracketLevel + 3 == currBracketIndex) { // Closing bracket that matches with opening bracket.
			currBracketLevel--;
			return false;
		}
		else {
			throw invalid_argument("Error: Brackets do not match.");
		}
	};

	int check_for_operator_level(char currChar) {
		for (int i = 0; i < 5; i++) {
			if (currChar == opList[i]) {
				if (i < 2) return 1;
				else return 2;
			}
		}
		return 0;
	};

	void pack_stack() {
		int length = infix.length();
		while (!infix_stack.empty())

			for (int i = length - 1; i >= 0; i--) {
				infix_stack.push(infix[i]);
			}
	};

	string combine_to_postfix(char choice) {
		string result = "";
		switch (choice) {
		case 'l': {
			while (!op_stack.empty()) {
				result += left_stack.top();
				left_stack.pop();
				result = left_stack.top() + result;
				left_stack.pop();
				result += op_stack.top();
				op_stack.pop();
			}
			break;
		}
		case 'r': {
			while (!op_stack.empty()) {
				result += right_stack.top();
				right_stack.pop();
				result = right_stack.top() + result;
				right_stack.pop();
				result += op_stack.top();
				op_stack.pop();
			}
			break;
		}
		case 'b': {
			while (!result_op_stack.empty()) {
				result += result_stack.top();
				result_stack.pop();
				result = result_stack.top() + result;
				result_stack.pop();
				result += result_op_stack.top();
				result_op_stack.pop();
			}
			break;
		}
		}
		return result;
	};
};