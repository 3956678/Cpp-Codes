#include<iostream>
using namespace std;
struct Node {
    int value;
    Node* addr;
};
Node* head = NULL;
void insertatstart(int k) {
    Node* temp = new Node;
    temp->value = k;
    temp->addr = head;
    head = temp;
}
void insertatend(int k) {
    Node* newNode = new Node;
    newNode->value = k;
    newNode->addr = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->addr != NULL) {
        temp = temp->addr;
    }
    temp->addr = newNode;
}
void insertati(int a, int k) {
    if (a == 0) {
        insertatstart(k);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < a - 1; i++) {
        temp = temp->addr;
    }
    if (temp == NULL) {
        cout << "Position out of bounds\n";
        return;
    }
    Node* newNode = new Node;
    newNode->value = k;
    newNode->addr = temp->addr;
    temp->addr = newNode;
}
void deletion(int a) {
    if (head == NULL) {
        cout << "Nothing to delete\n";
        return;
    }
    if (a == 0) {
        Node* temp = head;
        head = head->addr;
        delete temp;
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < a - 1; i++) {
        temp = temp->addr;
    }
    if (temp == NULL || temp->addr == NULL) {
        cout << "Index out of bounds\n";
        return;
    }
    Node* toDelete = temp->addr;
    temp->addr = toDelete->addr;
    delete toDelete;
}
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->addr;
    }
    cout << endl;
}
int main() {
    int n, k, a;
    cout << "Linked List Operations:\n";
    cout << "1) Insert at start\n2) Display\n3) Insert at end\n4) Insert at some position\n5) Deletion at index\n6) Exit\n";
    cin >> n;
    while (n != 6) {
        switch (n) {
            case 1:
                cout << "Enter the value to insert at start: ";
                cin >> k;
                insertatstart(k);
                break;
            case 2:
                cout << "Current List: ";
                display();
                break;
            case 3:
                cout << "Enter the value to insert at end: ";
                cin >> k;
                insertatend(k);
                break;
            case 4:
                cout << "Enter the value to insert: ";
                cin >> k;
                cout << "Enter the position to insert at (0-based index): ";
                cin >> a;
                insertati(a, k);
                break;
            case 5:
                cout << "Enter the index to delete: ";
                cin >> a;
                deletion(a);
                break;
            default:
                cout << "Invalid option\n";
        }
        cout << "\nChoose operation:\n";
        cout << "1) Insert at start\n2) Display\n3) Insert at end\n4) Insert at some position\n5) Deletion at index\n6) Exit\n";
        cin >> n;
    }
    cout << "Final List: ";
    display();
    return 0;
}
