#include<iostream>
#include<vector>
#include <algorithm>
#include<ctime>
using namespace std;
vector<int> fill(int n){
    vector<int> a;
    for(int i=0;i<n;i++){
       a.push_back(rand()%100);
    }
    return a;
}
int linearselection(vector<int> a,int left,int right,int k){
    if(k<0||k>a.size()){
        cout<<"not correct";
        return -1;
    }
    if(a.size()<=5){
        sort(a.begin(),a.end());
        return a[k-1];
    }
    vector<int> median;
    for(int i=left;i<=right;i+=5){
        int end=min(i+4,right);
        vector<int> group(a.begin()+i,a.begin()+end+1);
        sort(group.begin(),group.end());
        median.push_back(group[group.size()/2]);
    }
    int pivot=linearselection(median,0,median.size()-1,median.size()/2);
    int pivotindex=left;
    for(int i=left;i<=right;i++){
        if(a[i]==pivot){
            swap(a[i],a[right]);
            break;
        }
    }
    for(int i=left;i<right;i++){
        if(pivot>a[i]){
            swap(a[pivotindex],a[i]);
            pivotindex++;
        }
    }
    swap(a[pivotindex],a[right]);
    int rank=pivotindex-left+1;
    if(k==rank)
      return a[pivotindex];
    else if(k<rank)
       return linearselection(a,left,pivotindex-1,k);
    else
       return linearselection(a,pivotindex+1,right,k-rank);
}
int main(){
    srand(time(0));
    vector<int> a;
    int n,k;
    cout<<"Enter number of days:";
    cin>>n;
    a=fill(n);
    cout<<"Enter the kth smallest you want:";
    cin>>k;
    int k1=0.9*n;
    cout<<"The 90th percentile is:"<<k1<<endl;
    cout<<"Initially:";
    for(int i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
    int i=linearselection(a,0,a.size()-1,k);
    int i1=linearselection(a,0,a.size()-1,k1);
    cout<<"The kth smallest stock is:"<<i<<endl;
    cout<<"The 90th percentile stock is:"<<i1<<endl;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
      cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}