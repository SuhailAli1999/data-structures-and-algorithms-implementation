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

class Queue {
public:
	Node* front;
	Node* rear;

	Queue() {
		this->front = nullptr;
		this->rear = nullptr;
	}


	void EnQueue(int data) {
		Node* new_node = new Node(data);

		if (front == nullptr && rear == nullptr) {
			front = rear = new_node;
			return;
		}
		rear->next = new_node;
		rear = new_node;

	}
	void DeQueue() {
		Node* temp = front;
		if (front == nullptr) {
			cout << "Queue is empty !!" << endl;
		}
		else if  (front == rear) {
			front = rear = nullptr;
		}
		else {
			front = front->next;
			free(temp);
		}
	}

	int front_function() {
		if (front == NULL) {
			cout << "Queue is empty\n" ;
			return -1;
		}
		return this->front->data;
	}

	void print() {
		Node* current_node = front;
		while (current_node != nullptr) {
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
	}

};


int main()
{
	Queue q1;
	q1.EnQueue(2);
	q1.EnQueue(4);
	q1.EnQueue(5);
	q1.EnQueue(7);
	q1.print();
	q1.DeQueue();
	q1.print();



	return 0;

}

