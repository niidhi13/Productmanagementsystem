#include "product.h"

void deleteproduct()
{
    FILE *fptr, *tempptr;
    char ch;
    product tempprod;
    fptr = fopen("storage.bin", "rb");
    tempptr = fopen("tempstorage.bin", "wb");
    int id, flag = 0;
    printf("Enter product id which you want to delete :");
    scanf("%d", &id);

    while (fread(&tempprod, sizeof(product), 1, fptr))
    {
        if (tempprod.id != id)
        {
            fwrite(&tempprod, sizeof(product), 1, tempptr);
        }

        else
        {
            flag = 1;
        }
    }

    fclose(fptr);
    fclose(tempptr);
    remove("storage.bin");
    rename("tempstorage.bin", "storage.bin");
    if (!flag)
    {
        printf("Product not found !!\n");
    }

    else
    {
        printf("Product deleted successfuly\n");
    }

    scanf("%c", &ch);
}
