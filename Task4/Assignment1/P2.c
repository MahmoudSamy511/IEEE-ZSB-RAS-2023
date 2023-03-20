#include<stdio.h>
typedef struct complex_num{
    int real;
    int imag;

}complex;
void addComplex(complex n1,complex n2){
    int rpart = n1.real + n2.real;
    int ipart = n1.imag + n2.imag;
    complex res = {rpart,ipart};
    if(ipart <0){
        printf("Sum of two complex num : %d - %di ",res.real,-res.imag);

    }else{
        printf("Sum of two complex num : %d + %di ",rpart,ipart);
        
    }
    
}
int main(){
    complex num1 ={10,-5};
    complex num2 ={5,-1};
    addComplex(num1,num2);



    return 0;
}