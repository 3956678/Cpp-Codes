#include<iostream>
using namespace std;
struct node{
    node* a[26]={NULL};
    bool ew=0;
};
void insertion(node *r,string k){
    for(int i=0;i<k.length();i++){
        int idx=k[i]-'a';
        if(r->a[idx]==NULL){
            node* newNode=new node();
            r->a[idx]=newNode;
        }
        if(i==(k.length()-1)){
           r->ew=1;
           return;
        }
        r=r->a[idx];
    }
}
void search(node *r,string k){
      for(int i=0;i<k.length();i++){
        int idx=k[i]-'a';
        if(r->a[idx]==NULL){
            cout<<"Word does not exist";
            break;
        }
        if(i==(k.length())-1){
            if(r->ew==false){
            cout<<"Word does not exist"<<endl;
            break;
            }
            else{
               cout<<"Word does exist"<<endl;
               break;
            }
        }
        r=r->a[idx];
      }
      return;
   }
   bool isEmpty(node* r){
    for(int i=0;i<26;i++){
       if(r->a[i]!=NULL)
          return false;
    }
    return true;
 }
node* deletion(node* r,string k,int depth=0){
    if(r==NULL)
        return NULL;
    if(depth==k.size()){
        if(r->ew)
           r->ew=false;
        if(isEmpty(r)){
            delete r;
            r=NULL;
        }
        return r;
    }
    int idx=k[depth]-'a';
    r->a[idx]=deletion(r->a[idx],k,depth+1);
    if(isEmpty(r)&&r->ew){
        delete r;
        return NULL;
    }
    return r;
}
int main(){
    node* root=new node;
    insertion(root,"Aditya");
    insertion(root,"Keerthan");
    search(root,"Keerthan");
    search(root,"Hemanth");
    deletion(root,"Keethan",0);
    search(root,"Keerthan");
    return 0;
}