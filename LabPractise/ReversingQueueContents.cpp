#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
void queueReverse(){
     if(q.empty()){
        return;
     }
     int s=q.front();
     q.pop();
     queueReverse();
     q.push(s);
}
int main(){
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    queue<int> temp=q;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
    queueReverse();
    temp=q;
     while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
    return 0;
}