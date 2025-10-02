#include<iostream>
using namespace std;
char a[20];
int top=-1;
void push(char x){
      a[++top]=x;
}
void pop(){
	if(top==-1){
		return;
	}
	cout<<a[top];
	top--;
	return;
}
int priorityorder(char x){
	if(x=='*'||x=='/')
		return 2;
	if(x=='+'||x=='-')
		return 1;
	return 0;
}
int main(){
	char c[20];
	cout<<"enter the infix:";
	cin>>c;
	char *e;
	e=c;
	while(*e!='\0'){
		if(isalnum(*e))
			cout<<*e;
		else if(*e=='(')
			push(*e);
		else if(*e==')'){
                        while(top!=-1&&a[top]!='(')
				  pop();
			top--;
		}
                else{
			while(top!=-1&&priorityorder(a[top])>=priorityorder(*e))
				pop();
		 push(*e);
		}
		e++;
	}
	while(top!=-1)
		pop();
	return 0;
}

