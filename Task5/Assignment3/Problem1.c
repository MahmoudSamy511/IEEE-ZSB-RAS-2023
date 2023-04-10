#include<stdio.h>
#define my_sizeof1(type) (char *)(&type+1)-(char *)(&type)

static inline int my_sizeof2(int type){
    return (char *)(&type+1)-(char *)(&type);
}
int main(){
    int x1,x2;
    printf("The size of variable using macros: %d bytes\n",my_sizeof1(x1));
    printf("The size of variable using inline function: %d bytes\n",my_sizeof2(x2));

    return 0;}
    /*The main difference between macro and inline implementation of sizeof() 
    is that macros are preprocessor directives[pure text replacment] that are replaced with the actual 
    code during compilation, whereas inline functions are actual functions 
    that are inserted into the code during compilation.
    #Regular function# : 
    there is type checking and executed in [compiler] and have more execution time 
    compared to Function like macros.
    #Macros function# : 
    there is no type checking and executed in [preprocessor] and have the lowest execution time
    #Inline function# : 
    there is type checking and executed in [compiler] and execution time 
    greater than regular function and lower than macros
    In general, it is best to use inline functions when we need to 
    perform more complex operations and macros when we need to perform simple operations.
*/