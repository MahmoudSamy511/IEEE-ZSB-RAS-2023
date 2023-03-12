#include<stdio.h>
int main(){
    int x = 0x3E2;
    int * ptr ;
    ptr = &x;
    printf("%p\n",ptr);
    printf("%d\n",*ptr++); //use the value of p then moves to next position
    printf("%d\n",*++ptr);  //moves to the next int location then use that value
    printf("%d\n",++*ptr);  // increments the value by 1 then use it
  
    return 0;
}