#include<iostream>
using namespace std;
struct node{
	int value;
	node* next=NULL;
};
node* newnode(){
      node* newnode=new node();
      return newnode;
}
node* head=NULL;
void insertionatbegining(int k){
	node* temp;
	node* last;
	if(head==NULL){
            	temp=newnode();
	        temp->value=k;
	        head=temp;
		temp->next=temp;
	}
        else{
	  last=head;
	  while(last->next!=head)
		  last=last->next;
	  temp=newnode();
          temp->value=k;
          temp->next=head;
	  head=temp;
	  last->next=temp;
	}
}
void insertatend(int k){
	node*temp1=newnode();
        temp1->value=k;
	node* temp=head;
	if(temp->next==temp){
              temp->next=temp1;
	      temp1->next=temp;
	}
	else{
	   while(temp->next!=head){
		   temp=temp->next;
	   }
	   temp->next=temp1;
	   temp1->next=head;
	}
}
void insertionati(int a,int k){
	node* temp=head;
	node* temp1=newnode();
	temp1->value=k;
	if(a==1){
		insertionatbegining(k);
	}
	else{
		int i=1;
		while(i<(a-1)&&temp->next!=head){
			temp=temp->next;
		        i++;
		}
		temp1->next=temp->next;
		temp->next=temp1;
	}
}
void deletion(int a){
	node* temp=head;
	node* temp1=head;
	if(temp->next==temp){
		head=NULL;
		delete temp;
	}
	else{
		int i=1;
		while(i<(a+1)){
			temp=temp->next;
			temp1=temp;
			if(i==a){
				if(temp->next==head){
					temp1->next=head;
					delete temp;
				}
				else{
                                        temp1->next=temp->next;
					delete temp;
				}
			}
			i++;
		}
	}
}
node* reverseRecursive(node* current, node* prev) {
    if (current->next == head) {
        head = current;
        current->next = prev;
        return current; 
    }
    node* newHead = reverseRecursive(current->next, current);
    current->next = prev;
    return newHead;
}
void reverseLinkedList(){
	if(head==NULL||head->next==head)
		return;
	node* last=head;
	while(last->next!=head)
		last=last->next;
	head=reverseRecursive(head,head);
	last->next=head;
}
void display(){
	node* temp=head;
	cout<<"the values are:";
	while(temp->next!=head){
		cout<<temp->value<<" ";
		temp=temp->next;
	}
	cout<<temp->value<<" "<<endl;
}
int main(){
	int n,k,a;
        cout<<"enter the operation you want to do 1)insertatstart\n2)display\n3)insertatend\n4)insertatsomeposition\n5)deletion of a node at some index\n6)exit(0) 7)reverselinkedlist(7):";
	cin>>n;
	while(n==1||n==2||n==3||n==4||n==5||n==7){
		switch(n){
			case 1:cout<<"enter the value you want to insert:";
		               cin>>k;
		               insertionatbegining(k);
			       break;
		        case 2:display();
			       break;
			case 3:cout<<"enter the value you want to insert:";
			       cin>>k;
			       insertatend(k);
			       break;
                       case 4:cout<<"enter the value you want to insert:";
			      cin>>k;
			      cout<<"enter the position at which you want to insert:";
			      cin>>a;
			      insertionati(a,k);
			      break;
		       case 5:cout<<"enter the index you want to delete:";
			      cin>>a;
			      deletion(a);
			      break;
		       case 7:reverseLinkedList();
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
