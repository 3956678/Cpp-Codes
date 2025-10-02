#include <iostream>
#include <cmath> // For pow function
using namespace std;
const int MAX_SIZE = 100;
class Stack {
    int arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }
    int pop() {
        if (top < 0) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string postfix) {
    Stack st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // If character is a digit, push it to the stack
        if (isdigit(ch)) {
            st.push(ch - '0'); // Convert char to integer
        } else {
            // Pop two elements from stack for operation
            int operand2 = st.pop();
            int operand1 = st.pop();

            // Perform the operation and push the result back onto the stack
            switch (ch) {
                case '+':
                    st.push(operand1 + operand2);
                    break;
                case '-':
                    st.push(operand1 - operand2);
                    break;
                case '*':
                    st.push(operand1 * operand2);
                    break;
                case '/':
                    st.push(operand1 / operand2);
                    break;
                case '^':
                    st.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }
        }
    }

    // The final result is on top of the stack
    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix evaluation: " << result << endl;

    return 0;
}

