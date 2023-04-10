#include<stdio.h>
#include<stdlib.h>
#define n1 5
#define n2 5
#define n3 10
int main(){
    // allocate memory using malloc
int *ptr1 = (int*) malloc(n1 * sizeof(int));
if (ptr1 == NULL) {
    printf("Memory allocation failed for ptr1\n");
} else {
    printf("Memory allocation successful for ptr1\n");
    // assign values to memory block
    for (int i = 0; i < n1; i++) {
        ptr1[i] = i + 1;
    }
    // print values of memory block
    printf("Values of ptr1: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
}

// allocate memory using calloc
int *ptr2 = (int*) calloc(n2, sizeof(int));
if (ptr2 == NULL) {
    printf("Memory allocation failed for ptr2\n");
} else {
    printf("Memory allocation successful for ptr2\n");
    // assign values to memory block
    for (int i = 0; i < n2; i++) {
        ptr2[i] = i * 2;
    }
    // print values of memory block
    printf("Values of ptr2: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");
}
free(ptr1);
// allocate fourth space
int *ptr3 = (int*) malloc(n3 * sizeof(int));
if(ptr3 == NULL){
    printf("Memory allocation failed for ptr3\n");
}
else{
    printf("Memory allocation successful for ptr3\n");
    // assign values to memory block
    for (int i=0; i<n3; i++){
    ptr3[i]= 5 * i;
}
// print values of memory block
printf("Values of ptr3: ");
for (int i=0; i<n3; i++){
    printf("%d ",ptr3[i]);
}
}
free(ptr2);
free(ptr3);
return 0;
// if we had limited space in memory that lead to have overflow on stack in memory.



   
}