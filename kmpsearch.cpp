#include<iostream>
#include<vector>
#include <string>
using namespace std;
vector<int> lps(const string &p){
    int m=p.size();
    vector<int> lps(m,0);
    int i=1;
    int len=0;
    while(i<m){
        if(p[i]==p[len]){
            len++;
            lps[i++]=len;
        }
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i++]=0;
            }
        }
    }
    return lps;
}
void kmp(const string &p,const string &a){
    vector<int> a1=lps(p);
    int m=p.size();
    int n=a.size();
    int i=0,j=0;
    while(j<n){
        if(p[i]==a[j]){
            i++;
            j++;
        }
        if(i==m){
            cout<<"Found a matching pattern in: "<<j-i<<endl;
            i=a1[i-1];
        }
        else if(j<n && p[i]!=a[j]){
           if(i!=0){
            i=a1[i-1];
           }
           else{
            j++;
           }
        }
    }
}
int main(){
    string text = "ABABDABACDABABCABABABABCABAB";
    string pattern = "ABABCABAB";
    kmp(pattern,text);
    return 0;
}