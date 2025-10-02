#include<iostream>
#include<stack>
using namespace std;
int addition(int a,int b){
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    int r;
    while(a!=0){
        r=a%10;
        s1.push(r);
        a=a/10;
    }
     while(b!=0){
        r=b%10;
        s2.push(r);
        b=b/10;
    }
    int carry=0;
    if(s1.size()>s2.size()){
        while(s2.size()!=s1.size())
           s2.push(0);
    }
    else if(s1.size()<s2.size()){
        while(s1.size()!=s2.size())
           s1.push(0);
    }
    while(!s1.empty()&&!s2.empty()){
        int p1,p2;
          p1=s1.top();
          s1.pop();
          p2=s2.top();
          s2.pop();
        p1=p1+p2+carry;
        if(p1>10){
            carry=p1/10;
            p1=p1%10;
        }
        s3.push(p1);
    }
    int p2=1,p1=0,p3=0;
    while(!s3.empty()){
       p3=s3.top();
       p1+=p3*p2;
       p2*=10;
       s3.pop();
    }
    return p1;
}
int main(){
    cout<<addition(12345,2314)<<endl;
    return 0;
}