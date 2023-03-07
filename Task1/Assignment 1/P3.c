#include<stdio.h>
void freq(int arr[],int x){
    int fr[x];  
    int visited = -1;  
    for(int i =0 ;i<x;i++){
        int count = 1;
        for(int j=i+1;j<x;j++){
            if (arr[i] == arr[j] ){
                count++;
                fr[j] = visited;  
            }
        }
         if(fr[i] != visited)  
            fr[i] = count;  
    }  
    for(int i = 0; i < x; i++){  
        if(fr[i] != visited){  
            printf(" Element : %d  | Frequency: %d\n", arr[i],fr[i]);   
        }  
    }  
}
int main(){
    int s;
    printf("Enter number of elements: ");
    scanf("%d",&s);
    int arr[s];
    for (int i =0 ;i<s;i++){
        scanf("%d",&arr[i]);
    }
    freq(arr,s);
    return 0;
}