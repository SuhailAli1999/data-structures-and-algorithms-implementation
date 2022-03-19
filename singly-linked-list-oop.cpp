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
class List {
public:
	Node* head;

	List() {
		this->head = nullptr;
	}

	void insert_frist(int data) {

		Node* new_node = new Node(data);
		//new_node->data = data;

		if (head == nullptr) {
			this->head = new_node;
			new_node->next = nullptr;
		}
		else {
			new_node->next = this->head;
			this->head = new_node;
		}
		
	}
	void insert_nth(int data, int n) {
		Node* new_node = new Node(data);

		if (n == 0) {
			insert_frist(data);
		}
		else {
			Node* prev = this->head;

			for (int i = 0; i < n - 1 && prev->next != nullptr; i++) {
				prev = prev->next;
			}
			new_node->next = prev->next;
			prev->next = new_node;

		}
	}
	void delete_nth(int n) {

		Node* prev = head;

		if (n == 0) {
			head = prev->next;
			delete prev;

		}
		else {
			for (int i = 0; i < n - 2; i++) {
				prev = prev->next;
			}
			Node* element_del;
			element_del = prev->next;
			prev->next = element_del->next;
			// prev->next = prev->next->next;

			delete element_del;


		}

	}
	void reverse() {

		if (head == NULL) {
			return;
		}

		Node* current = this->head;
		Node* prev = nullptr;
		Node* next;

		
		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
			

	}

	
	void print() {
		Node* current_node = this->head;
		while (current_node != nullptr) {
			cout << current_node->data << " ";
			current_node = current_node->next;
		}
		cout << endl;
	}
};




int main()
{
  


	return 0;
}

