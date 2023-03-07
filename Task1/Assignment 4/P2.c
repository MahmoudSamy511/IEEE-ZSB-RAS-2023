#include<stdio.h>
int main(){

    char text[100];
    printf("Enter a String: ");
    gets(text);
    for(int i=0 ; text[i] != '\0' ;i++){
        printf("[%c] ",text[i]);
    }

    return 0;
}