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
};

Node* head;



void InserAtHead(int data) {
    Node* new_node = new Node();
    new_node->data = data;
    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
    }
    else {
        new_node->next = head;
        head = new_node;

    }
}
void InsertAtTail(int data) {
    Node* new_node = new Node();
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->next = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; 
    }

    temp->next = new_node;
    new_node->next = NULL;


}
void Insert_nth(int data, int n) {

    Node* new_node = new Node();

    new_node->data = data;

    if (n == 0) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* prev;
    prev = head;
    for (int i = 0; i < n - 1 ; i++) {
        if (prev == NULL) {
            InsertAtTail(data);
            return;
        }
        prev = prev->next;
        }
        
    


    new_node->next = prev->next;
    prev->next = new_node;

}
void Delete_nth(int n) {

    Node* prev;
    prev = head;

    if (n == 1) {
        head = prev->next;
        free(prev);

    }
    else {
        for (int i = 0; i < n - 1 ; i++) {
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
void RemoveDuplicates() {

    Node* current_node = head;
    

    while (current_node->next != NULL && current_node != NULL) {

        Node* nextnext = current_node->next->next;

        if (current_node->data == current_node->next->data) {

            delete(current_node->next);
            current_node->next = nextnext;
        
        }  
        else {
            current_node = current_node->next;
        }
    }
}
Node* MergeToSortedLists(Node* l1, Node* l2) {

    Node* new_head = new Node();
    Node* l3 = new_head;

    while (l1 !=NULL && l2!=NULL) {
        if (l1->data <= l2->data) {
            l3->next = l1;
            l1 = l1->next;
        }
        else {
            l3->next = l2;
            l2 = l2->next;

        }
        l3 = l3->next;
    }


    if (l1 == NULL) {
        l3->next = l2;
    }
    if (l2 == NULL) {
        l3->next = l1;
    }

    

    return new_head->next;
}
void RemoveNthFromEnd(int n) {

    Node* slow = head;
    Node* fast = head;

    for (int i = 0; i < n+1; i++) {

        fast = fast->next;
    }


    while (fast != NULL) {
        slow = slow->next;
         fast = fast->next;
    }

    slow->next = slow->next->next;

}
void MiddleNode() {
    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    head = slow;
}


void print() {
    Node* current_node = head;
    while (current_node != NULL) {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}


int main() {

    head = nullptr;
   

    Insert_nth(1, 0);
    Insert_nth(6, 0);
    Insert_nth(2, 0);
    Insert_nth(5, 0);
    Insert_nth(5, 0);
    Insert_nth(6, 0);
    print();
    MiddleNode();
    print();

    return 0;
}
