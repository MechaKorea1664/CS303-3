#include "inFixToPostFix.h"
using namespace std;

Infix_To_Postfix_Converter::Infix_To_Postfix_Converter() {
	isInBracket = false;
	currBracketLevel = -1;
};

string Infix_To_Postfix_Converter::convert_infix_to_postfix() {
	while (!infix_stack.empty()) {
		cout << "test" << endl;
		return "test";
	}
	cout << "test" << endl;
	return "test";
};

void Infix_To_Postfix_Converter::set_infix(string input) {
	infix = input;
	remove_spaces_from_infix();
	pack_stack();
};

void Infix_To_Postfix_Converter::print_result() {
	while (!result_stack.empty()) {
		cout << result_stack.top() << " ";
		result_stack.pop();
	}
};

void Infix_To_Postfix_Converter::remove_spaces_from_infix() {
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

bool Infix_To_Postfix_Converter::check_valid_bracket_and_update_bracket_level(char currChar) {
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

int Infix_To_Postfix_Converter::check_for_operator_level(char currChar) {
	for (int i = 0; i < 5; i++) {
		if (currChar == opList[i]) {
			if (i < 2) return 1;
			else return 2;
		}
	}
	return 0;
};

void Infix_To_Postfix_Converter::pack_stack() {
	int length = infix.length();
	while (!infix_stack.empty())

		for (int i = length - 1; i >= 0; i--) {
			infix_stack.push(infix[i]);
		}
};

string Infix_To_Postfix_Converter::combine_to_postfix(char choice) {
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