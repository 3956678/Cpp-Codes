#include <iostream>
#include <deque>
using namespace std;
bool isPalindrome(const string& str) {
    deque<char> dq;
    for (char ch : str) {
        if (isalnum(ch))
            dq.push_back(tolower(ch));
    }
    while (dq.size() > 1) {
        char front = dq.front();
        char back = dq.back();
        dq.pop_front();
        dq.pop_back();
        if (front != back)
            return false;
    }
    return true;
}
int main() {
    string s = "A man, a plan, a canal, Panama";
    if (isPalindrome(s))
        cout << "Palindrome\n";
    else
        cout << "Not a palindrome\n";
    return 0;
}