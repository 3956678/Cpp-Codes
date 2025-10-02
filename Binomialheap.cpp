#include<iostream>
using namespace std;
struct b{
    int v;
    int d;
    b* p;
    b* l;
    b* s;
};
//b* root=NULL;
b* create(int s){
    b* x=new b();
    x->v=s;
    x->d=0;
    x->p=x->l=x->s=NULL;
    return x;
}
b* mergetree(b*a1,b*a2){
    if(a1->v>a2->v)
       swap(a1,a2);
    a2->p=a1;
    a2->s=a1->l;
    a1->l=a2;
    a1->d++;
    return a1;
}
b* merge(b* a1,b* a2){
    if(a1==NULL)
      return a2;
    if(a2==NULL)
       return a1;
    if(a1->d<=a2->d){
        a1->s=merge(a1->s,a2);
        return a1;
    }
    else{
        a2->s=merge(a1,a2->s);
        return a2;
    }
}
b* mergeheap(b* a1,b* a2){
    b* m=merge(a1,a2);
    if(m==NULL)
       return NULL;
    b* prev;
    b* next;
    b* cur;
    cur=m;
    next=m->s;
    prev=NULL;
    while(next!=NULL){
        if(cur->d!=next->d||next->s!=NULL&&next->s->d==cur->d){
            prev=cur;
            cur=next;
        }
        else{
            if(cur->v<=next->v){
                cur->s=next->s;
                cur=mergetree(cur,next);
            }
            else{
                if(prev==NULL)
                  m=next;
                else
                    prev->s=next;
                    next=mergetree(next,cur);
                    cur=next;
            }
        }
        next=cur->s;
    }
    return m;
}
b* insert(b* r,int s){
     b*n=create(s);
     return mergeheap(r,n);
}
void displayTree(b* n){
    if(n==NULL)
      return;
    displayTree(n->l);
        cout<<n->v<<" ";
    displayTree(n->s);
}
/*b* reverse(b*prev,b* s){
    b*root=NULL;
    b* temp=prev;
    if(s->s==NULL){
        root=s;
        root->s=temp;
        return root;
    }
   else{
    root=reverse(s,s->s);
    s->s=prev;
   }
    return root;
}
void extractMin(b* s){
    b* w=s;
    b* w1=s;
    b* w2=s;
    while(w!=NULL){
       w=w->s;
       if(w1->v>w->v)
         w1=w;
    }
    w->s=w1->s;
    w2=w1->l;
    b* newHeap=reverse(NULL,w2);
    mergeheap(s,newHeap);
    delete w1;
}*/
int main(){
    b* root=NULL;
    root=insert(root,12);
    //root=insert(root,6);
    root=insert(root,7);
    //root=insert(root,8);
    root=insert(root,25);
    //extractMin(root);
    displayTree(root);
}