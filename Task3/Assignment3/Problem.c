#include<stdio.h>
struct test
{
    int Id;
    char *name;
    char class_id;
};
struct test1
{
    char *name;
    int Id;
    char class_id;
};
int main(){
    printf("Size of the struct before changing the order :%d\n" ,sizeof(struct test));
    printf("Size of the struct after changing the order:%d" ,sizeof(struct test1));
    /*Computer stores structure using the concept of word boundary.Processor doesn't read 1byte at a time from memory.
    It reads 1 word at a time. my processor is 64 bit so the size of the word is 8 bytes so in the first case cpu will
    take 3 cylcles to read the size [3*8 = 24 bytes] and in the second case cpu will take only 2 cycles [2*8 =16 bytes] */

    return 0;

}