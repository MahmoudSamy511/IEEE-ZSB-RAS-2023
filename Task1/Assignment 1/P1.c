#include<stdio.h>
int main(){
    int i,j;
    int count =0;
    int arr[]={2,3,2,4,2,6,5,10};
    int length= sizeof(arr)/sizeof(arr[0]);
    for(i =0 ;i<length;i++){
        for(j=i+1;j<length;j++){
            if (arr[i] == arr[j]){
                count++;
                break;

            }
        }
    }
    printf("Total duplicate elements in array : %d",count);


    return 0;
}