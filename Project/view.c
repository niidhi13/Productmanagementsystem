#include "product.h"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_MAGENTA "\x1b[33m"
// printf("%-20s   |   %-20s  |    %-20s  |   %-20s    |\n","ID","PRODUCT NAME","PRICE","QUANTITY");

void viewproduct()
{
    printf(ANSI_COLOR_RESET);
    FILE *ptr = fopen("storage.bin", "rb");
    product vp;
    printf("----------------------------------------------------------------------------------------------------------\n");
    printf("\x1b[32m%-20s   |   %-20s  |    %-20s  |   %-20s        |\n", "ID", "PRODUCT NAME", "PRICE", "QUANTITY\x1b[0m");
    printf("----------------------------------------------------------------------------------------------------------\n");
    while (fread(&vp, sizeof(product), 1, ptr))
    {
        printf(ANSI_COLOR_MAGENTA);
        printf("%-20d   |   %-20s  |    %-20f  |    %-20d   | \n", vp.id, vp.name, vp.price, vp.quantity);
    }
    fclose(ptr);

    char ch;
    printf("\nPress enter to continue.... else press any key .....");
    scanf("%c", &ch);
    printf(ANSI_COLOR_RESET);
}