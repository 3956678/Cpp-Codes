#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert element at the end of the linked list
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Get element at a specific index
int get(Node* head, int index) {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (count == index) {
            return temp->data;
        }
        count++;
        temp = temp->next;
    }
    throw out_of_range("Index out of bounds");
}

// Update element at a specific index
void update(Node* head, int index, int value) {
    Node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        if (count == index) {
            temp->data = value;
            return;
        }
        count++;
        temp = temp->next;
    }
    throw out_of_range("Index out of bounds");
}

// Delete element at a specific index
void remove(Node*& head, int index) {
    if (head == nullptr) {
        throw out_of_range("List is empty");
    }

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        throw out_of_range("Index out of bounds");
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Display all elements in the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Free memory
void freeList(Node*& head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Insert elements
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    display(head);

    // Access element at index 1
    cout << "Element at index 1: " << get(head, 1) << endl;

    // Update element at index 1
    update(head, 1, 25);
    display(head);

    // Remove element at index 1
    remove(head, 1);
    display(head);

    // Free memory
    freeList(head);

    return 0;
}
