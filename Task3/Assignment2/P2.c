#include<stdio.h>
struct info
{
    char *name;
    int age;
};
int main(){
    struct info person1 = {"Mahmoud Samy",21};
    struct info *ptr =&person1;
    printf("Name : %s\nAge : %d",ptr->name,ptr->age);

    return 0 ;
}