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

// allocate memory using realloc
int *ptr3 = (int*) realloc(ptr1, n3 * sizeof(int));
if (ptr3 == NULL) {
    printf("Memory reallocation failed for ptr1\n");
} else {
    printf("Memory reallocation successful for ptr1\n");
    // assign values to memory block
    for (int i = n1; i < n3; i++) {
        ptr3[i] = i * 3;
    }
    // print values of memory block
    printf("Values of ptr3: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");
}

// free allocated memory
free(ptr2);
free(ptr3);
return 0;




   
}