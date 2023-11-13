/*
	The Assignment 3 document can be found here:
	https://app.box.com/s/wjwvm8tp93kbop55r5wiel3otkvt6e13
*/

#include <iostream>
#include "inFixToPostFix.h"
#include "queue.h"
#include "stack.h"

using namespace std;

int main() {
	Infix_To_Postfix_Converter converter;
	string infix = "2+1*3+(15-33)";
	string result = "";
	converter.set_infix(infix);


	cout << result << endl;
	return 0;
}