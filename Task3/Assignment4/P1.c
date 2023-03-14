#include<stdio.h>
union database
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
    printf("Size of the union: %d\n",sizeof(union database));
    printf("Size of the struct{shops}: %d\n",sizeof(struct shops));
    printf("Size of the struct{product_info}: %d\n",sizeof(struct product_info));
    printf("Size of the struct{category}: %d\n",sizeof(struct category));

    



    return 0;
} 

