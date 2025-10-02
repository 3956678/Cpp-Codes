#include <iostream>

using namespace std;
struct Node {
  int data;
  Node * next;
};

void push(Node * & top, int value) {
  Node * newNode = new Node;
  if (!newNode) {
    cout << "Stack overflow" << endl;
    return;
  }
  newNode -> data = value;
  newNode -> next = top;
  top = newNode;
  cout << value << " pushed to stack" << endl;
}

int pop(Node * & top) {
  if (!top) {
    cout << "Stack underflow" << endl;
    return -1;
  }
  Node * temp = top;
  int poppedValue = top -> data;
  top = top -> next;
  delete temp;
  return poppedValue;
}

int peek(Node * top) {
  if (!top) {
    cout << "Stack is empty" << endl;
    return -1;
  }
  return top -> data;
}

void display(Node * top) {
  if (!top) {
    cout << "Stack is empty" << endl;
    return;
  }
  Node * temp = top;
  while (temp) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
  cout << endl;
}

int main() {
  Node * stack = nullptr;

  int l;
  do {
    cout << "Enter 1 -to push\nEnter 2 -pop\nEnter 3 - peek value \nEnter 4 -display\nEnter 5 -exit\n";
    cin >> l;
    switch (l) {
    case 1: {
      int x;
      cout << "Enter the element : ";
      cin >> x;
      push(stack, x);
      break;
    }
    case 2: {
      pop(stack);
      break;
    }
    case 3: {
      peek(stack);
      cout << "\n";
      break;
    }
    case 4: {
      display(stack);
    }
    case 5: {
      exit(0);
    }
    default:
      break;
    }
  } while (l != 5);

  return 0;
}