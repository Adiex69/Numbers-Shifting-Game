#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>
void name();
void rules();
int main()
{
    name();
    rules();
    system("cls");
    system ("color 7");
   int used=0, left=200;
    int sudo_arr[4][4] = {{0}};
    randArrGen(sudo_arr);
    printf("\t\t\t\tPress n/N to terminate the game.\n\n");
    Display(sudo_arr, used,left);
    char ch1, ch2, till;

    int posZeroI = 3;
    int posZeroJ = 3;

    while(left) {
        fflush(stdin);
        ch1 = getch();//first getch for 0 and -32 in windows10 cmd 32bit.
        if(ch1==0 || ch1== -32) {
            ch2 = getch();// second getch for arrow value.
            if(ch2 == 72 && posZeroI > 0) { //"UP")
                sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI - 1][posZeroJ];
                sudo_arr[posZeroI - 1][posZeroJ] = 0;
                posZeroI -= 1;
                used++;
                left--;
                Display(sudo_arr,used,left);
            }
            else if(ch2 == 80 && posZeroI <3) {//printf("DOWN");
                sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI + 1][posZeroJ];
                sudo_arr[posZeroI + 1][posZeroJ] = 0;
                posZeroI += 1;
                used++;
                left--;
                Display(sudo_arr,used,left);
            }
            else if(ch2 == 75 && posZeroJ > 0) {// printf("LEFT")
                sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI][posZeroJ - 1];
                sudo_arr[posZeroI][posZeroJ - 1] = 0;
                posZeroJ -= 1;
                used++;
                left--;
                Display(sudo_arr,used,left);
            }
            else if(ch2 == 77 && posZeroJ < 3) {//printf("RIGHT")
                sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI][posZeroJ + 1];
                sudo_arr[posZeroI][posZeroJ + 1] = 0;
                posZeroJ += 1;
                used++;
                left--;
                Display(sudo_arr,used,left);
            }
        }
        else if((ch1=='a' || ch1=='A') && posZeroJ > 0) {// printf("LEFT")
            sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI][posZeroJ - 1];
            sudo_arr[posZeroI][posZeroJ - 1] = 0;
            posZeroJ -= 1;
            used++;
            left--;
            Display(sudo_arr,used,left);
        }
        else if((ch1=='d' || ch1=='D') && posZeroJ < 3) {//printf("RIGHT")
            sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI][posZeroJ + 1];
            sudo_arr[posZeroI][posZeroJ + 1] = 0;
            posZeroJ += 1;
            used++;
            left--;
            Display(sudo_arr,used,left);
        }
        else if((ch1=='w' || ch1=='W') && posZeroI > 0) { //"UP")
            sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI - 1][posZeroJ];
            sudo_arr[posZeroI - 1][posZeroJ] = 0;
            posZeroI -= 1;
            used++;
            left--;
            Display(sudo_arr,used,left);
        }
        else if((ch1=='s' || ch1=='S') && posZeroI <3) {//printf("DOWN");
            sudo_arr[posZeroI][posZeroJ] = sudo_arr[posZeroI + 1][posZeroJ];
            sudo_arr[posZeroI + 1][posZeroJ] = 0;
            posZeroI += 1;
            used++;
            left--;
            Display(sudo_arr,used,left);
        }
        else if(ch1 == 'n' || ch1 == 'N') {
            exit(0);
        }

    }


    return 0;
}
int randArrGen(int game_arr[4][4]) {
    int arr[16] = {0};// Check array.
    //int game_arr[4][4];// Main array or Holding array.

    int n = 15;

    // srand is use to generate new set of random values on each
    //  new run, if not used each run generate new set of ramdom
    //  values in same order.
    srand(time(0));

    int val;// this variable will store random value generated.
    int i=0, j=0, k=0;// k is for inner while loop.
    while(n != 0) {
        val = rand() % n + 1;// here +1 is for avoiding zero.
        if(arr[val] == 0) {// check that random don't repeat the value.
            game_arr[i][j] = val;// set the random value.
            if(i<4 && j==3){
                j=0;
                i++;
            }
            else {
                j++;
            }
            arr[val]++;// increment to asure value is once inputed.

            k=n;// decrease the j value.
            while(arr[k] != 0) {
                n--;// decrease the range of random generator.
                k--;
            }
        }
    }
    game_arr[3][3] = 0;
}
void Display(int game_arr[][4], int used, int left) {
    static int check=1;
    int i=0, j=0;
    if(check) {
        printf("Attempted steps:- %d.\n",used);
        printf("Remaining steps:- %d.\n",left);
        for(i=0;i<4;i++) {
            j=0;
            for(j=0;j<4;j++){
                printf("%02d ",game_arr[i][j]);

            }
            printf("\n");
        }
        check--;
    }
    else {
        CONSOLE_SCREEN_BUFFER_INFO coninfo;
        HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hCon, &coninfo);
        coninfo.dwCursorPosition.Y -= 6;
        /* coninfo.dwCursorPosition.X ;
                Leave it untouched to print from left end.
        */
        SetConsoleCursorPosition(hCon, coninfo.dwCursorPosition);
        printf("Attempted steps:- %d.\n",used);
        printf("Remaining steps:- %d.\n",left);
        for(i=0;i<4;i++) {
            j=0;
            for(j=0;j<4;j++){
                printf("%02d ",game_arr[i][j]);

            }
            printf("\n");
        }
    }
}
