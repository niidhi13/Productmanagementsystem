#include<stdio.h>
int main()
{
    char text[4000]="\
         |      | \n\r\
         ||     | \n\r\
         |  |   | \n\r\
         |    | | \n\r\
         |      | \n\r\
         \r";
     printf("\x1B[31m%s\033[0m\t\t",text);
     
          return 0;
}