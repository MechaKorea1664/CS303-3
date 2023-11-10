#include "inFixToPostFix.h"
#include <iostream>

using namespace std;


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

	int indexCurrBracketLevel = -1, indexCurrChar = -1;
	for (int i = 0; i < 6; i++) {
		if (bracketList[i] == currBracketLevel)	indexCurrBracketLevel = i;
		if (bracketList[i] == currChar)	indexCurrChar == i;
	}
	if (indexCurrBracketLevel != -1) {			// If currently in a bracket,
		if (indexCurrChar != -1) {				// If the current char being checked is within bracketList,
												// return 2 if currChar is an opening bracket and lower level than currBracketLevel.
			if (indexCurrChar < 3 && indexCurrBracketLevel < indexCurrChar) return 3; 
												// return 1 if it is a closing bracket that pairs with currBracketLevel.
			else if (indexCurrBracketLevel + 3 == indexCurrChar) return 1;
			else return 0;						// return false (0) if none of the above applies.
		}
	}
	else {										// If currently NOT in a bracket,
		if (indexCurrChar != -1) {				// If currChar is a bracket,
			if (indexCurrChar < 3) return 2;	// If it is an opening bracket, return 3.
			else return 0;						// If it is a closing bracket, return false (0).
		}										// if neither currBracketLevel or currChar is in bracketList,
		else return 4;							// return 4.
	}											// if all checks fail,
	return 4;									// return 4
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

Stack<char> pack_stack(string input) {
	Stack<char> charStack;
	int length = input.length();

	for (int i = length-1; i >= 0; i--) {
		charStack.push(input[i]);
	}

	return charStack;
}

string combine_to_postfix(string left, string right, char op) {
	string result = left + " " + right + " " + op;
	return result;
}

string combine_to_postfix(Stack<string>& numStack, Stack<char>& opStack) {
	string result = "", postFixElement = "";
	while (opStack.empty()) {
		postFixElement = numStack.top() + ' ';
		numStack.pop();
		postFixElement += numStack.top() + ' ';
		numStack.pop();
		postFixElement += opStack.top() + ' ';
		opStack.pop();
		numStack.push(postFixElement);
	}
	result = numStack.top();
	numStack.pop();
	return result;
}

string convert_infix_to_postfix(Stack<char> inFixExpression, bool isInBracket, char bracket) {
	Stack<string> numStack, postFixStack;
	Stack<char> opStack, postFixOpStack;
	string left = "", right = "", result = "", tempLeft = "", tempRight = "";

	int opLevel_Current, opLevel_Ahead;

	bool inBracket = isInBracket;
	bool isLeftComplete = false;

	char currBracket = bracket;
	char op;

	while (!inFixExpression.empty()) {
		opLevel_Current = check_for_operator_level(inFixExpression.top());
		switch (check_valid_bracket_and_update_bracket_level(currBracket, inFixExpression.top())) {
		case 0:   // invalid bracket.
			throw invalid_argument("Error: Bracket misorder and/or mismatch.");
			break;

		case 1:    // in bracket, Closing bracket / same level.
			result = combine_to_postfix(postFixStack, postFixOpStack);
			return result;
			break;

		case 2:   // NOT in bracket, opening bracket.
		case 3:   // in bracket, opening bracket / lower level.
			inBracket = true;

			if (!isLeftComplete) {
				left = convert_infix_to_postfix(inFixExpression, inBracket, inFixExpression.top());
				opLevel_Current = check_for_operator_level(inFixExpression.top());
				isLeftComplete = true;
			}
			op = inFixExpression.top();

			if (isLeftComplete) {
				right = convert_infix_to_postfix(inFixExpression, inBracket, inFixExpression.top());
				opLevel_Ahead = check_for_operator_level(inFixExpression.top());
				isLeftComplete = false;
			}

			inBracket = false;
			break;

		case 4:    // none of the above, head should be a number.
			if (!isLeftComplete) {
				left = "";
				while (opLevel_Current == 0) {
					left += inFixExpression.top();
					inFixExpression.pop();
					opLevel_Current = check_for_operator_level(inFixExpression.top());
				}
				op = inFixExpression.top();
				inFixExpression.pop();
				isLeftComplete = true;
			}
			if (isLeftComplete) {
				right = "";
				opLevel_Ahead = check_for_operator_level(inFixExpression.top());
				while (opLevel_Ahead == 0) {
					right += inFixExpression.top();
					inFixExpression.pop();
					opLevel_Ahead = check_for_operator_level(inFixExpression.top());
				}
				isLeftComplete = false;
			}
			break;
		}
		opLevel_Ahead = check_for_operator_level(inFixExpression.top());
		if (opLevel_Current > opLevel_Ahead) {
			postFixStack.push(combine_to_postfix(numStack, opStack));
			isLeftComplete = true;
		}
		else if (opLevel_Current == opLevel_Ahead) {
			numStack.push(right);
			numStack.push(left);
			opStack.push(op);
			isLeftComplete = true;
		}
		else if (opLevel_Current < opLevel_Ahead) {
			numStack.push(right);
			postFixStack.push(left);
			postFixOpStack.push(op);
			isLeftComplete = true;
		}
		result = combine_to_postfix(postFixStack, postFixOpStack);
		return result;
	}
}