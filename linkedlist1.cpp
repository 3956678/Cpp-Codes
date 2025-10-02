#include<iostream>
using namespace std;
int choice=1;
struct node
    {
        int data;
        struct node * next;
    };
struct node *head=0,*newnode=0,*temp=0;
void front()
{
    struct node* newnode = new node;
    cout<<"enter data to be entered ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;   
}
void back()
{
    struct node* newnode = new node;
    cout<<"enter data to be entered ";
    cin>>newnode->data;
    newnode->next=0;    
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void ind()
{
    struct node* newnode = new node;
    int pos=0,i=2;
    cout<<"enter the pos";
    cin>>pos;
     if(pos==1&&head==0){
        cout<<"Linked list not yet created!\n";
        return;
     }
     else{
        if(pos==1){
            cout<<"enter data to be entered ";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;
        }
        else{
        temp=head;
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
    cout<<"enter data to be inserted ";
    cin>>newnode->data;
    newnode->next=temp->next;
    temp->next=newnode;
}
}
}
int frontdel(){
 if(head==NULL){
        cout<<"no ll created\n";
        return 0;
 }
else {

    temp=head;
    head=head->next;
    delete(temp);
}
return 0;
}
        
int backdel(){
 if(head==0){
        cout<<"no ll created\n";
        return 0;
}
   else {
    struct node* prevnode;
    temp=head;
    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    
    }                           //there is some error in this.backdel 
        prevnode->next=0;       // try inserting 1st element and del tht element using del back and then try to print it show error 
                                // fix this..
    delete(temp);               // there were many more errors i fixed them .

}
return 0;
}
        
int del()
{
    struct node *nextnode;
    int pos ,i=1;
    cout<<"enter pos to be deleted ";
    cin>>pos; 
    if(head==0){
        cout<<"no ll created\n";
        return 0;
    }
    if(pos==1){
        temp=head;
         head=temp->next;
         delete temp;
         return 0;
    }
    else {
        temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }

    nextnode=temp->next;
    temp->next=nextnode->next;
    delete(nextnode);

}
return 0;
}
        

void dis() 
{
     temp = head;
    while (temp !=0) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    while(choice!=8)
    {
       
        cout << "Enter 1 to insert at front\n";
        cout << "Enter 2 to insert at back\n";
        cout << "Enter 3 to insert at position\n";
        cout << "Enter 4 to delete at front\n";
        cout << "Enter 5 to delete at back\n";
        cout << "Enter 6 to delete at position\n";
        cout << "Enter 7 to display\n";
        cout << "Enter 8 to exit\n";

        cin>>choice;

        switch (choice)
        {
        case 1:
            front();
            break;

        case 2:
            back();
            break;
        
        case 3:
            ind();
            break;

        case 4:
            frontdel();
            break;

        case 5:
            backdel();
            break;
        
        case 6:
            del();
            break;
        
        case 7:
            dis();
            break;

        case 8:
            cout<<"extited";
            break;

        default:
            break;
        }
    }
    
}
