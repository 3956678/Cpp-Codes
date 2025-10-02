#include<iostream>
using namespace std;
int main(){
	int a[9];
	for(int i=0;i<9;i++){
		cout<<"enter your "<<i+1<<"element:";
		cin>>a[i];
	}
	cout<<"initial elements are:";
	for(int i=0;i<9;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	int largest=0,cnt=0;
	cout<<"the next largest is:";
	for(int i=0;i<9;i++){
		largest=a[i];
		for(int j=(i+1);j!=i;j++){
		      if(j==9){
			      j=0;
		      }
                      if(largest<a[j]){
                           cout<<a[j]<<" ";
			   cnt++;
			   break;
		      }
		}
		if(cnt==0){
			cout<<"-1"<<" ";
		}
		cnt=0;
	}
	return 0;
}
