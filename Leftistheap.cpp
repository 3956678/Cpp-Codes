#include <iostream>
using namespace std;
struct Node {
    int val;
    int s;
    Node* l;
    Node* r;
};
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->val = key;
    newNode->s = 1;
    newNode->l = newNode->r = nullptr;
    return newNode;
}
int gets(Node* node){
    if(node==NULL)
       return 0;
    else
       return node->s;
}
Node* merge(Node* h1, Node* h2) {
    if(h1==NULL) 
        return h2;
    if(h2==NULL) 
        return h1;
    if(h1->val<h2->val)
        swap(h1, h2);
    h1->r= merge(h1->r,h2);
    int sl=gets(h1->l);
    int sr=gets(h1->r);
    if(sr>sl)
        swap(h1->l,h1->r);
    h1->s=gets(h1->r)+1;
    return h1;
}
Node* insert(Node* root, int key) {
    Node* newNode = createNode(key);
    return merge(root, newNode);
}
Node* deletem(Node* root, int* val) {
    if(root==NULL) {
        cout<< "Heap is empty!\n";
        return NULL;
    }
    *val = root->val;
    Node* newRoot = merge(root->l,root->r);
    free(root);
    return newRoot;
}
void inorder(Node* root) {
    if(root==NULL)
     return;
    inorder(root->l);
    cout<< root->val<< " ";
    inorder(root->r);
}
void printHeap(Node* root) {
    cout<< "Heap elements (inorder): ";
    inorder(root);
    cout << "\n";
}
int main() {
    Node* root = nullptr;
    root=insert(root, 10);
    root=insert(root, 20);
    root=insert(root, 5);
    root=insert(root, 30);
    root=insert(root, 2);
    printHeap(root); 
    int val;
    root=deletem(root, &val);
    cout<< "Deleted max: " << val << "\n";
    printHeap(root); 
    return 0;
}