#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head;

void InsertAtHead(int data) {

    Node* new_node = new Node();
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;


    }
}
void InsertAtTail(int data) {

    Node* new_node = new Node();
    new_node->data = data;

    if (head == NULL) {
        new_node->next = NULL;
        head = new_node;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;


    }



}
void InsertAt_nth(int data, int n) {

    Node* new_node = new Node();

    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        return;
    }

    if (n == 0) {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }
    
        Node* temp = head;

        for (int i = 0; i < n ; i++) {
            temp = temp->next;

            if (temp == NULL) {
                InsertAtTail(data);
                return;
            }
        }

            new_node->prev = temp->prev;
            temp->prev->next = new_node;
            temp->prev = new_node;
            new_node->next = temp;
        

}
void Delete_nth(int n) {

    Node* temp = head;

    for (int i = 0; i < n-1; i++) {

        temp = temp->next;
    }

    temp->next->next->prev = temp;

    temp->next = temp->next->next;


}

void Print() {
    Node* current_node = head;
    while (current_node != NULL) {
        cout << current_node->data << " " ;
        current_node = current_node->next;
    }
    cout << endl;
}
void Print_Reverse() {
    Node* current_node = head;
    if (head == NULL) {
        return;
    }
    else {
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        while (current_node != NULL) {
            cout << current_node->data;
            current_node = current_node->prev;
        }
    }
}



int main() {

    head = nullptr;
    InsertAt_nth(99, 0);
    InsertAt_nth(2, 2);
    InsertAt_nth(3, 1);
    InsertAt_nth(4, 1);
    InsertAt_nth(5, 1);
    InsertAt_nth(6, 67);
    Print();
    Delete_nth(3);
    Print();



    return 0;
}
