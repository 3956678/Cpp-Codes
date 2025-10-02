#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
stack<int> s;
stack<int> p;
struct node{
       int value;
       node* left;
       node* right;
       int height=1;
};
int getHeight(node *r){
	if(r==NULL)
		return 0;
	else
		return r->height;
}
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
	n->height=1+max(getHeight(n->left),getHeight(n->right));
	return n;
}
void inorderdisplay(node *r){
         if(r==NULL)
		 return;
	 else{
		 inorderdisplay(r->left);
		 s.push(r->value);
		 cout<<r->value<<" ";
		 inorderdisplay(r->right);
	 }
}
void getMax(){
          int largest=s.top();
	  s.pop();
	  int x1=0;
	  while(!s.empty()){
                x1=s.top();
		s.pop();
		if(x1>largest)
			largest=x1;
	  }
	  cout<<"largest value is:"<<largest<<endl;
}
void inorderdisplay1(node *r){
         if(r==NULL)
		 return;
	 else{
		 inorderdisplay1(r->left);
		 p.push(r->height);
		 inorderdisplay1(r->right);
	 }
}
void getMaxH(){
          int largest=p.top();
	  p.pop();
	  int x1=0;
	  while(!p.empty()){
                x1=p.top();
		p.pop();
		if(x1>largest)
			largest=x1;
	  }
	  cout<<"the depth is:"<<largest<<endl;
}
int main(){
	node* root;
	root=NULL;
	root=create();
	cout<<"inorder display: ";
	inorderdisplay(root);
	cout<<"\n";
	getMax();
	inorderdisplay1(root);
	getMaxH();
        cout<<"the depth is:"<<root->height<<endl;
	return 0;
}

