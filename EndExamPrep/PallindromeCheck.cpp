#include<iostream>
#include<deque>
using namespace std;
bool pallindromecheck(string s){
    deque<char> d;
    for(char c:s){
        d.push_back(c);
    }
    while(!d.empty()){
        char c1=tolower(d.front());
        d.pop_front();
        char c2=tolower(d.back());
        d.pop_back();
        if(c1!=c2){
            return false;
        }
        if(d.size()==1)
           return true;
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter the string:";
    cin>>s;
    if(pallindromecheck(s)){
        cout<<"the word "<<s<<" "<<"is a pallindrome"<<endl;
    }
    else{
          cout<<"the word "<<s<<" "<<"is not a pallindrome"<<endl;
    }
    return 0;
}