#include<iostream>
using namespace std;
int b=1,n=5;
struct Node{	
	int value;
	Node* addr;
};
Node *head=NULL;
//Node *tail=NULL;
void enqueue(int k){
	Node *temp;
	Node *temp1;
	if(head==NULL){
              temp=new Node;
	      head=temp;
	      temp->value=k;
	      temp->addr=NULL;
	      ++b;
	      return;
	}
	else if(b==n){
		cout<<"queue is full";
		return ;
	}
	else{
		temp=new Node;
		temp1=new Node;
		temp=head;
		temp1->value=k;
		while(temp->addr!=NULL){
			temp=temp->addr;
		}
			       temp->addr=temp1;
				temp1->addr=NULL;
				//cout<<"a";
				++b;
				return;
			}
}
void display(){
	Node *temp1;
	temp1=new Node;
	temp1=head;
	while(temp1!=NULL){
              cout<<temp1->value<<" ";
	      temp1=temp1->addr;
	}
}
void dequeue(){
        Node *temp;
        temp=new Node;
        temp=head;
	if(head==NULL){
		cout<<"there is bothing to delete";
		return;
	}
	else if(temp->addr==NULL){
		head=NULL;
		return;
	}
	else{
		if(b==1){
			head==NULL;
		        return;
		}
		else{
			temp=head;
			temp=temp->addr;
			head=temp;
			return;
		}
	}
}
int main(){
	int a,k;
	cout<<"\nenter the operation you want to do:1)enqueue(1)\n2)dequeue(2)\n3)display(3)\n4)exit(0):";
	cin>>a;
	while(a==1||a==2||a==3){
		switch(a){
			case 1:cout<<"enter the value you want to insert:";
			       cin>>k;
			       enqueue(k);
			       break;
			 case 2:dequeue();
				break;
			 case 3:display();
				break;
		         default:break;
		}
	cout<<"\nenter the operation you want to do:1)enqueue(1)\n2)dequeue(2)\n3)display(3)\n4)exit(0):";
	cin>>a;
	}
	cout<<"your final elements are :"<<"\n";
	display();
	return 0;
}

