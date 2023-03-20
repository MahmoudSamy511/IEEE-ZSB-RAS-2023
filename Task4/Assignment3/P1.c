#include<stdio.h>
#define Function Ascending_order
#ifdef Function
void Ascending_order(){
    int arr [5] ,temp;
    for(int i=0;i<5;i++){
        printf("Enter Num %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j =0 ;j<5;j++){
        for(int k = j+1;k<5;k++){
            if (arr[k]<arr[j]){
                temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
            }
        }
    }
    printf("Numbers After Arranging in Ascending order: ");
    for(int i=0;i<5;i++){
        printf("%d, ",arr[i]);
    }
}
void Descending_order(){
    int arr [5] ,temp;
    for(int i=0;i<5;i++){
        printf("Enter Num %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j =0 ;j<5;j++){
        for(int k = j+1;k<5;k++){
            if (arr[k]>arr[j]){
                temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
            }
        }
    }
    printf("Numbers After Arranging in Descending order: ");
    for(int i=0;i<5;i++){
        printf("%d, ",arr[i]);
    }
}
#endif
#ifndef Function
    #warning "Please define the order"
#endif

int main(){
    Function();
    return 0;
}