#include<iostream>
using namespace std;
struct Node{
    Node* a[26];
    bool ew;
};
void insert(Node* node,string k){
    Node* b=node;
     for(int i=0;i<k.length();i++){
        int idx=k[i]-'a';
        if(b->a[idx]==NULL){
            Node* r=new Node();
            b->a[idx]=r; 
        }
        if(i==k.length()-1){
            b->ew=true;
        }
        b=b->a[idx];
     }
}
void Search(Node* node,string k){
    for(int i=0;i<k.length();i++){
        int idx=k[i]-'a';
        if(node->a[idx]==NULL){
            cout<<k<<" "<<"is not present"<<endl;
            return;
        }
        if(i==k.length()-1){
            if(node->ew==false){
                cout<<k<<" "<<"is not present"<<endl;
                return;
            }
        }
        node=node->a[idx];
    }
    cout<<k<<" "<<"is present"<<endl;
    return;
}
bool isEmpty(Node* node){
    for(int i=0;i<26;i++){
        if(node->a[i]!=NULL)
            return false;
    }
    return true;
}
Node* deletion(Node* node,string k,int depth){
    if(node==NULL)
        return NULL;
    if(depth==k.length()-1){
        node->ew=false;
        if(isEmpty(node)){
            delete node;
             return NULL;
        }
        return node;
    }
     int idx=k[depth]-'a';
    node->a[idx]=deletion(node->a[idx],k,depth+1);
    if(isEmpty(node)&&node->ew==false){
        delete node;
        return NULL;
    }
    return node;
}
int main(){
    Node* root=new Node();
    insert(root,"Aditya");
    insert(root,"Keerthan");
    Search(root,"Keerthan");
    Search(root,"Hemanth");
    deletion(root,"Keerthan",0);
    Search(root,"Keerthan");
}