#include <iostream>
#include "stack.h"

using namespace std;

string convert_infix_to_postfix(string inFixExpression, bool isInBracket, char bracket, int& i);