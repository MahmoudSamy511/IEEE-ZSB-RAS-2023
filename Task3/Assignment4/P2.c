#include<stdio.h>
struct database
{
    struct shops
    {
        char *name;
        char *location;
    };
       struct product_info
    {
        int id;
        float price;
        int quantity;
    };
    struct category
    {
        int id_category;
        int products_num;
    };
 
    
} object1;
int main(){
    printf("Size of the parent struct: %d\n",sizeof(struct database));
    printf("Size of the struct{shops}: %d\n",sizeof(struct shops));
    printf("Size of the struct{product_info}: %d\n",sizeof(struct product_info));
    printf("Size of the struct{category}: %d\n",sizeof(struct category));
    
    /*size of union equal to size of largest member so in previous problem the output will be 16 bytes
    but in this problem we use struct instead of union so the cpu take 5 cycles [5*8 = 40 bytes] */



    return 0;
} 

