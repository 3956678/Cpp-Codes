#include<stdio.h>
int n=5;
void add_Element(int* a,int pos,int key,int size){
//adding an element    
    if(pos==size){
        a[pos]=key;
        n++;
        return;
    }
    int temp=a[pos-1];
    a[pos-1]=key;
    add_Element(a,pos+1,temp,size);
    return;
}
void delete_usingpos(int* a,int pos){
 //deleting an element
    while(pos<=n){
        if(pos==(n)){
            a[pos-1]=0;
            n--;
            return;
        }
        int temp=a[pos-1];
        a[pos-1]=a[pos];
        a[pos]=temp;
        pos++;
    }
    return;
}
void delete_usingval(int* a,int val){
 //deleting an element
 int pos=0;
 for(int i=0;i<n;i++){
    if(a[i]==val){
        pos=i+1;
        break;
    }
 }
    while(pos<=n){
        if(pos==(n)){
            a[pos-1]=0;
            n--;
            return;
        }
        int temp=a[pos-1];
        a[pos-1]=a[pos];
        a[pos]=temp;
        pos++;
    }
    return;
}
int ternarySearch(int s,int e,int key,int ar[])
{   
     for(int i=1;i<n;i++){
        int val=ar[i];
        int n=i-1;
        while(val<ar[n]&&n>=0){
                ar[n+1]=ar[n];
                n--;
        }
        ar[n+1]=val;
    }
    if(s<=e){
        int mid1 = s+(e-s)/3;
        int mid2 = e-(e-s)/3;
        if(ar[mid1]==key){
            return mid1;
        }
        if(ar[mid2]==key){
            return mid2;
        }
        if(key<ar[mid1]){
            return ternarySearch(s, mid1-1,key,ar);
        }
        else if(key>ar[mid2]){
            return ternarySearch(mid2+1,e,key,ar);
        }
        else {
            return ternarySearch(mid1+1, mid2-1,key,ar);
        }
    }
    return -1;
}
int binarySearch(int s,int e,int key,int ar[])
{   
     for(int i=1;i<n;i++){
        int val=ar[i];
        int n=i-1;
        while(val<ar[n]&&n>=0){
                ar[n+1]=ar[n];
                n--;
        }
        ar[n+1]=val;
    }
    if(s<=e){
        int mid1 =s+(e-s)/2;
        if(ar[mid1]==key){
            return mid1;
        }
        if(key<ar[mid1]){
            return binarySearch(s, mid1-1,key,ar);
        }
        else if(key>ar[mid1]){
            return binarySearch(mid1+1,e,key,ar);
        }
    }
    return -1;
}
int main(){
 //initialize the array
 int a[10]={2,3,1,4,5};
 int n1;
 int element,position2;
 printf("Enter the operation you want to do: 1)add \n2)delete with position \n3)print: \n 4)deletewithvalue\n5)binary search\n6)ternary search 7)exit");
 scanf("%d",&n1);
 while(n1!=7){
 switch(n1){
    case 1:printf("Enter element you want to add:");
           scanf("%d",&element);
           printf("Enter the position:");
           scanf("%d",&position2);
           add_Element(a,position2,element,n);
           break;
    case 2:printf("Enter the position:");
           scanf("%d",&position2);
           delete_usingpos(a,position2);
           break;
    case 3:for(int i=0;i<n;i++){
        printf("%d ",a[i]);
         }
        printf("\n");
        break;
    case 4:printf("Enter the value:");
           scanf("%d",&element);
           delete_usingval(a,element);
    case 5:printf("Enter element:");
           scanf("%d",&element);
          int position=ternarySearch(0,n-1,element,a);
          if(position==-1){
            printf("Element not found");
           }
          else{
          printf("Element found in %d",position+1);
          }
          printf("\n");
          break;
    case 6:printf("Enter element:");
           scanf("%d",&element);
          int position1=ternarySearch(0,n-1,element,a);
          if(position1==-1){
            printf("Element not found");
           }
          else{
          printf("Element found in %d",position1+1);
          }
          printf("\n");
          break;
         }
          printf("Enter the operation you want to do: 1)add \n2)delete with position \n3)print: \n 4)deletewithvalue\n5)binary search\n6)ternary search 7)exit");
         scanf("%d",&n1);
 }
 return 0;
}