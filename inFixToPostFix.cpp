#include "inFixToPostFix.h"
#include <iostream>

using namespace std;

string convert_infix_to_postfix(string inFixExpression, bool isInBracket, char bracket, int& i) {
	Stack<string> numStack, opStack;
	string left = "", right = "", op = "", op2 = "", result = "";

	bool inBracket = isInBracket;
	bool isLeftComplete = false;

	char opList[5] = { '+','-','*','/','%' };
	char currBracket = bracket;

	int length_inFixExpression = inFixExpression.length();

	for (; i < length_inFixExpression; i++) {
		switch (check_valid_bracket_and_update_bracket_level(currBracket, inFixExpression[i])) {
		case 0: {
			throw invalid_argument("Error: Bracket misorder and/or mismatch.");
			break;
		}
		case 1: {
			i++;
			return result;
			break; // just in case, might remove later.
		}
		case 2: {
			i++;
			if (left == "") left = convert_infix_to_postfix(inFixExpression, inBracket, i);
			else if (right == "") right = convert_infix_to_postfix(inFixExpression, inBracket, i);
		}
		case 3: {
			currBracket = inFixExpression[i];
		}
		}
	}
}

void remove_spaces_from_string(string& inFixExpression) {
	int length = inFixExpression.length();
	string result = "";
	for (int i = 0; i < length; i++) {
		if (inFixExpression[i] == ' ') {
			continue;
		}
		result += inFixExpression[i];
	}
	inFixExpression = result;
}

int check_valid_bracket_and_update_bracket_level(char currBracketLevel, char currChar) {
	char bracketList[6] = { '{','[','(','}',']',')' };

	int indexCurrBracketLevel = -1, int indexCurrChar = -1;
	for (int i = 0; i < 6; i++) {
		if (bracketList[i] == currBracketLevel)	indexCurrBracketLevel = i;
		if (bracketList[i] == currChar)	indexCurrChar == i;
	}
	if (indexCurrBracketLevel != -1) { // If currently in a bracket,
		if (indexCurrChar != -1) { // If the current char being checked is within bracketList,
			// return 2 if currChar is an opening bracket and lower level than currBracketLevel.
			if (indexCurrChar < 3 && indexCurrBracketLevel < indexCurrChar) return 2; 
			// return 1 if it is a closing bracket that pairs with currBracketLevel.
			else if (indexCurrBracketLevel + 3 == indexCurrChar) return 1;
			else return 0; // return false (0) if none of the above applies.
		}
	}
	else { // If currently NOT in a bracket,
		if (indexCurrChar != -1) { // If currChar is a bracket,
			if (indexCurrChar < 3) return 3; // If it is an opening bracket, return 3.
			else return 0; // If it is a closing bracket, return false (0).
		}
		else return 4; // if neither currBracketLevel or currChar is in bracketList, return 3.
	}
}

int check_for_operator_level (char currChar) {
	char opList[5] = { '+','-','*','/','%' };
	for (int i = 0; i < 5; i++) {
		if (currChar == opList[i]) {
			if (i < 2) return 1;
			else return 2;
		}
	}
	return 0;
}

string unpack_stack(Stack<string> numStack, Stack<string> opStack) {
	string result = "";
	return result;
}