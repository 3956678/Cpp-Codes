#include<iostream>
#include<chrono>
#include<fstream>
#include<ctime>
#include<algorithm>
using namespace std::chrono;
using namespace std;
void fill(int *a,int n){
    for(int i=0;i<n;i++){
          a[i]=rand()%1000;
    }
}
void heapify(int* arr, int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int* arr,int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);    
        heapify(arr, i, 0);       
    }
}
void Bubble_sort(int*a,int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
void selectionSort(int*a,int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
void copyArray(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}
int main(){
    srand(time(0));
    ofstream fout("sorting.dat");
    for(int i=1000;i<=20000;i+=4000){
        int a[i],b[i],c[i];
        fill(a,i);
        copyArray(a,b,i);
        copyArray(a,c,i);
        auto t1 = high_resolution_clock::now();
        Bubble_sort(a,i);
        auto t2 = high_resolution_clock::now();
        auto tb = duration_cast<nanoseconds>(t2 - t1).count();        
        t1 = high_resolution_clock::now();
        selectionSort(b,i);
        t2 = high_resolution_clock::now();
        auto ts = duration_cast<nanoseconds>(t2 - t1).count();
        t1 = high_resolution_clock::now();
        heapSort(c,i);
        t2 = high_resolution_clock::now();
        auto th = duration_cast<nanoseconds>(t2 - t1).count();
        fout<<i<<" "<<tb<<" "<<ts<<" "<<th<<"\n";
    }
    return 0;
}