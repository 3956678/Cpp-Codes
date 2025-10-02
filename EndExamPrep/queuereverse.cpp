#include<iostream>
#include<queue>
using namespace std;
void queueReverse(queue<int>& q){
    if(q.empty()){
        return;
    }
    int s=q.front();
    q.pop();
    queueReverse(q);
    q.push(s);
}
void queueDisplay(queue<int> q){
    int n=q.size();
    int a[n]={0};
    int i=0;
    while(!q.empty()){
        cout<<q.front()<<" ";
        a[i++]=q.front();
        q.pop();
    }
    for(int j=0;j<i;j++){
        q.push(a[j]);
    }
}
int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queueDisplay(q);
    cout<<endl;
    queueReverse(q);
    queueDisplay(q);
    cout<<endl;
   queueReverse(q);
    queueDisplay(q);
    cout<<endl;
    queueDisplay(q);
    cout<<endl;
}