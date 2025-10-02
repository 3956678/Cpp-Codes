#include<iostream>
#include<unordered_map>
using namespace std;
int max_length_of_subarray(int*a,int n,int k){
    unordered_map<int,int> len;
    int start=0,end=0;
    len[0]=-1;
    int maxlen=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(len.count(sum-k)==1){
            if(maxlen<i-len[sum-k]){
                start=len[sum-k]+1;
                end=i;
                maxlen=i-len[sum-k];
            }
        }
        if(len.count(sum)==0){
            len[sum]=i;
        }
    }
    for(int i=start;i<=end;i++){
       cout<<a[i]<<" ";
    }
    cout<<endl;
    return maxlen;
}
int main(){
    int a[6]={4, 5, 0, -2, -3, 1};
    int k = 0;
    int l=max_length_of_subarray(a,6,k);
    cout<<l<<endl;
    return 0;
}