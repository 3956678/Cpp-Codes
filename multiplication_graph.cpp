#include<iostream>
#include<cmath>
#include<string>
#include<random>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;
long long randomBigInt(int digits) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 9);
    string num;
    num.reserve(digits); //it preallocates some memory
    uniform_int_distribution<int> firstDist(1, 9);
    num += to_string(firstDist(gen));
    for (int i = 1; i < digits; i++) {
        num += to_string(dist(gen));
    }
    long long num1=stoll(num); //to convert string to long long
    return num1;
}
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
long long bruteforce(long long a,long long b){
    if(a>b)
     swap(a,b);
    long long result=0;
    int rem=0;
    int base=1;
    while(a!=0){
        rem=a%10;
        result+=(b*rem)*base;
        a=a/10;
        base*=10;
    }
    return result;
}
int main(){
    ofstream fout("Multiplication.dat");
    long long a;
    long long b;
    fout<<"no.of digits"<<" "<<"karatsuba"<<"bruteforce"<<"\n";
    for(int i=10;i<=17;i++){
         a=randomBigInt(i);
         b=randomBigInt(i);
        auto t1=high_resolution_clock::now();
        karatsuba(a,b);
        auto t2=high_resolution_clock::now();
        auto tk=duration_cast<nanoseconds>(t2-t1).count();
        t1=high_resolution_clock::now();
        bruteforce(a,b);
        t2=high_resolution_clock::now();
        auto tb=duration_cast<nanoseconds>(t2-t1).count();
        fout<<i<<" "<<tk<<" "<<tb<<"\n";
    }
    fout.close();
    return 0;
}