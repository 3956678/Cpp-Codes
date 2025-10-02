#include<stdio.h>
int main(){
    int n;
    printf("Enter the number");
    scanf("%d",&n);
    printf("Your odd numbers below the given number are:");
    int i=1;
    do{
        printf("%d ",i);
        i+=2;
    }while(i<=n);
    printf("\n");
    return 0;
}