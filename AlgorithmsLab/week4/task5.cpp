#include<iostream>
#include<vector>
#include <algorithm>
#include<chrono>
#include<fstream>
#include<ctime>
using namespace std::chrono;
using namespace std;
vector<int> fill(int n){
    vector<int> a;
    for(int i=0;i<n;i++){
       a.push_back(rand()%100);
    }
    return a;
}
int linearselection(vector<int> &a,int left,int right,int k){
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
    int pivot=linearselection(median,0,median.size()-1,median.size()/2+1);
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
void merge(vector<int> &a,int s,int e){
    int mid=(s+e)/2;
    vector<int> temp(e-s+1);
    int i=s;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=e){
        if(a[i]>a[j]){
            temp[k++]=a[j++];
        }
        else if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[i++];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int p=0;p<k;p++){
        a[s+p]=temp[p];
    }
}
void mergesort(vector<int> &a,int s,int e){
    int mid=(s+e)/2;
    if(s<e){
         mergesort(a,s,mid);
         mergesort(a,mid+1,e);
         merge(a,s,e);
         return;
    }
    return;
}
int kth_element(vector<int> &a,int k){
    mergesort(a,0,a.size()-1);
    return a[k-1];
}
int main(){
    srand(time(0));
    ofstream fout("linear selection time performance.dat");
    for(int i=10000;i<=100000;i+=10000){
        vector<int> a;
        a=fill(i);
        vector<int> b(a);
        int k=(rand()%i)+1;
        auto t1=high_resolution_clock::now();
        linearselection(a,0,a.size()-1,k);
        auto t2=high_resolution_clock::now();
        auto tl=duration_cast<microseconds>(t2-t1).count();
        t1=high_resolution_clock::now();
        kth_element(b,k);
        t2=high_resolution_clock::now();
        auto tm=duration_cast<microseconds>(t2-t1).count();
        fout<<i<<" "<<tl<<" "<<tm<<"\n";
    }
    return 0;
}