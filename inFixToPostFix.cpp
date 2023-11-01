#include <stack>
#include <iostream>

using namespace std;

string appendToStack(stack<string> numStack, stack<string> opStack, string inFixExpression, bool &isInvalidBracket) {
	bool isInBracket = true; // Considers the entire expression to be within a bracket.
	bool invalidBracket = false;
	string a, b, op;
	char currBracket; 
	int length_inFixExpression = inFixExpression.length();

	for (int i = 0; i < length_inFixExpression; i++) {
		switch (inFixExpression[i]) {
		case '{':
			if (currBracket == '[' || currBracket == '(') invalidBracket = true;
			currBracket = '{';
			break;
		case '[':
			if (currBracket == '(') invalidBracket = true;
			currBracket = '[';
			break;
		case '(':
			if (currBracket == '(') invalidBracket = true;
			currBracket = '(';
			break;
		default:
			break;
		}
		if (invalidBracket == true) {
			cout << "invalid input dumbass check again" << endl;
			return 0;
			break; // just in case hahahaha
		}
	}

}

void removeSpaces(string& inFixExpression) {
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

bool checkBracket(char currBracket, char currChar) {
	if		(currBracket == '(' && currChar != ')') return false;
	else if (currBracket == '[' && currChar != ']') return false;
	else if (currBracket == '{' && currChar != '}') return false;
	else											return true;
}