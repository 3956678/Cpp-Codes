#include<iostream>
using namespace std;
int main(){
	int a[7];
	for(int i=0;i<7;i++){
		cout<<"enter your "<<i+1<<"element:";
		cin>>a[i];
	}
	int k;
	cout<<"enter length of sliding window:";
	cin>>k;
	cout<<"initial elements are:";
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	int largest=0,cnt=1;
	cout<<"the maximum values are:";
	for(int i=0;i<7;i++){
		largest=a[i];
		for(int j=(i+1);cnt<=3&&j<7;j++,cnt++){
                      if(largest<a[j]){
                           largest=a[j];
		      }
		      cnt++;
		}
		if(i>7-k)
			break;
		cout<<largest<<" ";
		cnt=1;
	}
	return 0;
}

