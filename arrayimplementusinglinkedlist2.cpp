#include <iostream>
using namespace std;
#define SIZE 10 
int arr[SIZE]; 
int top1 = -1; 
int top2 = SIZE; 
void push1(int value) {
    if (top1 + 1 == top2) {
        cout<<"Stack Overflow! No space in Stack 1.\n";
        return;
    }
    arr[++top1] = value;
}
void push2(int value) {
    if (top2 - 1 == top1) {
        cout<<"Stack Overflow! No space in Stack 2.\n";
        return;
    }
    arr[--top2] = value;
}
int pop1() {
    if (top1 == -1) {
        cout<<"Stack Underflow! Stack 1 is empty.\n";
        return -1;
    }
    return arr[top1--];
}
int pop2() {
    if (top2 == SIZE) {
        cout<<"Stack Underflow! Stack 2 is empty.\n";
        return -1;
    }
    return arr[top2++];
}
void printStacks() {
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Stack 2: ");
    for (int i = SIZE - 1; i >= top2; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    push1(10);
    push1(20);
    push1(30);
    push2(100);
    push2(200);
    push2(300);   
    printStacks();
    printf("Popped from Stack 1: %d\n", pop1());
    printf("Popped from Stack 2: %d\n", pop2());
    printStacks();
    return 0;
}
