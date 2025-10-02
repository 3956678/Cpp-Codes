#include <iostream>
#include <cmath>
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
int evaluatePrefix(string prefix) {
    Stack st;
    for (int i = 0; i < prefix.length(); i++) {
        char ch = prefix[prefix.length()-i-1];
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int operand2 = st.pop();
            int operand1 = st.pop();
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
    return st.pop();
}
int main() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;
    int result = evaluatePrefix(prefix);
    cout << "Result of the prefix evaluation: " << result << endl;
    return 0;
}

