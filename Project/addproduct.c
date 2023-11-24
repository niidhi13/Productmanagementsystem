#include "product.h"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34m"


void addproduct()
{
     printf(ANSI_COLOR_BLUE);
    product p1;

    FILE *ptr;
    ptr = fopen("storage.bin", "ab");

    printf("\n===============Add New Product=================\n");
    printf("Enter product ID : ");
    scanf("%d%*c", &p1.id);

    printf("Enter product name : ");
    scanf("%[^\n]%*c", &p1.name);

    printf("Enter product price : ");
    scanf("%f", &p1.price);

    printf("Enter product quantity : ");
    scanf("%d", &p1.quantity);

    fwrite(&p1, sizeof(product), 1, ptr);

    fclose(ptr);
    printf("Product added sucessfully\n");
    printf(ANSI_COLOR_RESET);
}