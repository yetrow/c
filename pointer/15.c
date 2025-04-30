//多级指针设计
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id;
    float price;
    const char* manufacturer;
}Product;

Product* create_product(int id,float price,const char* manufacturer);
const char* get_manu(Product** produt);
// void print_pro(const Product* product);
// void update_by_wholesaler(Product* product,int new_id,float new_price);
// void update_by_retailer(Product* product,int new_id,float new_price);


int main(void)
{
    Product *product1=create_product(1,10.0,"frank's enterprise");
    printf("product id is:%d,price is:%.2f,manufacturer is:%s\n",\
        product1->id,product1->price,product1->manufacturer);

    //工厂获取产品
    Product* wholesaler_product=product1;
    //零售商获取产品，并联系工厂
    Product** retailer_product=&wholesaler_product;
    printf("product id is:%d,price is:%.2f,manufacturer is:%s\n",\
        (*retailer_product)->id,(*retailer_product)->price,(*retailer_product)->manufacturer);
        printf("product id is:%d,price is:%.2f,manufacturer is:%s\n",\
            (**retailer_product).id,(**retailer_product).price,(**retailer_product).manufacturer);
    

    const char* manufacturer=get_manu(retailer_product);
    printf("get_manufacturer is:%s\n",manufacturer);

    free(product1);

    return 0;
}

Product* create_product(int id,float price,const char* manufacturer)
{
     Product *p=(Product*)malloc(sizeof(Product));
    if(p==NULL)
    {
        perror("failed\n");
        exit(EXIT_FAILURE);
    }
     p->id=id;
     p->price=price;
     p->manufacturer=manufacturer;

     return p;
}

// void print_pro(const Product* product)
// {
//     if(product!=NULL)
//     {
//         printf("product->id:%d\n",product->id);
//         printf("product->price:%.2f\n",product->price);
//         //printf("product->manufacturer:%s\n",product->manufacturer);
//     }
// }

// void update_by_wholesaler(Product* product,int new_id,float new_price)
// {
//     product->id=new_id;
//     product->price=new_price;
// }
// void update_by_retalier(Product* product,int new_id,float new_price)
// {
//     product->id=new_id;
//     product->price=new_price;
// }
const char* get_manu(Product** product)
{
    return(*product)->manufacturer;
}