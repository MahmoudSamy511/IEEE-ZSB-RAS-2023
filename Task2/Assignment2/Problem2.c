#include <stdio.h>
int main()
{
    int arr[] = {1,5,7,4,9};
    int *p = &arr[0];
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i =0;i<len;i++){
        printf(" Element of index [%d] = %d\n",i,*(p+i));
    }
    

    return 0;
}