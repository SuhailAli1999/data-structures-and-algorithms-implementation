#include <iostream>
#include<stack>
#include <string>
using namespace std;

int priority(char c) {
	if (c == '-' || c == '+') {
		return 1;
	}
	else if (c == '*' || c == '/') {
		return 2;
	}
	else if (c == '^') {
		return 3;
	}
	else {
		return 0;
	}
}

int main() {

	stack<char> stack;
	string input = "A*B+(C-D/E)";
	string output = "";

	for (int i = 0; i < input.size(); i++) {
		
		if (isalpha(input[i]) || isdigit(input[i])) {
			output += input[i];
		}
		else if (input[i] == '('){
			stack.push(input[i]);
		}
		else if (input[i] == ')') {
			while (stack.top() != '(') {
				output += stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else {

				while (!stack.empty() && priority(input[i]) <= priority(stack.top())) {
					output += stack.top();
					stack.pop();
				}

				stack.push(input[i]);
			
		}
	}

	while (!stack.empty()) {
		output += stack.top();
		stack.pop();
	}

	cout << output << endl; 


	return 0;
}
