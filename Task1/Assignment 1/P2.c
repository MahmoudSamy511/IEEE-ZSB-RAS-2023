#include<stdio.h>
int main(){
    int i,j;
    int arr[]={2,5,1,10,2,6,5,10};
    int length= sizeof(arr)/sizeof(arr[0]);
    printf("Unique elments : \n");
    for(i =0 ;i<length;i++){
        int Duplicate = 0;
        for(j=0;j<length;j++){
            if (arr[i] == arr[j] && i!=j){
                Duplicate = 1;
            }
        }
        if (Duplicate == 0) printf("%d \n",arr[i]);
    }
    return 0;
}