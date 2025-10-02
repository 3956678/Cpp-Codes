#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    double x=n/2;
    if(n%2==0){
        printf("It is not a prime number.");
        return 0;
    }
    else{
        for(int i=3;i<=x;i++){
            if(i%n==0){
                printf("It is not a prime number.");
                return 0;
            }
        }
    }
    printf("It is a prime number.");
    return 0;
}