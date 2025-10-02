#include <iostream>
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
node* lca(node *r,int p,int q){
      if(r==NULL||r->value==p||r->value==q)
	      return r;
	  node* l=lca(r->left,p,q);
      node* r1=lca(r->right,p,q);
	  if(l==NULL)
	     return r1;
	  else if(r1==NULL)
	     return l;
	  else
	     return r;
}
int main(){
	node* root;
	root=NULL;
	root=create();
	int p,q;
	cout<<"Enter first node value:";
	cin>>p;
	cout<<"Enter second value:";
	cin>>q;
	node* s=lca(root,p,q);
	cout<<"The lowest common ancestor value is:"<<s->value;
	return 0;
}
