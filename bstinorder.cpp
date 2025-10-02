#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
struct node{
       int value;
       node* left=NULL;
       node* right=NULL;
};
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
void inorderwithoutrecursion(node* r){
       stack<node*> s;
       node* p=r;
       int done=0;
       while(done!=1){
	      if(p!=NULL){
		     s.push(p);
		     p=p->left;
	      }
	      else{
		      if(!s.empty()){
                              p=s.top();
			      s.pop();
			      cout<<p->value<<" ";
			      p=p->right;
		      }
                      else
			      done=1;
	      }
       }
}
int main(){
	node* root;
	root=NULL;
	int val=0,n;
	cout<<"enter the operation you want to do insert(1):";
	cin>>n;
	while(n==1){
		switch(n){
	      case 1:cout<<"enter the value you want to insert:";
	                cin>>val;
		        root=create(root,val);
		        break;
	      
	     default:break;
	}
                     cout<<"enter the operation you want to do insert(1):";
	             cin>>n;
       }
	cout<<"inorder display: ";
	inorderdisplay(root);
	cout<<"\n";
	cout<<"inorder display without recurrsion:";
	inorderwithoutrecursion(root);
	cout<<"\n";
	return 0;
}

