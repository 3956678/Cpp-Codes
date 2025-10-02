#include<iostream>
#include<algorithm>
using namespace std;
struct node{
       int value;
       node* left=NULL;
       node* right=NULL;
       int height=1;
};
int geth(node *r){
	if(r==NULL)
		return 0;
	else
		return r->height;
}
int BalanceFactor(node *r){
	if(r==NULL)
		return 0;
	else
		return geth(r->left)-geth(r->right);
}
node *rotateRight(node *y) {
    node*x = y->left;
    node*ch = x->right;
    x->right = y;
    y->left = ch;
    y->height = max(geth(y->left),geth(y->right)) + 1;
    x->height = max(geth(x->left),geth(x->right)) + 1;
    return x;
}
node *rotateLeft(node *x) {
    node*y = x->right;
    node*ch = y->left;
    y->left = x;
    x->right =ch;
    x->height = max(geth(x->left),geth(x->right)) + 1;
    y->height = max(geth(y->left),geth(y->right)) + 1;
    return y;
}
node* create(node *r,int v){
      if(r==NULL){
	  node *t=new node();
          t->value=v;
	  return t;
      }
      if(v<r->value)
	   r->left=create(r->left,v);
      else if(v>r->value)
	   r->right=create(r->right,v);
      else
	      return r;
      r->height=1+max(geth(r->left),geth(r->right));
      int balance=(geth(r->left)-geth(r->right));
     if (balance>1&&v<r->left->value)
        return rotateRight(r);
    if (balance<-1&&v>r->right->value)
        return rotateLeft(r);
    if (balance>1&&v>r->left->value){
        r->left = rotateLeft(r->left);
        return rotateRight(r);
    }
    if (balance<-1&&v<r->right->value) {
        r->right = rotateRight(r->right);
        return rotateLeft(r);
    }
    return r;
}
node *deletion(node *r,int v) {
    if(r==NULL)
	    return r;
    if(v<r->value)
        r->left=deletion(r->left,v);
    else if(v>r->value)
        r->right=deletion(r->right,v);
    else{
	if(r->left==NULL&&r->right==NULL){
		delete r;
	        return NULL;
	}
	else if(r->left==NULL&&r->right!=NULL||r->right==NULL&&r->left!=NULL) {
            node *temp;
	    if(r->left==NULL)
		    temp=r->right;
	    else
		    temp=r->left;
            delete r;
            return temp;
        } 
	else{
            node *temp =r->right;
	    while(temp->left!=NULL)
		    temp=temp->left;
            r->value=temp->value;
            r->right=deletion(r->right,temp->value);
        }
    }
    if(r==NULL) 
	    return r;
    r->height=1+max(geth(r->left),geth(r->right));
    int balance=(geth(r->left)-geth(r->right));
    if(balance>1&&BalanceFactor(r->left)>=0) 
	    return rotateRight(r);
    if(balance>1&&BalanceFactor(r->left)<0) {
        r->left=rotateLeft(r->left);
        return rotateRight(r);
    }
    if(balance<-1&&BalanceFactor(r->right)<=0) 
	    return rotateLeft(r);
    if (balance<-1&&BalanceFactor(r->right)>0) {
        r->right=rotateRight(r->right);
        return rotateLeft(r);
    }
    return r;
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
	int val=0,n;
	cout<<"enter the operation you want to do insert(1) or delete(2)(if entered -1 it exits):";
	cin>>n;
	while(n!=-1){
		switch(n){
	      case 1:cout<<"enter the value you want to insert:";
	                cin>>val;
		        root=create(root,val);
		        break;
	      case 2:cout<<"enter the value you want to delete:";
	                cin>>val;
		        root=deletion(root,val);
		        break;
	     default:break;
	}
                     cout<<"enter the operation you want to do insert(1) or delete(2)(if entered -1 it exits):";
	             cin>>n;
       }
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
 
