#include <stdio.h>
#include <stdlib.h>

void name()
{
   static char str_name[20];
   printf("\t\t\t Welcome to Number Shifting Game \n\n\n");
    printf("Player Name : ");
    fgets(str_name,20,stdin);


}

