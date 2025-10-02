#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* addr;
    Node* before;
};

Node* head = NULL;

void insertatstart(int k) {
    Node* temp = new Node;
    temp->value = k;
    temp->addr = head;
    temp->before = NULL;
    
    if (head != NULL) {
        head->before = temp;
    }
    
    head = temp;
}

void insertatend(int k) {
    Node* temp = new Node;
    temp->value = k;
    temp->addr = NULL;

    if (head == NULL) {
        temp->before = NULL;
        head = temp;
        return;
    }

    Node* current = head;
    while (current->addr != NULL) {
        current = current->addr;
    }

    current->addr = temp;
    temp->before = current;
}

void displayfromfront() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->addr;
    }
    cout << "\n";
}

void displayfromback() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp->addr != NULL) {
        temp = temp->addr;
    }

    while (temp != NULL) {
        cout << temp->value << " ";
        temp = temp->before;
    }
    cout << "\n";
}

void insertati(int a, int k) {
    if (a == 0) {
        insertatstart(k);
        return;
    }

    Node* temp = head;
    int i = 0;

    while (temp != NULL && i < a - 1) {
        temp = temp->addr;
        i++;
    }

    if (temp == NULL || temp->addr == NULL) {
        cout << "Invalid position\n";
        return;
    }

    Node* newNode = new Node;
    newNode->value = k;
    newNode->addr = temp->addr;
    newNode->before = temp;
    temp->addr->before = newNode;
    temp->addr = newNode;
}

void deletion(int a) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    if (a == 0) {
        head = head->addr;
        if (head != NULL) {
            head->before = NULL;
        }
        delete temp;
        return;
    }

    int i = 0;
    while (temp != NULL && i < a) {
        temp = temp->addr;
        i++;
    }

    if (temp == NULL) {
        cout << "Invalid position\n";
        return;
    }

    if (temp->before != NULL) {
        temp->before->addr = temp->addr;
    }
    if (temp->addr != NULL) {
        temp->addr->before = temp->before;
    }

    delete temp;
}

int main() {
    int n, k, a;
    cout << "Enter operation: \n1) Insert at start\n2) Display from front\n3) Insert at end\n4) Insert at position\n5) Delete node at index\n6) Exit\n7) Display from back\n";
    cin >> n;
    
    while (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 7) {
        switch (n) {
            case 1:
                cout << "Enter value: ";
                cin >> k;
                insertatstart(k);
                break;
            case 2:
                displayfromfront();
                break;
            case 3:
                cout << "Enter value: ";
                cin >> k;
                insertatend(k);
                break;
            case 4:
                cout << "Enter value: ";
                cin >> k;
                cout << "Enter position: ";
                cin >> a;
                insertati(a, k);
                break;
            case 5:
                cout << "Enter index to delete: ";
                cin >> a;
                deletion(a);
                break;
            case 7:
                displayfromback();
                break;
            default:
                break;
        }
        
        cout << "Enter operation: \n1) Insert at start\n2) Display from front\n3) Insert at end\n4) Insert at position\n5) Delete node at index\n6) Exit\n7) Display from back\n";
        cin >> n;
    }

    cout << "Final elements:\n";
    displayfromback();

    return 0;
}