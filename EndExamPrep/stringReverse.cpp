#include<iostream>
#include<stack>
using namespace std;
string reverse(string s){
    stack<char> q;
    for(char c:s){
        q.push(c);
    }
    string final;
    while(!q.empty()){
       final+=q.top();
       q.pop();
    }
    return final;
}
int main(){
    string s;
    cout<<"Enter String:";
    cin>>s;
    s=reverse(s);
    cout<<"Reversed is:"<<s<<endl;
    return 0;
}