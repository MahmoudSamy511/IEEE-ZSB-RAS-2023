#include<stdio.h>
#include<stdlib.h>
int main(){
    int MAX_Length;
    printf("Enter Maximum length: ");
    scanf("%d",&MAX_Length);
    char *name =(char*) malloc(MAX_Length * sizeof(char));
    if (name == NULL){ printf("Memory allocation failed for name\n");}
    else{
    printf("Memory allocation successful for name\n");
    printf("Enter your name: ");
    getchar();
    gets(name);
    printf("Your Name: %s\n",name);
    int freq[256] = {0}, max_freq = 0, i;
    for(i = 0; name[i] != '\0'; i++)
    {
        freq[(int)name[i]]++;
    }
    for(i = 0; i < 256; i++)
    {
        if(freq[i] > freq[max_freq])
        {
            max_freq = i;
        }
    }
    printf("The most repeated character is '%c' with frequency %d.\n", max_freq, freq[max_freq]);
    }
    free(name);
    return 0;
}