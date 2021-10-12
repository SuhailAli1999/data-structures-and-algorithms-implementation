#include <iostream>
#include <stddef.h>
#include <conio.h>
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

class List {

public:
	Node* head;

	List() {
		this->head = nullptr;
	}

	void Insert_first(int data) {

		Node* new_node = new Node(data);

		//new_node->data = data;

		if (head == NULL) {
			this->head = new_node;
			new_node->next = NULL;

		}
		else {
			new_node->next = this->head;
			this->head = new_node;
		}


	}
	void Insert_nth(int data, int n) {

		Node* new_node = new Node(data);



		if (n == 1) {
			new_node->next = this->head;
			this->head = new_node;

		}
		else {
			Node* prev;
			prev = this->head;
			for (int i = 0; i < n - 2; i++) {
				prev = prev->next;
			}
			new_node->next = prev->next;
			prev->next = new_node;
		}
	}
	void Delete_nth(int n) {

		Node* prev;
		prev = head;

		if (n == 1) {
			head = prev->next;
			free(prev);

		}
		else {
			for (int i = 0; i < n - 2; i++) {
				prev = prev->next;
			}
			Node* element_del;
			element_del = prev->next;
			prev->next = element_del->next;
			// prev->next = prev->next->next;

			free(element_del);

		}
	}
	void Reverse() {

		if (head == NULL) {
			return;
		}
		Node* prev = NULL;
		Node* current = head;
		Node* next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void Print(Node* head) {

		//Node* current_node = head;
		while (head != NULL) {
			cout << head->data << " ";
			head = head->next;

		}
		cout << endl;

	}



};



int main()
{
	
	List l1;
	l1.Insert_first(1);
	l1.Insert_first(2);
	l1.Insert_first(3);
	l1.Insert_first(4);
	l1.Print(l1.head);

	return 0;
}

