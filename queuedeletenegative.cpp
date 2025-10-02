#include <iostream>
#include <queue>
#include <string>
using namespace std;
using std::queue;
queue<int> q,tempq;
int main(){
    int n;
    cout << "Enter no of values to be entereed in the queue :";
    cin >> n ;
    for(int i=0;i<n;i++){
        cout << "enter no " << i+1 << " : ";
        int value;
        cin >> value;
        q.push(value);
    }
    tempq=q;
    cout << "queue before : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
    for(int i=0;i<n;i++){
        if(tempq.front()<0)
            tempq.pop();
        else{
            q.push(tempq.front());
            tempq.pop();
        }
    }
    cout << "queue after : ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}