#include<stdio.h>
struct student_info
{
    char name[50];
    char address[50];
    int age;
    int roll_number;
    float mark;
}s[15];

int main(){
    for(int i = 1; i<16 ;i++){
        printf("Enter Student %d Roll Number : ",i);
        scanf("%d",&s[i].roll_number);
        printf("Enter Student %d Name : ",i);
        scanf("%s",s[i].name);
        printf("Enter Student %d Age : ",i);
        scanf("%d",&s[i].age);
        printf("Enter Student %d Address : ",i);
        scanf("%s",s[i].address);
        printf("Enter Student %d Mark : ",i);
        scanf("%f",&s[i].mark);
        printf("------------------------\n");
    }
    printf("Displaying information of Students\n\n");
    for(int i = 1; i<16 ;i++){
        printf("Student %d Roll Number : %d \n",i,s[i].roll_number);
        printf("Student %d Name : %s \n",i,s[i].name);
        printf("Student %d Age : %d\n",i,s[i].age);
        printf("Student %d Address : %s\n",i,s[i].address);
        printf("Student %d Mark : %0.1f\n",i,s[i].mark);
        printf("------------------------\n");
    }
    return 0;
}