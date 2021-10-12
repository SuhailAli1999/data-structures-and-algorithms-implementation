#include <iostream>
using namespace std;

class Stack {
	int top;
	int arr[100];

public:
	

	Stack() {
		top = -1;
		memset(arr, 0, 100);
	}
	void push(int val) {
		if (top >= 99) {
			cout << "OverFlow!!" << endl;
		}
		else {
			arr[++top] = val;
		}
	}
	char pop() {
		if (isEmpty()) {
			cout << "UnderFlow" << endl;
		}
		else {
		
		    return arr[top--];

		}
	}
	int Top() {
		return arr[top];
	}
	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void print() {

		for (int i = top; i >= 0; i--) {
			cout << arr[i] << endl;
		}
	}
};

int main() {


	Stack s1;
	/*s1.push(2);
	s1.push(6);
	s1.push(7);
	s1.push(3);
	s1.pop();
	s1.print();

	cout << endl << s1.Top();
	*/
	char s[100] = "TheEnd";
	for (int i = 0; i < strlen(s); i++) {
		s1.push(s[i]);
	}
	for (int i = 0; i < strlen(s); i++) {
		s[i] = s1.Top();
		s1.pop();
	}

	cout << s << endl; 
	








	return 0;

}
