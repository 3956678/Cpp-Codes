#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s1, s2, result;
    int num1, num2;

    // Taking input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Pushing digits onto stacks
    while (num1 > 0) {
        s1.push(num1 % 10);
        num1 /= 10;
    }
    while (num2 > 0) {
        s2.push(num2 % 10);
        num2 /= 10;
    }

    int carry = 0;
    
    // Performing digit-wise addition
    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        
        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        carry = sum / 10;
        result.push(sum % 10);
    }

    // Printing the result
    cout << "Sum: ";
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
    cout << endl;

    return 0;
}