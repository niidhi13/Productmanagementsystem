// in linux system do not define #include <window.h>

#ifdef WIN32
#include<windows.h>
#endif
#ifndef PRODUCT
#define PRODUCT
#include<stdio.h>
#include<stdlib.h>

typedef struct product
{
    int id;
    char name[50];
    float price;
    int quantity;
} 
product;
#endif

/* if you include this header file again and again on other files then it will conflict in that files that's why we useed this #ifndef
macro in which it will define the macro if it is not included previously*/

// Note: if you will not add 8th line then this error : we redefinition struct product will occur.

