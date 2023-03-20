#include<stdio.h>
#define Num1 4
#define Num2 2
#define Add(x,y)  x+y
#define Subt(x,y) x-y
#define operation Add
#if (!defined operation || !defined Num1 || !defined Num2)
#warning "check operation or input Values "
#endif
int main(){

printf("The result of operation : %d\n",operation(Num1,Num2));


    return 0;
}