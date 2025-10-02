#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ternarySearch(int s,int e,int key,int ar[],int n)
{   int count=1;  
    if(s<=e){
        int mid1 = s+(e-s)/3;
        int mid2 = e-(e-s)/3;
        if(ar[mid1]==key){
            return count;
        }
        if(ar[mid2]==key){
            return count;
        }
        if(key<ar[mid1]){
            return count+ternarySearch(s, mid1-1,key,ar,n);
        }
        else if(key>ar[mid2]){
            return count+ternarySearch(mid2+1,e,key,ar,n);
        }
        else {
            return count+ternarySearch(mid1+1, mid2-1,key,ar,n);
        }
    }
    return count;
}
int binarySearch(int s,int e,int key,int ar[],int n)
{   
    int count=1;
    if(s<=e){
        int mid1 =s+(e-s)/2;
        if(ar[mid1]==key){
            return count;
        }
        if(key<ar[mid1]){
            return count+binarySearch(s, mid1-1,key,ar,n);
        }
        else if(key>ar[mid1]){
            return count+binarySearch(mid1+1,e,key,ar,n);
        }
    }
    return count;
}
int main(){
    int a[46];
    srand(time(0));
    FILE *fp;
    fp=fopen("output.dat","w");
    for(int n=1;n<=45;n++){
        for(int i=0;i<n;i++){
            a[i]=rand()%100;
        }
        for(int i=1;i<n;i++){
        int val=a[i];
        int n1=i-1;
        while(val<a[n1]&&n1>=0){
                a[n1+1]=a[n1];
                n1--;
        }
        a[n1+1]=val;
    }
        int stepsbinary=binarySearch(0,n-1,-1,a,n);
        int stepsternary=ternarySearch(0,n-1,-1,a,n);
        fprintf(fp,"%d %d %d\n",n,stepsbinary,stepsternary);
    }
    fclose(fp);
    printf("data feeding is complete");
    return 0;
}