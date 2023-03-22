#include<stdio.h>
#define Num1 6
#define Num2 2
#define Add(x,y)  x+y
#define Subt(x,y) x-y
#define operation Add 

int main(){
#if (!defined operation || !defined Num1 || !defined Num2)
#warning "check operation or input Values "
#else
printf("The result of operation : %d\n",operation(Num1,Num2));
#endif


    return 0;
}