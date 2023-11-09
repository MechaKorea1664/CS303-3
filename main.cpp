/*
	The Assignment 3 document can be found here:
	https://app.box.com/s/wjwvm8tp93kbop55r5wiel3otkvt6e13
*/

#include <iostream>
#include "inFixToPostFix.cpp"


int main() {
	string infix = "2+1*3+(15-33)";
	Stack<char> urNameHere= pack_stack(infix);
	convert_infix_to_postfix(urNameHere, false, 'l');
	return 0;
}