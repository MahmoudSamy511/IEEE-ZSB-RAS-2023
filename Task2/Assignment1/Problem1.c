#include<stdio.h>
int main(){
    int x = 5;
    char y = 'b';
    long z = 20000;
    int *p1 = &x;
    char *p2 = &y;
    long *p3 = &z;
    printf("%p\n",p1);
    printf("%p\n",p2);
    printf("%p\n",p3);
    printf("--------------------------------\n");
    p1++; // size of int is 4 bytes so next address of p1 increased by 4
    p2++; // size of char is 1 bytes so next address of p2 increased by 1
    p3++; // size of int is 4 bytes so next address of p3 increased by 4
    printf("%p\n",p1);
    printf("%p\n",p2);
    printf("%p\n",p3);
    return 0;
}