#include<iostream>
#include<cmath>
using namespace std;
long long karatsuba(long long a,long long b){ //using long long is best for overflow
    if(a<=1000||b<=1000){
        return a*b;
    }
    int n=max((int)log10(a)+1,(int)log10(b)+1);
    int m=n/2; //for odd numbers this is best
    long long base=1;
    for(int i=1;i<=m;i++)
      base*=10;
    int A=a/base;
    int B=a%base;
    int C=b/base;
    int D=b%base;
    long long ac=karatsuba(A,C);
    long long bd=karatsuba(B,D);
    long long ad_plus_bc=karatsuba(A+B,C+D)-ac-bd;
    return ac*base*base+bd+ad_plus_bc*base;
}
int main(){
    long long a,b,c;
    cout<<"Enter the numbers:";
    cin>>a>>b;
    c=karatsuba(a,b);
    cout<<"result is:"<<c<<endl;
}