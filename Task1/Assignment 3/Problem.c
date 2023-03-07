#include<stdio.h>
int main(){
    unsigned int x = -1;
    printf("Unsigned Value: %d ===> %u\n",x,x);
    if (x == 2147483649 ){
        printf("Sign Magnitude");
    }
    else if (x == 4294967294){
        printf("1's Complement");

    }
    else if (x == 4294967295){
        printf("2's Complement");

    }



    return 0;
}