#include<stdio.h>
int main(){
    char c;
    char s[30],sen[30];
    scanf("%c",&c);
    scanf(" %s",s);
    scanf(" %[^\n]%*c",sen);

    printf("%c\n",c);
    printf("%s\n",s);
    printf("%s\n",sen);
    

    return 0;
}