#include<iostream>
using namespace std;
int b=0;
class Node{
	public:	
	int value;
	Node* addr;
	Node(int value){
		this->value=value;
		addr=NULL;
	}
};
Node *head;
void insertatstart(int k){
	if(head==NULL){
              head=new Node(k);
	      b++;
	}
	else{
		Node *temp=new Node(k);
        	temp->addr=head;
		head=temp;
		b++;
	}
}
void display(){
	Node *temp1;
	temp1=head;
	while(temp1!=NULL){
              cout<<temp1->value<<" ";
	      temp1=temp1->addr;
	}
}
int main(){
	int n,k,a;
        cout<<"enter the operation you want to do 1)insertatstart\n2)display\n3)insertatend\n4)insertatsomeposition\n5)deletion of a node at some index\n6)exit(0):";
	cin>>n;
	while(n==1||n==2||n==3||n==4||n==5){
		switch(n){
			case 1:cout<<"enter the value you want to insert:";
		               cin>>k;
		               insertatstart(k);
			       break;
		        case 2:display();
			       break;
			case 3:cout<<"enter the value you want to insert:";
			       cin>>k;
			       break;
                       case 4:cout<<"enter the value you want to insert:";
			      cin>>k;
			      cout<<"enter the position at which you want to insert:";
			      cin>>a;
			      break;
		       case 5:cout<<"enter the index you want to delete:";
			      cin>>a;
			      break;
		      default:break;
		}
			      cout<<"enter the operation you want to do 1)insertatstart\n2)display\n3)insertatend\n4)insertatsomeposition\n5)deletion of a node at some index\n6)exit(0):";
	            cin>>n;	
	}
	cout<<"your final elements are :"<<"\n";
	display();
	return 0;
}
