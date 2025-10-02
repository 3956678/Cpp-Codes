#include<iostream>
#include<algorithm>
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
int nextGreatest(node *r,int v){
        int s=0;
        node* r1=r;
        while(r!=NULL){
           if(r->value>v){
              r=r->left;
              if(r->value!=v)
                 s=r->value;
           }
           else
             r=r->right;
        }
        if(s==0)
           return r1->value;
        return s;
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
int main(){
	node* root;
	root=NULL;
	int val=0,n;
	cout<<"enter the operation you want to do insert(1)  nextGreatest(4)(if entered -1 it exits):";
	cin>>n;
	while(n!=-1){
		switch(n){
	      case 1:cout<<"enter the value you want to insert:";
	                cin>>val;
		        root=create(root,val);
		        break;
          case 4:cout<<"enter the value you want to check:";
                  cin>>val;
                  cout<<"The next greatest is:"<<nextGreatest(root,val);
                  break;
	     default:break;
	}
                     cout<<"enter the operation you want to do insert(1)(if entered -1 it exits):";
	             cin>>n;
  }
	cout<<"inorder display: ";
	inorderdisplay(root);
	return 0;
}
