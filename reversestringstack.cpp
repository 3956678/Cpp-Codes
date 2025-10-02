#include<iostream>
#include<string>
using namespace std;
int s = -1;
char a[100];
void push(char);
void input(string);
void pop();
int main() {
  string b;
  cout << "enter the String:";
  getline(cin, b);
  input(b);
  return 0;
}
void input(string b) {
  for (char ch: b)
    push(ch);
  pop();
}
void push(char c) {
  if (s == -1) {
    s = 0;
    a[s] = c;
  } else {
    s++;
    a[s] = c;
  }
  return;
}
void pop() {
  for (s; s >= 0; s--)
    cout << a[s];
}