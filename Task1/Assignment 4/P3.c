#include<stdio.h>
int main(){
    int flag;
    char str1[100] ,str2[100];
    printf("Enter String1: ");
    gets(str1);
    printf("Enter String2: ");
    gets(str2);
    for (int i = 0, j = 0; str1[i] != '\0', str2[j] != '\0'; i++, j++){
        if (str1[i] == str2[j])
        {flag = 1;}
        else
        {flag = 0;}
    }
    if (flag == 0){printf("Both Strings Are Not Equal!");}
    else {printf("Both Strings Are Equal!");}
    return 0;
}