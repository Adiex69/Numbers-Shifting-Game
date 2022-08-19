#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void rules()
{
   system("cls");

    printf("\t\t\t\t\t RULES OF THIS GAME\n\n");
    printf("1. You can Move only 1 step at a time by Arrow Key\n\n");
    printf("\t\tMove Up : by Up arrow key\n");
    printf("\t\tMove Down : by Up arrow key\n");
    printf("\t\tMove Left : by Up arrow key\n");
    printf("\t\tMove Right : by Up arrow key\n\n");
    printf("2.You can move at empty position only\n\n");
    printf("3.For each valid move : Your total number of move will decreased by 1\n\n");
    printf("4.Winning Situation : Number in a 4X4 matrix should be in order from 1 to 15\n");
    printf("\t\t\t\t --------------------\n");
    printf("\t\t\t\t| Winning Situation |\n");
    printf("\t\t\t\t --------------------\n");
    printf("-------------------\n");
    printf("1  | 2  | 3  | 4  |\n5  | 6  | 7  | 8  |\n9  | 10 | 11 | 12 |\n13 | 14 | 15 | __ |\n");
    printf("-------------------\n\n");
    printf("\t\tPress Enter to start the NUMBER SHIFTING game :)");



     system("color 4");
     getch();
}
