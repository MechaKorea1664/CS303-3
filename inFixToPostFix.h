#include <iostream>
#include "stack.h"

using namespace std;

string convert_infix_to_postfix(Stack<char> inFixExpression, bool isInBracket, char bracket);

void remove_spaces_from_string(string& inFixExpression);

int check_valid_bracket_and_update_bracket_level(char currBracketLevel, char currChar);

int check_for_operator_level(char currChar);

Stack<char> pack_stack(string input);

string combine_to_postfix(string left, string right, char op);

string combine_to_postfix(Stack<string>& numStack, Stack<char>& opStack);