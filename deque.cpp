#include<iostream>
using namespace std;
int f=-1,r=-1;
#define n 5
int a[n];
void enqueuefront(int k){
if(f==-1&&r==-1){
	f=r=0;
	a[r]=k;
 }
else if(f==0&&r==n-1||f==(r+1)){
	cout<<"overflow";
 }
else if(f==0){
	f=n-1;
	a[f]=k;
 }
else{
	f--;
	a[f]=k;
 }
}
void enqueuerear(int k){
	if(f==0&&r==n-1||f==r+1){
		cout<<"overflow";
	}
	else if(f==-1&&r==-1){
		f=r=0;
		a[r]=k;
	}
	else if(r==n-1){
		r=0;
		a[r]=k;
	}
	else{
		r++;
		a[r]=k;
	}
}
void dequeuefront(){
	if(f==-1||r==-1){
		cout<<"empty";
	}
	else if(f==r)
		f=r=-1;
	else if(f==n-1)
		f=0;
	else
		f++;
}
void dequeuerear(){
	if(f==-1||r==-1)
		cout<<"empty";
	else if(f==r)
		f=r=-1;
        else if(r==0)
		r=n-1;
	else
		r--;
}
void display(){
     for(int i=f;;i=(i+1)%5){
		cout<<a[i]<<" ";
          	if(i==r){
			break;
		}
	   }
     cout<<"\n";
}
int main(){
       int b,k;
       cout<<"enter the operation you want to do\n1)enqueuefront(1)\n2)enqueuerear(2)\n3)dequeuefront(3)\n4)dequeuerear(4)\n5)display(5)\n6)exit(0):";
       cin>>b;
       while(b==1||b==2||b==3||b==4||b==5){
	       switch(b){
		       case 1:cout<<"enter the value you want to enqueue:";
			      cin>>k;
			      enqueuefront(k);
			      break;
 case 2:cout<<"enter the value you want to enqueue:";
			      cin>>k;
			      enqueuerear(k);
			      break;
 case 3:		dequeuefront();
			      break;
 case 4:               dequeuerear();
			      break;
 case 5:               display();
		       break;
 default:break;
	       }
 cout<<"enter the operation you want to do\n1)enqueuefront(1)\n2)enqueuerear(2)\n3)dequeuefront(3)\n4)dequeuerear(4)\n5)display(5)\n6)exit(0):";
       cin>>b;
       }
       display();
       return 0;
}
       
