#include<stdio.h>
typedef struct student_info{
    unsigned int roll_number : 4;
    unsigned age : 8;
    unsigned marks : 3;
    char *name;
    char *address;
}student;
void stdDisplay(student s[15]){
    printf("Displaying information of Students\n\n");
    for(int i = 0; i<15 ;i++){
        printf("Student %d Roll Number : %d \n",i,s[i].roll_number);
        printf("Student %d Name : %s \n",i,s[i].name);
        printf("Student %d Age : %d\n",i,s[i].age);
        printf("Student %d Mark : %d\n",i,s[i].marks);
        printf("Student %d Address : %s\n",i,s[i].address);
        
        printf("------------------------\n");
    }
}
int main(){
    student s[15];

    s[0].roll_number=0;     //roll_number stored in 4 bits (range from 0 to 15)
    s[0].age=12;            //age stored in 8 bits (range from 0 to 255)
    s[0].marks=4;          //marks stored in 4 bits (range from 0 to 7)
    s[0].name="Ahmed";    // name stored in 8 bytes
    s[0].address="E1";    // address stored in 8 bytes

    s[1].roll_number=1;
    s[1].age=13;
    s[1].marks=5;
    s[1].name="Ali";
    s[1].address="E2";

    s[2].roll_number=2;
    s[2].age=15;
    s[2].marks=5;
    s[2].name="Mahmoud";
    s[2].address="E3";

    s[3].roll_number=3;
    s[3].age=15;
    s[3].marks=5;
    s[3].name="Emad";
    s[3].address="E4";

    s[4].roll_number=4;
    s[4].age=17;
    s[4].marks=6;
    s[4].name="Sayed";
    s[4].address="E5";

    s[5].roll_number=5;
    s[5].age=12;
    s[5].marks=5;
    s[5].name="Mahmoud";
    s[5].address="E1";

    s[6].roll_number=6;
    s[6].age=12;
    s[6].marks=5;
    s[6].name="Mahmoud";
    s[6].address="E1";

    s[7].roll_number=7;
    s[7].age=12;
    s[7].marks=5;
    s[7].name="Mahmoud";
    s[7].address="E1";

    s[8].roll_number=8;
    s[8].age=12;
    s[8].marks=5;
    s[8].name="Mahmoud";
    s[8].address="E1";

    s[9].roll_number=9;
    s[9].age=12;
    s[9].marks=5;
    s[9].name="Mahmoud";
    s[9].address="E1";

    s[10].roll_number=10;
    s[10].age=12;
    s[10].marks=5;
    s[10].name="Mahmoud";
    s[10].address="E1";

    s[11].roll_number=11;
    s[11].age=12;
    s[11].marks=5;
    s[11].name="Mahmoud";
    s[11].address="E1";

    s[12].roll_number=12;
    s[12].age=12;
    s[12].marks=5;
    s[12].name="Mahmoud";
    s[12].address="E1";

    s[13].roll_number=13;
    s[13].age=12;
    s[13].marks=5;
    s[13].name="Mahmoud";
    s[13].address="E1";

    s[14].roll_number=14;
    s[14].age=12;
    s[14].marks=5;
    s[14].name="Mahmoud";
    s[14].address="E15";

    stdDisplay(s);
    printf("Size of struct :%d bytes",sizeof(student));
    /*Size of struct equals to [8+8+8 = 24 bytes]*/

    return 0;
}