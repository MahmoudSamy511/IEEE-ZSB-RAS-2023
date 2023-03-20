#include<stdio.h>
typedef int Int4;
typedef unsigned int unInt4;
typedef short sInt2;
typedef long lInt4;
typedef float Float4;
typedef double Double8;
typedef char Char1;
typedef unsigned char  unChar1;


int main(){

printf("Size of Integar: %d bytes\n",sizeof(Int4));
printf("Size of Short Integar: %d bytes\n",sizeof(sInt2));
printf("Size of Long: %d bytes\n",sizeof(lInt4));
printf("Size of Float: %d bytes\n",sizeof(Float4));
printf("Size of Double: %d bytes\n",sizeof(Double8));
printf("Size of Char: %d bytes\n",sizeof(Char1));
printf("Size of Unsigned Intgar: %d bytes\n",sizeof(unInt4));
printf("Size of Unsigned Char: %d bytes\n",sizeof(unChar1));
return 0;
}