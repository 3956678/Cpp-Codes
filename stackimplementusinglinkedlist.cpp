#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Push operation to add an element to the stack
void push(Node*& top, int value) {
    Node* newNode = new Node;
    if (!newNode) {
        cout << "Stack overflow" << endl;
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack" << endl;
}

// Pop operation to remove an element from the stack
int pop(Node*& top) {
    if (!top) {
        cout << "Stack underflow" << endl;
        return -1;
    }
    Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

// Peek operation to get the top element of the stack
int peek(Node* top) {
    if (!top) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

// Display the stack
void display(Node* top) {
    if (!top) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* stack = nullptr; // Stack is initially empty

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    display(stack);

    cout << "Top element is " << peek(stack) << endl;

    cout << "Popped element is " << pop(stack) << endl;
    display(stack);

    return 0;
}
