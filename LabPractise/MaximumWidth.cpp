#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int value;
    Node* right;
    Node* left;
};
Node* createNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
Node* create(int x){
    if(x==-1)
       return NULL;
    Node* node=createNode(x);
    cout<<"Enter the value you want to insert for left of"<<node->value<<"(If pressed -1 it exits):";
    cin>>x;
    node->left=create(x);
    cout<<"Enter the value you want to insert for right of"<<node->value<<"(If pressed -1 it exits):";
    cin>>x;
    node->right=create(x);
    return node;
}
void inorder(Node* node){
    if(node==NULL)
       return;
    inorder(node->left);
    cout<<node->value<<" ";
    inorder(node->right);
}
void getMaxWidth(Node* root,int &maxWidth,int &targetLevel){
    queue<Node*> q;
    int level=0,size=0;
    q.push(root);
    while(!q.empty()){
        size=q.size();
        if(size>maxWidth){
            targetLevel=level;
            maxWidth=size;
        }
        for(int i=0;i<size;i++){
            Node* p=q.front();
            q.pop();
            if(p->left)
              q.push(p->left);
            if(p->right)
              q.push(p->right);
        }
        level++;
    }
}
void printMaxWidth(Node* root,int targetLevel){
    queue<Node*> q;
    int size=0,level=0;
    q.push(root);
    while(!q.empty()){
        size=q.size();
        if(level==targetLevel){
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                cout<<node->value<<" ";
            }
            return;
        }
        for(int i=0;i<size;i++){
            Node* node1=q.front();
            q.pop();
            if(node1->left)
               q.push(node1->left);
            if(node1->right)
               q.push(node1->right);
        }
        level++;
    }
}
int main(){
    Node* root=NULL;
    Node* root2=NULL;
    int x;
    int maxWidth=0,targetLevel=0;
    cout<<"Enter the value you want to enter(if enetered -1 it exits):";
    cin>>x;
    root=create(x);
    inorder(root);
    cout<<endl;
    getMaxWidth(root,maxWidth,targetLevel);
    cout<<"The maximum width is:"<<maxWidth;
    cout<<"It is at level:"<<targetLevel;
    cout<<endl;
    printMaxWidth(root,targetLevel);
    return 0;
}