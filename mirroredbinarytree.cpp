#include<iostream>
using namespace std;
struct node{
       int value;
       node* left;
       node* right;
};
struct node1{
    int value1;
    node1* left1=NULL;
    node1* right1=NULL;
};
node* create(){
	int x;
	node *n=new node();
   // node1* n1=new node1();
	cout<<"Enter the data(-1 for no node):";
	cin>>x;
	if(x==-1)
		return 0;
	else{
		n->value=x;
       // n1->value1=x;
        cout<<"enter the left child of "<<x<<"\n";
	    n->left=create();
	cout<<"enter the right child of "<<x<<"\n";
	n->right=create();
    }
	return n;
}
node1* mirror(node* r){
    if(r==NULL)
       return NULL;
    node1* n=new node1();
    n->value1=r->value;
    n->right1=mirror(r->left);
    n->left1=mirror(r->right);
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
void inorderdisplay1(node1* r){
    if(r==NULL)
      return;
else{
    inorderdisplay1(r->left1);
    cout<<r->value1<<" ";
    inorderdisplay1(r->right1);
}
}
int main(){
	node* root;
	root=NULL;
    node1* root1=NULL;
	root=create();
	cout<<"inorder display: ";
	inorderdisplay(root);
	cout<<"\n";
    cout<<"mirrored binary tree:";
    root1=mirror(root);
    cout<<"it's inorder display is:";
    inorderdisplay1(root1);
	return 0;
}
