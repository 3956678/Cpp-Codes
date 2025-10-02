#include<iostream>
using namespace std;
struct node{
    node* a[26]={NULL};
    bool ew=false;
};
node* createNode(){
    node* root=new node();
    return root;
}
void insert(node* root,string s){
    for(char c:s){
        c=tolower(c);
        int idx=c-'a';
        if(root->a[idx]==NULL){
            root->a[idx]=createNode();
        }
        root=root->a[idx];
    }
    root->ew=true;
}
bool search(node* root,string s){
    for(char c:s){
        c=tolower(c);
        int idx=c-'a';
        if(root->a[idx]==NULL){
            return false;
        }
        root=root->a[idx];
    }
    if(root->ew)
       return true;
    return false;
}
bool emptyword(node* root){
    for(int i=0;i<26;i++){
        if(root->a[i]!=NULL)
           return false;
    }
    return true;
}
void deletion(node* root,string s,int i=0){
    if(root==NULL)
      return;
    if(i==(s.length())){
         root->ew=false;
         return;
    }
    char c=tolower(s[i]);
    int idx=c-'a';
    root=root->a[idx];
    deletion(root,s,i+1);
    if(emptyword(root)){
       delete(root);
       return;
    }
    else{
        return;
    }
}
int main(){
    node* root=new node();
    insert(root,"Aditya");
    insert(root,"Hemanth");
    if(search(root,"hemanth")){
        cout<<"Name is present";
    }
    else
        cout<<"Name is not present";
    deletion(root,"Hemanth");
    if(search(root,"hemanth")){
        cout<<"Name is present";
    }
    else
        cout<<"Name is not present";
    return 0;
}