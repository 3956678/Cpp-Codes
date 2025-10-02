#include<iostream>
using namespace std;
int main(){
	int x,y,count=0;
	cout<<"enter the first value:";
	cin>>x;
	cout<<"enter the second value:";
	cin>>y;
	while(x!=y){
		if(x<y){
			x=x*2;
			count++;
			cout<<"step-"<<count<<":"<<"value*2="<<x<<endl;
		}
		if(x>y){
			x--;
			count++;
			cout<<"step-"<<count<<":"<<"value-1="<<x<<endl;
		}
	}
	cout<<"the number of steps it takes is:"<<count;
       return 0;
}       
