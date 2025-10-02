#include<iostream>
#include<unordered_map>
using namespace std;
int no_of_subarray(int*a,int n,int k){
    unordered_map<int,int> cnt;
    int count=0;
    int sum=0;
    cnt[0]=1;
    for(int i=0;i<6;i++){
        sum+=a[i];
        if(cnt.count(sum-k)==1){
           count+=cnt[sum-k];
           cnt[sum]++;
        }
        if(cnt.count(sum)==0){
            cnt[sum]=1;
        }
    }
    return count;
}
int max_length_of_subarray(int*a,int n,int k){
    unordered_map<int,int> len;
    len[0]=-1;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(len.count(sum-k)==1){
            maxlen=max(maxlen,i-len[sum-k]);
        }
        if(len.count(sum)==0){
            len[sum]=i;
        }
    }
    return maxlen;
}
int main(){
    int a[6]={4, 5, 0, -2, -3, 1};
    int k = 5;
    int count=no_of_subarray(a,6,k);
    int maxlen=max_length_of_subarray(a,6,5);
    cout<<"Number of subarrays are:"<<count<<endl;
    cout<<"The longest subarray is of "<<maxlen<<" elements."<<endl;
}