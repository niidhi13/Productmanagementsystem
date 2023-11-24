#include "product.h"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

void editproduct()
{

    printf(ANSI_COLOR_YELLOW);
    FILE *fptr = fopen("storage.bin", "rb+");

    int id, flag = 0, size = sizeof(product);
    char name[20];
    product tempstr;

    printf("Enter product NAME :");
    scanf("%[^\n]s%*c", &name);

    while (fread(&tempstr, sizeof(product), 1, fptr) == 1)
    {
        if (strcmp(tempstr.name, name) == 0)
        {
            printf("Product record found !! ");
            printf("id : %d \n", tempstr.id);
            printf("Name : %s \n", tempstr.name);
            printf("Price : %f \n", tempstr.price);
            printf("Quantity : %d \n", tempstr.quantity);

            printf("================== ENTER NEW RECORD ==================");
            printf("Enter new product ID :");
            scanf("%s%*c", &id);

            printf("Enter product name : ");
            scanf("%[^\n]%*c", &tempstr.name);

            printf("Enter product price : ");
            scanf("%f", &tempstr.price);

            printf("Enter product quantity : ");
            scanf("%d", &tempstr.quantity);
            fseek(fptr, -size, 1);

            fwrite(&tempstr, sizeof(product), 1, fptr);
            flag = 1;
            break;
        }
    }
    fclose(fptr);
    if (flag == 1)
        printf("Record Modified.......\n");
    else
        printf("Product not found in file \n");
    printf(ANSI_COLOR_RESET);
}
