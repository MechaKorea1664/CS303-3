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
	Infix_To_Postfix_Converter();

	string convert_infix_to_postfix();

	void set_infix(string input);

	void print_result();

	void remove_spaces_from_infix();

	bool check_valid_bracket_and_update_bracket_level(char currChar);

	int check_for_operator_level(char currChar);

	void pack_stack();

	string combine_to_postfix(char choice);
};
