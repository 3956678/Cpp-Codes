#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
string add_Strings(const string &a,const string &b){
    string res="";
    int carry=0,sum=0;
    int i=a.size()-1,j=b.size()-1;
    int d1,d2;
    while(i>=0||j>=0||carry){
        d1=(i>=0 ?a[i--]-'0':0);
        d2=(j>=0?b[j--]-'0':0);
        sum=d1+d2+carry;
        carry=sum/10;
        sum=sum%10;
        res.push_back(sum+'0');
    }
    reverse(res.begin(),res.end());
    return res;
}
string sub_Strings(const string &a,const string &b){
    string res="";
    int carry=0,sum=0;
    int i=a.size()-1,j=b.size()-1;
    int d1,d2;
    while(i>=0||j>=0){
        d1=(i>=0?a[i--]-'0':0);
        d2=(j>=0?b[j--]-'0':0);
        sum=d1-d2-carry;
        if(sum<0){
            sum+=10;
            carry=1;
        }
        else{
            carry=0;
        }
         res.push_back(sum+'0');
    }
    while(res.size()>1 && res[0]=='0')
        res.erase(res.begin());
    reverse(res.begin(),res.end());
    return res;
}
string karatsuba(const string &a,const string &b){
    if(a.size()<=5||b.size()<=5){
        long long a1=stoll(a);
        long long b1=stoll(b);
        long long c1=a1*b1;
        return to_string(c1);
    }
    int size=max(a.size(),b.size());
    int m=size/2;
    string p=a.substr(0,a.size()-m);
    string q=a.substr(a.size()-m);
    string r=b.substr(0,b.size()-m);
    string s=b.substr(b.size()-m);
    string r1=karatsuba(p,r);
    string r2=karatsuba(q,s);
    string r3=karatsuba(add_Strings(p,q),add_Strings(r,s));
    r3=sub_Strings(sub_Strings(r3,r1),r2);
    r1=r1+string(2*m,'0');
    r3=r3+string(m,'0');
    return add_Strings(add_Strings(r1,r2),r3);
}
int main(){
    string a,b;
    cout<<"Enter the string a and b:";
    cin>>a>>b;
    string c=karatsuba(a,b);
    cout<<"The result is:"<<c;
    return 0;
}