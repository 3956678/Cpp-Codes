#include<iostream>
#include<algorithm>
#include<chrono>
#include<fstream>
#include<ctime>
using namespace std::chrono;
using namespace std;
void fill_ascending(int *a,int n){
     for(int i=0;i<n;i++){
          a[i]=rand()%1000;
    }
    sort(a,a+n);
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
    ofstream fout("Quickascending.dat");
    for(int i=1000;i<=7000;i+=1000){
        int pos=rand()%i;
        int c[i],e[i];
        fill_ascending(c,i);
        copyArray(c,e,i);
        auto t1 = high_resolution_clock::now();
        quicksort(c,0,i);
        auto t2 = high_resolution_clock::now();
        auto tqa = duration_cast<microseconds>(t2 - t1).count(); 
        swap(e[pos],e[i-1]);
        t1 = high_resolution_clock::now();
        quicksort(e,0,i);
        t2 = high_resolution_clock::now();
        auto trqa = duration_cast<microseconds>(t2 - t1).count();
        fout<<i<<" "<<tqa<<" "<<trqa<<" "<<" "<<"\n";
    }
    return 0;
}