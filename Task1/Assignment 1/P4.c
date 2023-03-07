#include<stdio.h>
int addNum(int *n1,int *n2){
    return *n1 + *n2;
}
int main(){
    int num1,num2;
    printf("Enter two number :");
    scanf("%d %d",&num1,&num2);
    printf("The sum of %d and %d == %d",num1,num2,addNum(&num1,&num2));
    return 0 ;
}
