#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
struct CircularDoublyLinkedList {
    Node* head;
    CircularDoublyLinkedList() {
        head = nullptr;
    }    
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = newNode->prev = nullptr;
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            newNode->next = head;
            newNode->prev = last;
            last->next = newNode;
            head->prev = newNode;
        }
    }
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head->prev;
        do {
            cout << temp->data << " -> ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << "HEAD" << endl;
    }
};
int main() {
    CircularDoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.displayForward();
    list.displayBackward();
    return 0;
}
