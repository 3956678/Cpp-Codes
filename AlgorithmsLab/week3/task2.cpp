#include<iostream>
#include<algorithm>
#include<chrono>
#include<fstream>
#include<ctime>
using namespace std::chrono;
using namespace std;
void fill(int *a,int n){
    for(int i=0;i<n;i++){
          a[i]=rand()%1000;
    }
}
int partition(int *a,int s,int e){
    int p=a[e];
    int i=s-1;
    int j=s;
    for(j;j<e;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[e],a[i]);
    return i;
}
void quicksort(int* a,int s,int e){
    if(s<e){
       int i=partition(a,s,e);
       quicksort(a,s,i-1);
       quicksort(a,i+1,e);
    }
}
void copyArray(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}
int main(){
    srand(time(0));
    ofstream fout("QuickSortAnalysis.dat");
    for(int i=1000;i<=7000;i+=1000){
        int pos=rand()%i;
        int a[i],b[i];
        fill(a,i);
        copyArray(a,b,i);
        auto t1 = high_resolution_clock::now();
        quicksort(a,0,i);
        auto t2 = high_resolution_clock::now();
        auto tq = duration_cast<microseconds>(t2 - t1).count(); 
        swap(b[pos],b[i-1]);       
        t1 = high_resolution_clock::now();
        quicksort(b,0,i);
        t2 = high_resolution_clock::now();
        auto trq = duration_cast<microseconds>(t2 - t1).count();
        fout<<i<<" "<<tq<<" "<<trq<<"\n";
    }
    return 0;
}