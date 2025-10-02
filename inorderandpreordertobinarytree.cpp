#include<iostream>
struct node{
	node* left;
	node* right;
	int value;
}
node* treeconstruct(int *a,int *b,int l,int r){
           for(int i=l;i<r;i++){
		   if(a[i]==
int main(){
	node* root=NULL;
	int n1,n2;
        cout<<"enter the number of elements in preorder:";
	cin>>n1;
       	cout<<"enter the number of elements in inorder:";
	cin>>n2;
	if(n1!=n2){
		cout<<"invalid!try again";
		return 0;
	}
	int a[n1],b[n2];
	for(int i=0;i<n1;i++){
		cout<<"enter:";
		cin>>a[i];
	}
	for(int i=0;i<n2;i++){
		cout<<"enter:";
		cin>>b[i];
	}
	   root=treeconstruct(a,b,0,n1);
}
