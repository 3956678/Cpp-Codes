#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
vector<int> robin(string &pattern,string &key){
  int n=pattern.size();
  int m=key.size();
  int base=256; //like 3*10^m-1 so on but with 256
  int mod=101; //if value is high it becomes difficult so we mod it
  int h=(int)pow(base,m-1)%mod;
  int p=0,q=0; //pattern hash value and key value hash
  vector<int> results;
  for(int i=0;i<m;i++){
     p=(p*base+pattern[i])%mod;
     q=(q*base+key[i])%mod;
  }
  for(int i=0;i<=n-m;i++){
    if(p==q){
        bool match=true;
        for(int j=0;j<m;j++){
            if(pattern[i+j]!=key[j]){
               match=false;
               break;
            }
        }
        if(match)
           results.push_back(i);
    }
    if(i<n-m)
    p=(base*(p-pattern[i]*h)+pattern[i+m])%mod;
    if(p<0)
      p+=mod;
  }
  return results;
}
int main(){
    string text="ababcabdababc";
    string pattern="abc";
    vector<int> results=robin(text,pattern);
    for(int index:results){
        cout<<"The results found at: "<<index+1<<endl;
    }
    return 0;
}