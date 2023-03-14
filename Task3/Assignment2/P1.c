#include<stdio.h>
#include<string.h>
struct Data
{
    char day[30];
    char month[30];
    char year[30];

}date1,date2;
int main(){
    printf("Enter date 1 :");
    scanf("%s %s %s",date1.day,date1.month,date1.year);
    printf("Enter date 2 :");
    scanf("%s %s %s",date2.day,date2.month,date2.year);
    int v1 = strcmp(date1.day,date2.day);
    int v2 = strcmp(date1.month,date2.month);
    int v3 = strcmp(date1.year,date2.year);
    if (v1 == 0 && v2 == 0 && v3 == 0)
        printf("Dates are equal");
    else
        printf("Dates are not equal");

    return 0;
}