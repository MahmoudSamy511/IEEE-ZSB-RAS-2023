#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int counter = 0;
    char s[1000];
    scanf("%[^\n]", s);
    int frequncy[10]={0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            int digit = s[i] - '0';
            for (int j = 0; s[j] != '\0'; j++)
            {
                int testDigit = s[j] - '0';
                if (testDigit == digit)
                {
                    counter++;
                }
            }
            frequncy[digit] = counter;
            counter = 0;
        }
        else
        {
            counter = 0;
        }
    }
    for (int i = 0; i<10; i++)
    {
        if(frequncy[i]>0)
            printf("%d ", frequncy[i]);
        else
            printf("0 ");
    }
    return 0;
}
