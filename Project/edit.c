#include "product.h"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void editproduct()
{

    printf(ANSI_COLOR_YELLOW);
    FILE *fptr = fopen("storage.bin", "rb");
    FILE *tempfptr = fopen("tempstorage.bin", "wb");

    int id, flag = 0;
    printf("Enter product ID :");
    scanf("%d%*c", &id);

    product tempstr;

    while (fread(&tempstr, sizeof(product), 1, fptr))
    {
        if (tempstr.id == id)
        {
            printf("Product record found !! ");
            printf("id : %d \n", tempstr.id);
            printf("Name : %s \n", tempstr.name);
            printf("Price : %f \n", tempstr.price);
            printf("Quantity : %d \n", tempstr.quantity);

            printf("================== ENTER NEW RECORD ==================");
            printf("Enter new product ID :");
            scanf("%d%*c", &id);

            printf("Enter product name : ");
            scanf("%[^\n]%*c", &tempstr.name);

            printf("Enter product price : ");
            scanf("%f", &tempstr.price);

            printf("Enter product quantity : ");
            scanf("%d", &tempstr.quantity);

            fwrite(&tempstr, sizeof(product), 1, tempfptr);
            flag = 1;
        }

        else
        {
            fwrite(&tempstr, sizeof(product), 1, tempfptr);
        }
    }

    fclose(fptr);
    fclose(tempfptr);
    remove("storage.bin");
    rename("tempstorage.bin", "storage.bin");

    if (flag == 1)
    {
        printf("Product edit successfully !!\n");
    }

    else
    {
        printf("Product not found !!\n");
    }
    char ch;
    scanf("%c%*c", &ch);
    printf(ANSI_COLOR_RESET);
}
