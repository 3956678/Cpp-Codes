#include<iostream>
using namespace std;
int s=-1;
int a[5];
void push(int k){
	if(s==-1){
		s=0;
		a[s]=k;
	}
	else if(s==5){
		cout<<"the stack is full";
		exit(0);
	}
	else{
		s++;
		a[s]=k;
	}
}
int pop(){
	if(s==-1){
		cout<<"the stack is empty";
		exit(0);
	}
	else{
		int k=a[s];
		s--;
		return k;
	}
}
void display(){
	    while(s>=0)
		cout<<pop()<<" ";
}
int main(){
    int n,k;
    cout<<"enter the operation you want to do 1)push(1)\n2)pop(2)\n3)display(3)\n4)exit(0):";
    cin>>n;
    while(n==1||n==2||n==3){
	switch(n){
		case 1:cout<<"enter the value you want to push:";
	              cin>>k;
	              push(k);
                      break;
                case 2:pop();
                       break;
                case 3:display();
                       break;
                default:break;
	}
 cout<<"enter the operation you want to do 1)push(1)\n2)pop(2)\n3)display(3)\n4)exit(0):";
    cin>>n;
    }
    return 0;
}
    
