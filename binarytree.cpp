#include<iostream>
using namespace std;
struct node{
       int value;
       node* left;
       node* right;
};
node* create(){
	int x;
	node *n=new node();
	cout<<"Enter the data(-1 for no node):";
	cin>>x;
	if(x==-1)
		return 0;
	else
		n->value=x;
        cout<<"enter the left child of "<<x<<"\n";
	n->left=create();
	cout<<"enter the right child of "<<x<<"\n";
	n->right=create();
	return n;
}
void inorderdisplay(node *r){
         if(r==NULL)
		 return;
	 else{
		 inorderdisplay(r->left);
		 cout<<r->value<<" ";
		 inorderdisplay(r->right);
	 }
}
void postorderdisplay(node *r){
	if(r==NULL)
		return;
	else{
		postorderdisplay(r->left);
		postorderdisplay(r->right);
                cout<<r->value<<" ";
	}
}
void preorderdisplay(node *r){
	if(r==NULL)
		return;
	else{
		cout<<r->value<<" ";
		preorderdisplay(r->left);
		preorderdisplay(r->right);
	}
}
int main(){
	node* root;
	root=NULL;
	root=create();
	cout<<"inorder display: ";
	inorderdisplay(root);
	cout<<"\n";
	cout<<"preorder display: ";
	preorderdisplay(root);
	cout<<"\n";
	cout<<"postorder display: ";
	postorderdisplay(root);
	cout<<"\n";
	return 0;
}
