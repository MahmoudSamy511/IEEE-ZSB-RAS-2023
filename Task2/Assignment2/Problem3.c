#include "Function.c"
#include <stdio.h>
extern void helloFun(); //importing function from Funtion.c file

void func( void ) {
   static int i = 5; // local static variable 
   i++;
   printf("i == %d \n", i);
}

int main(){
    auto int val1; // by default every local variable is auto

    register int val2 = 5;
    //printf("%p",&val2); 
    //  Error because thats a register variable which stored in CPU not in memory and we cant access his address
    
    helloFun();
    
    func();
    func();


    return 0;

}