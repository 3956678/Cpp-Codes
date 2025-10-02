#include<iostream>
using namespace std;
//int s=-1;
#define n 10
//int a[n];
//void push(int);
//int pop();
int main(){
	int n1,n2;
	cout<<"enter your first number:";
	cin>>n1;
	cout<<"enter your second number:";
	cin>>n2;
	int a[10]={0},b[10]={0},c[10]={0};
	int sum=0;
	int d1=0;
	int d2=0;
	int car=0,i=0,j=0;
	for(i;n1!=0;n1/=10)
		a[i++]=n1%10;
	i--;
	for(j;n2!=0;n2/=10)
		b[j++]=n2%10;
	j--;
	int l=max(i,j);
        for(int k=0;k<l;k++){
		/*d1=i%10;
		d2=j%10;
		sum=d1+d2+c;
		c=0;
		if(sum>=10){
			c=sum/10;
			sum=sum%10;
			push(sum);
		}
		else{
			push(sum);
		}
		sum=0;*/
		c[k]=a[k]+b[k]+car;
		car=0;
                if(c[k]>=10&&k<l-1){
			car=c[k]/10;
			c[k]=c[k]%10;
	    }
	}
	//while(s>=0)
		//cout<<pop();
        for(i=l-1;i>=0;i--)
		cout<<c[i];
	return 0;
}
/*void push(int k){
	if(s==-1){
		s=0;
		a[s]=k;
	}
	else{
	s++;
	a[s]=k;
	}
}
int pop(){
	if(s<0){
		cout<<"there are no elements to pop";
		return -1;
	}
	int k=a[s];
	s--;
	return k;
}*/
