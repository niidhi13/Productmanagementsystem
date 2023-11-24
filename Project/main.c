#include "product.h"
#include "addproduct.c"
#include "delete.c"
#include "view.c"
#include "edit_by_name.c"
#include "search.c"

int main()
{
    
    printf(ANSI_COLOR_CYAN);
    int choice;
    char ch;
    do
    {

        printf("\n\t=============================== Welcome to project management system ================================ \n");
        printf("\n\t|                             1.Add Product                                                          |\n");
        printf("\n\t|                             2.Delete Product                                                       |\n");
        printf("\n\t|                             3.view Product                                                         |\n");
        printf("\n\t|                             4.edit Product                                                         |\n");
        printf("\n\t|                             5.exit                                                                 |\n");
        printf("\n\t|                                                                                                    |\n");
        printf("\n\t===================================================================================================== \n");

        printf("enter your choice:");
        scanf("%d%*c", &choice);

        switch (choice)
        {
        case 1:
            addproduct();
            break;
        case 2:
            deleteproduct();
            break;
        case 3:
            viewproduct();
            break;
        case 4:
            editproduct();
            break;
        case 5:
            printf("Exiting system......\n");
            exit(0);
            break;
        default:
            printf("Invalid Choice !!");
            exit(0);
            break;
        }
        printf("presss Enter to continue.........");
        scanf("%c", &ch);
    } while (ch == '\n');
    return 0;
}
