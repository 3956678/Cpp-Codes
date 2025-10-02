#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct Node{
    int value;
    Node* left;
    Node* right;
    int height=0;
};
stack<int> s;
int getHeight(Node* root){
    if(root==NULL)
       return 0;
    return root->height;
}
Node* CreateNode(int value){
    Node* node=new Node();
    node->value=value;
    return node;
}
Node* insert(Node* root,int x){
     if(x==-1)
       return NULL;
     root=CreateNode(x);
     cout<<"Enter the left of "<<root->value<<"if entered -1 it exits:";
     cin>>x;
     root->left=insert(root->left,x);
    cout<<"Enter the right of "<<root->value<<"if entered -1 it exits:";
     cin>>x;
     root->right=insert(root->right,x);
     root->height=max(getHeight(root->left),getHeight(root->right))+1;
     return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
void inorder1(Node* root){
    if(root==NULL){
        return;
    }
    inorder1(root->left);
    s.push(root->value);
    inorder1(root->right);
}
void preorder(Node* root){
    if(root==NULL)
       return;
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL)
       return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
}
void inorderwithoutrecursion(Node* root){
    stack<Node*> s;
    while(root!=NULL||!s.empty()){
        if(root==NULL&&!s.empty()){
            Node* pop=s.top();
            s.pop();
            cout<<pop->value<<" ";
            root=pop->right;
        }
        else{
        s.push(root);
        root=root->left;
        }
    }
}
void preorderwithoutrecursion(Node* root){
    stack<Node*> s;
    while(root!=NULL||!s.empty()){
        if(root==NULL&&!s.empty()){
            Node* pop=s.top();
            s.pop();
            root=pop->right;
        }
        else{
        s.push(root);
        cout<<root->value<<" ";
        root=root->left;
        }
    }
}
void postorderwithoutrecursion(Node* root){
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty()){
        Node* node=s1.top();
        s1.pop();
        s2.push(node);
        if(node->left!=NULL)
           s1.push(node->left);
        if(node->right!=NULL)
           s1.push(node->right);
    }
    while(!s2.empty()){
        Node* pop=s2.top();
        s2.pop();
        cout<<pop->value<<" ";
    }
}
Node* lca(int x,int y,Node* root){
    if(root==NULL||root->value==x||root->value==y){
        return root;
    }
    Node* a=lca(x,y,root->left);
    Node* b=lca(x,y,root->right);
    if(a!=NULL&&b!=NULL)
       return root;
    else if(a==NULL)
       return b;
    else
       return a;
}
int maximumValue(Node* root){
    inorder1(root);
    int max=s.top();
    s.pop();
    while(!s.empty()){
        if(max<s.top())
          max=s.top();
        s.pop();
    }
    return max;
}
int getMaxHeight(Node* root){
    return root->height;
}
int maxDiameter(Node* root,int& diameter){
    if(root==NULL)
       return 0;
    int left=maxDiameter(root->left,diameter);
    int right=maxDiameter(root->right,diameter);
    diameter=max(diameter,left+right+1);
    return 1+max(left,right);
}
int maximumSum(Node* root,int& maxSum){
    if(root==NULL)
      return 0;
    int left=maximumSum(root->left,maxSum);
    int right=maximumSum(root->right,maxSum);
    maxSum=max(maxSum,left+right+root->value);
    return max(left,right)+root->value;
}
Node* mirroredBinaryTree(Node* root){
    if(root==NULL)
       return NULL;
    Node* root2=CreateNode(root->value);
    root2->left=mirroredBinaryTree(root->right);
    root2->right=mirroredBinaryTree(root->left);
    return root2;
}
int maxWidth(Node* root){
    int currentwidth=0,maxwidth=0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        currentwidth=q.size();
        if(currentwidth>maxwidth)
           maxwidth=currentwidth;
        for(int i=0;i<currentwidth;i++){
          Node* pop=q.front();
          q.pop();
          if(pop->left!=NULL)
             q.push(pop->left);
          if(pop->right!=NULL)
             q.push(pop->right);
        }
    }
    return maxwidth;
}
void printMaxWidth(Node* root){
    int targetLevel=maxWidth(root);
    int currentwidth=0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        currentwidth=q.size();
        if(targetLevel==currentwidth){
        for(int i=0;i<currentwidth;i++){
          Node* pop=q.front();
          q.pop();
          cout<<pop->value<<" ";
        }
        return;
      }
        for(int i=0;i<currentwidth;i++){
          Node* pop=q.front();
          q.pop();
          if(pop->left!=NULL)
             q.push(pop->left);
          if(pop->right!=NULL)
             q.push(pop->right);
        }
    }
}
int main(){
   Node* root=NULL;
   int x,diameter=0,maxSum=0;
   cout<<"Enter the value"<<"if entered -1 it exits:";
   cin>>x;
   root=insert(root,x);
   inorder(root);
   cout<<endl;
   preorder(root);
   cout<<endl;
   postorder(root);
   cout<<endl;
   inorderwithoutrecursion(root);
   cout<<endl;
   preorderwithoutrecursion(root);
   cout<<endl;
   postorderwithoutrecursion(root);
   cout<<endl;
   int a,b;
   cout<<"Enter the first value of ancestor:";
   cin>>a;
   cout<<"Enter the second value of ancestor:";
   cin>>b;
   Node* node=lca(a,b,root);
   cout<<"The common ancestor is:"<<node->value<<endl;
   int max=maximumValue(root);
   cout<<"The maximum value is"<<max<<endl;
   int maxHeight=getMaxHeight(root);
   maxDiameter(root,diameter);
   maximumSum(root,maxSum);
   cout<<"The maximum height is:"<<maxHeight<<endl;
   cout<<"The highest diameter is:"<<diameter<<endl;
   cout<<"The maximum path sum is:"<<maxSum<<endl;
   Node* newRoot=mirroredBinaryTree(root);
   cout<<"The mirrored traversal is:";
   inorder(newRoot);
   cout<<endl;
   cout<<"The maximum width is"<<maxWidth(root)<<endl;
   cout<<"the path is:";
   printMaxWidth(root);
   cout<<endl;
   return 0;
}