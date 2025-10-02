#include<iostream>
using namespace std;
int f=-1,r=-1;
#define n 5
int a[n];
void enqueue(int k){
	if(r==n){
		cout<<"it is full";
		exit(0);
	}
	else if(f==-1&&r==-1){
		f=r=0;
		a[r]=k;
	}
        else{
		r++;
		a[r]=k;
	}
}
void dequeue(){
	if(f==-1&&r==-1){
		cout<<"it is empty";
		exit(0);
	}
	else if(f-1==r){
             cout<<"underflow";
	     exit(0);
	}
	else
		f++;
}
void display(){
	for(int i=f;i<=r;i++)
		cout<<a[i]<<" ";
}
void deletenegatives(){
	int i=f;
	while(i<=r){
		if(a[i]<0&&i!=r){
			for(int j=i;j<=(r-1);j++){
				a[j]=a[j+1];
				cout<<"a";
			}
			r--;
		}
		else if(a[i]<0&&i==r)
			r--;
	         else
		    i++;	 
	}
}
int main(){
	int b,k;
	cout<<"\nenter the operation you want to do:1)enqueue(1)\n2)dequeue(2)\n3)display(3)\n4)exit(0)\n5)deletenegative(5):";
	cin>>b;
	while(b==1||b==2||b==3||b==5){
		switch(b){
			case 1:cout<<"enter the value you want to insert:";
			       cin>>k;
			       enqueue(k);
			       break;
			 case 2:dequeue();
				break;
			 case 3:display();
				break;
			case 5:deletenegatives();
			       break;
		         default:break;
		}
	cout<<"\nenter the operation you want to do:1)enqueue(1)\n2)dequeue(2)\n3)display(3)\n4)exit(0)\n5)deletenegative(5):";
	cin>>b;
	}
       cout<<"your elements are:";
       display();
       return 0;
}

