#include<iostream>
using namespace std;
int f1=-1,r1=-1,f2=-1,r2=-1;
#define n 5
int a[n];
int b1[n];
void enqueue1(int k){
	if(r1==n){
		cout<<"it is full";
		exit(0);
	}
	else if(f1==-1&&r1==-1){
		f1=r1=0;
		a[r1]=k;
	}
        else{
		r1++;
		a[r1]=k;
	}
}
void dequeue1(){
	if(f1==-1&&r1==-1){
		cout<<"it is empty";
		exit(0);
	}
	else if(f1-1==r1){
             cout<<"underflow";
	     exit(0);
	}
	else
		f1++;
}
void display1(){
	for(int i=f1;i<=r1;i++)
		cout<<a[i]<<" ";
}
void enqueue2(int k){
	if(r2==n){
		cout<<"it is full";
		exit(0);
	}
	else if(f2==-1&&r2==-1){
		f2=r2=0;
		b1[r2]=k;
	}
        else{
		r2++;
		b1[r2]=k;
	}
}
void dequeue2(){
	if(f2==-1&&r2==-1){
		cout<<"it is empty";
		exit(0);
	}
	else if(f2-1==r2){
             cout<<"underflow";
	     exit(0);
	}
	else
		f2++;
}
void display2(){
	for(int i=f2;i<=r2;i++)
		cout<<b1[i]<<" ";
}
void comparision(int *a,int *b1){
	if((r1-f1)!=(r2-f2)){
		cout<<"the queues are not identical";
		exit(0);
	}
	int i=f1,j=f2;
	while(i<=r1&&j<=r2){
		if(a[i]!=b1[j]){
			cout<<"the queues are not identical\n";
	exit(0);
		}
		i++;
		j++;
	}
	cout<<"the queues are identical";
}
int main(){
	int b,k;
	cout<<"\nenter the operation you want to do:1)enqueue in 1stqueue(1)\n2)dequeue for 1stqueue(2)\n3)display for 1stqueue(3)\n4)enqueue for 2ndqueue\n5)dequeue for 2ndqueue\n6)display for 2ndqueue\n7)comparision\n8)exit(0):";
	cin>>b;
	while(b==1||b==2||b==3||b==4||b==5||b==6||b==7){
		switch(b){
			case 1:cout<<"enter the value you want to insert:";
			       cin>>k;
			       enqueue1(k);
			       break;
			 case 2:dequeue1();
				break;
			 case 3:display1();
				break;
		         case 4:cout<<"enter the value you want to insert:";
			       cin>>k;
			       enqueue2(k);
			       break;
			 case 5:dequeue2();
				break;
			 case 6:display2();
				break;
			 case 7:comparision(a,b1);
				break;
		         default:break;
		}
	cout<<"\nenter the operation you want to do:1)enqueue in 1stqueue(1)\n2)dequeue for 1stqueue(2)\n3)display for 1stqueue(3)\n4)enqueue for 2ndqueue\n5)dequeue for 2ndqueue\n6)display for 2ndqueue\n7)comparision\n8)exit(0):";	
   cin>>b;
	}
       return 0;
}

