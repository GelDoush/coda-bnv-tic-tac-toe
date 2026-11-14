#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

void interface(char **tab) {
    printf(" %c | %c | %c \n",tab[0][0],tab[0][1],tab[0][2]);
    printf("-------------\n");
    printf(" %c | %c | %c \n",tab[1][0],tab[1][1],tab[1][2]);
    printf("-------------\n");
    printf(" %c | %c | %c \n",tab[2][0],tab[2][1],tab[2][2]);
}

void empty_interface(char **tab) {
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            tab[i][j] = ' ';
            j=j+1;
        }
        i=i+1;
    }
}

void robot(char **tab) {
    int i = 0;
    int stop = 0;
    while (i < 3 && stop==0) {
        int j = 0;
        while (j < 3 &&stop==0) {
            if (tab[i][j] != 'X' && tab[i][j] != 'O') {
                tab[i][j] = 'X';
                stop=1;
            }
            j=j+1;
        }
        i=i+1;
    }
}

void victory(char **tab) {
    int i = 0;
    while (i < 3) {
        if (tab[i][0] != ' ' && tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2]) {
            interface(tab);
            if (tab[i][0] == 'O') {
                printf("Player won\n");
            } 
            else {
                printf("Robot won\n");
            }
            sleep(5);
            system("clear");
            exit(0);

        }
        if (tab[0][i] != ' ' && tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i]) {
            interface(tab);
            if (tab[0][i] == 'O') {
                printf("Player won\n");
            } 
            else {
                printf("Robot won\n");
            }
            sleep(5);
            system("clear");
            exit(0);
        }
        i = i + 1;
    }
    if (tab[0][0] != ' ' && tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2]) {
        interface(tab);
        if (tab[0][0] == 'O') {
            printf("Player won\n");
        }
        else {
            printf("Robot won\n");
    
        }
        sleep(5);
        system("clear");
        exit(0);
    }
    if (tab[0][2] != ' ' && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {
        interface(tab);
        if (tab[0][2] == 'O') {
            printf("Player won\n");
        }
        else {
            printf("Robot won\n");
    
        }
        sleep(5);
        system("clear");
        exit(0);
    }
}

int game(char **tab) {
    int j1;
    int playing=1;
    int line;
    int column;
    int count=0;

    empty_interface(tab);

    while (playing == 1) {
        interface(tab);
        if (count==9) {
                playing = 0;
                printf("\n");
                printf("Game ended, nobody won (tie)\n");
                sleep(5);
                system("clear");
                exit(0);
        }

        printf("Choose a case to play (0-8) : \n");
        scanf("%d",&j1);
        if (j1 >= 0 && j1 < 9) {
            line = j1/3;
            column = j1%3;
            if (tab[line][column] != 'X' && tab[line][column] != 'O') {
                tab[line][column]='O';
                count=count+1;
                victory(tab);

                if (count==9) {
                playing = 0;
                printf("\n");
                printf("Game ended, nobody won (tie)\n");
                sleep(5);
                system("clear");
                exit(0);
                }

                robot(tab);
                count=count+1;
                victory(tab);
            }
            else {
                printf("The slot already contains a caracter \n");
            }
        }
        else {
            printf("Number was not in the possible choices, please retry with one that is accepted \n");
        }
    }
}