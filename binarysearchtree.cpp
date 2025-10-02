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
node *deletion(node *r,int v) {
    if(r==NULL)
	    return r;
    if(v<r->value)
        r->left=deletion(r->left,v);
    else if(v>r->value)
        r->right=deletion(r->right,v);
    else{
	if(r->left==NULL&&r->right==NULL){
	    //node *temp=NULL;
            delete r;
            return NULL;
	}	    
	else if(r->left==NULL&&r->right!=NULL||r->right==NULL&&r->left!=NULL) {
            node *temp=NULL;
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
    return r;
}
node* search(node *r,int v){
	if(r==NULL){
	         cout<<"element is absent"<<"\n";
		return NULL;
	}
	 if(v<r->value)
        r->left=search(r->left,v);
        else if(v>r->value)
        r->right=search(r->right,v);
	/*if(r==NULL){
		 cout<<"element is absent"<<"\n";
		 return r;
	 }*/
	 else if(v==r->value){
		 cout<<"element is present"<<"\n";
		 return r;
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
	cout<<"enter the operation you want to do insert(1) or delete(2) or search(3)(if entered -1 it exits):";
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
	      case 3:cout<<"enter the value you want to search:";
	                cin>>val;
		        root=search(root,val);
			break;
	     default:break;
	}
                     cout<<"enter the operation you want to do insert(1) or delete(2) or search(3)(if entered -1 it exits):";
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
