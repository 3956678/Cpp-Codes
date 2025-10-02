#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
stack<int> s;
stack<int> p1;
struct node{
       int value;
       node* left;
       node* right;
       int depth=0;
};
node* create(){
	int x;
	node *n=new node();
	cout<<"Enter the data(-1 for no node):";
	cin>>x;
	if(x==-1)
		return 0;
	else{
		n->value=x;
	}
        cout<<"enter the left child of "<<x<<"\n";
	n->left=create();
	cout<<"enter the right child of "<<x<<"\n";
	n->right=create();
	return n;
}
void findDepth(node* r,int depth){
    if(r==NULL)
      return;
    r->depth=depth;
    findDepth(r->left,depth+1);
    findDepth(r->right,depth+1);
}
void inorderdisplay(node *r){
         if(r==NULL)
		 return;
	 else{
		 inorderdisplay(r->left);
		 cout<<r->depth<<" ";
		 inorderdisplay(r->right);
	 }
}
void inorderdisplay1(node *r){
         if(r==NULL)
		 return;
	 else{
		 inorderdisplay1(r->left);
		 p1.push(r->depth);
		 inorderdisplay1(r->right);
	 }
}
int getMaxH(){
          int largest=p1.top();
	  p1.pop();
	  int x1=0;
	  while(!p1.empty()){
                x1=p1.top();
		p1.pop();
		if(x1>largest)
			largest=x1;
	  }
	  return largest;
}
int getw(node* r,int i){
    stack<node*> a;
    node* p=r;
    int done=0,x=0;
    while(done!=1){
       if(p!=NULL){
          a.push(p);
          p=p->left;
       }
       else{
           if(!a.empty()){
                           p=a.top();
                           if(p->depth==i)
                                 x++;
               a.pop();
               p=p->right;
           }
                   else
               done=1;
       }
    }
    return x;
}
int maxw(node* r){
    int x1=0,x2=0,x3=0;
    int l=getMaxH();
    cout<<"the height is:"<<l;
    for(int i=1;i<=l;i++){
       x2=getw(r,i);
       if(x2>x1){
         x1=x2;
         x3=i;
       }
    }
    return x3;  
}
void maxw1(node *r){
    int h=maxw(r);
    stack<node*> a;
    node* p=r;
    int done=0;
    while(done!=1){
       if(p!=NULL){
          a.push(p);
          p=p->left;
       }
       else{
           if(!a.empty()){
                           p=a.top();
                           if(p->depth==h)
                                cout<<p->depth<<","<<p->value<<endl;
               a.pop();
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
	root=create();
    findDepth(root,0);
	cout<<"inorder display: ";
	inorderdisplay(root);
	cout<<"\n";
	inorderdisplay1(root);
	maxw1(root);
	return 0;
}
