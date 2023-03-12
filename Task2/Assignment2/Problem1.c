#include <stdio.h>
int add(int *num)
{
    return *num + 1;
}
int main()
{
    int x = 6;
    int (*fun_ptr)(int *) = add;
    printf("Number after increment : %d", fun_ptr(&x));

    return 0;
}