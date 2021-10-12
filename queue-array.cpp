#include <iostream>
using namespace std;

class Queue {
	int front;
	int rear;
	int arr[100];

public:
	/*Queue() {
		front = -1;
		rear = -1;
		memset(arr, 0, 100);
	}*/
	void EnQueue(int x) {
		if (rear == (size(arr) - 1)) { // is full
			cout << "Queue is full" << endl;
			return;
		}
		else if (IsEmpty()) {
			rear = 0;
			front = 0;
		}
		else {
			rear++;
		}
		arr[rear] = x;

	}
	void DeQueue() {
		if (IsEmpty()) {
			return;
		}
		else if (front == rear ) {
			front = -1;
			rear = -1;
		}
		else {
			front++;
		}

	}
	bool IsEmpty() {
		if (front == -1 && rear == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	int Front() {
		return arr[front];
	}
};

int main()
{




}
