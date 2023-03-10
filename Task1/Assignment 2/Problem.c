#include<stdio.h>
int main(){
    int x =5 , y=6 , z=7;
    int*p=&x ,*q=&y ,*r=&z;
    int *temp1 ;
    printf("x= %d\ny= %d\nz= %d\n-------------------\n",x,y,z);
    printf("p= %p\nq= %p\nr= %p\n-------------------\n",p,q,r);
    printf("*p= %d\n*q= %d\n*r= %d\n----------------\n",*p,*q,*r);
    printf("Swapping pointers\n-----------------\n");
    temp1 = p;
    p= q;
    q= r;
    r= temp1;
    printf("x= %d\ny= %d\nz= %d\n-------------------\n",x,y,z);
    printf("p= %p\nq= %p\nr= %p\n-------------------\n",p,q,r);
    printf("*p= %d\n*q= %d\n*r= %d\n-----------------\n",*p,*q,*r);
    return 0;
}