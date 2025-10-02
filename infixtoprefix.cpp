#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[20];
int top=-1;
void push(char x){
      a[++top]=x;
}
char pop(){
	if(top==-1){
		return '\0';
	}
	char c;
	c=a[top];
	top--;
	return c;
}
int priorityorder(char x){
	if(x==')'||x=='(')
		return 0;
	if(x=='*'||x=='/')
		return 2;
	if(x=='+'||x=='-')
		return 1;
	return 0;
}
/*void strrev(char c[]){
	int count=0;
	while(c[count]!='\0'){
		count++;
	}
	int s=0;
	int e=count-1;
	while(s<e){
		char t=c[s];
		c[s]=c[e];
		c[e]=t;
		s++;
		e--;
	}
}*/
int main(){
	char c[20],b[20];
	cout<<"enter the infix:";
	cin>>c;
        //strrev(c);
	char *e=c;
	int i=0;
	reverse(c,c+strlen(c));
	e=c;
	while(*e!='\0'){
		if(isalnum(*e))
			b[i++]=*e;
		else if(*e==')')
			push(*e);
		else if(*e=='('){
                        while(top!=-1&&a[top]!=')'){
				  b[i++]=pop();
			}
			top--;
		}
                else{
			while(top!=-1&&priorityorder(a[top])>priorityorder(*e))
				b[i++]=pop();
		 push(*e);
		}
		e++;
	}
	while(top!=-1)
		b[i++]=pop();
	b[i]='\0';
	reverse(b,b+strlen(b));
	//strrev(b);
	for(int i=0;b[i]!='\0';i++)
	cout<<b[i];
	return 0;
}
