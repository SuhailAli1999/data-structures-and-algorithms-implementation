#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};


class Stack {
public:
	Node* top;

	Stack() {
		top = nullptr;
	}

	void push(int data) {
		Node* new_node = new Node(data);
		if (top == nullptr) {
			top = new_node;
		}
		else {
			new_node->next = top;
			top = new_node;
		}
	}
	void pop() {
		if (top == nullptr) {
			cout << "Stack underflow!!";
			return;
		}
		else {
			Node* temp = top;
			top = top->next;
			free(temp);

		}
	}
	int Top() {
		if (top == nullptr) {
			cout << "Stack overflow!!" << endl;
			return -1;
		}
		else {
			return this->top->data;
		}
	}
	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	void print() {
		if (top == nullptr) {
			cout << "Stack underflow!!" << endl;
		}
		else {
			Node* current_node = top;
			while (current_node != nullptr) {
				cout << current_node->data << endl;
				current_node = current_node->next;
			}
		}
	}


};



int main()
{
	Stack s1;
	s1.push(5);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.print();

}

