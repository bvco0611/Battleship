#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "biblioteca.h"

#define ROWS 10
#define COLS 10
#define EMPTY 0 
#define OCCUPIED 1 
 

void resetOcean(int ocean[ROWS][COLS]){
    int r,c;
    for(r = 0; r < ROWS; r++)
    {
        for(c = 0; c < COLS; c++)
        {
            ocean[r][c] = EMPTY;
        }
    }
}

void placeShip(int ocean[ROWS][COLS],char player[]){

    int p1a, p1b, p1c;
    int r;
    int c;
    int s;
    int p2a;
    int p2b;


    


    printf("%s place your ship on a grid (0-9) \n Row(1) or Column(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Which row (0-9): ");
        scanf("%d", &r);
        while(r > 9 || r < 0)
        {
            printf("Invalid. Which row (0-9): ");
            scanf("%d", &r);
        }
        printf("Point one: ");
        scanf("%d", &p1a);
        while(p1a > 9 || p1a < 0)
        {
            printf("Invalid. Point one: ");
            scanf("%d" , &p1a);
        }
        printf("Point two: ");
        scanf("%d", &p1b);
        while(p1b > 9 || p1b < 0 || p1b == p1a || p1b < (p1a -1) || p1b > (p1a+1))
        {
            printf("Invalid. Point two: ");
            scanf("%d", &p1b);
        }
        printf("Point three: ");
        scanf("%d", &p1c);
        while(p1c > 9 || p1c < 0 || p1c == p1a || p1c == p1b  || p1c < (p1b -1) || p1c > (p1b +1))
        {
            printf("Invalid. Point three: ");
            scanf("%d", &p1c);
        }
        ocean[r][p1a]=OCCUPIED;
        ocean[r][p1b]=OCCUPIED;
        ocean[r][p1c]=OCCUPIED;
    }
    else if(s == 2)
    {
        printf("Which Column(0-9): ");
        scanf("%d", &c);
        while(c > 9 || c < 0)
        {
            printf("Invalid. Which column (0-9): ");
            scanf("%d", &c);
        }
        printf("Point one: ");
        scanf("%d", &p1a);
        while(p1a > 9 || p1a < 0)
        {
            printf("Invalid. Point one: ");
            scanf("%d" , &p1a);
        }
        printf("Point two: ");
        scanf("%d", &p1b);
        while(p1b > 9 || p1b < 0 || p1b == p1a || p1b < (p1a -1) || p1b > (p1a+1))
        {
            printf("Invalid. Point two: ");
            scanf("%d", &p1b);
        }
        printf("Point three: ");
        scanf("%d", &p1c);
        while(p1c > 9 || p1c < 0 || p1c == p1a || p1c == p1b  || p1c < (p1b -1) || p1c > (p1b +1))
        {
            printf("Invalid. Point three: ");
            scanf("%d", &p1c);
        }
        ocean[p1a][c]=OCCUPIED;
        ocean[p1b][c]=OCCUPIED;
        ocean[p1c][c]=OCCUPIED;

    }
        
    printf("%s place your second ship on a grid (0-9) \n Row(1) or Column(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Which row (0-9): ");
        scanf("%d", &r);
        while(r > 9 || r < 0)
        {
            printf("Invalid. Which row (0-9): ");
            scanf("%d", &r);
        }
        printf("Point one: ");
        scanf("%d", &p2a);
        while(p2a > 9 || p2a < 0 || p2a == p1a || p2a == p1b || p2a == p1c)
        {
            printf("Invalid. Point one: ");
            scanf("%d" , &p2a);
        }
        printf("Point two: ");
        scanf("%d", &p2b);
        while(p2b > 9 || p2b < 0 || p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1) || p2b == p1a || p2b ==p1b || p2b == p1c)
        {
            printf("Invalid. Point two: ");
            scanf("%d", &p2b);
        }
        
           
        ocean[r][p2a]=OCCUPIED;
        ocean[r][p2b]=OCCUPIED;
        
    }
    else if(s == 2)
    {
        printf("Which Column(0-9): ");
        scanf("%d", &c);
        while(c > 9 || c < 0)
        {
            printf("Invalid. Which column (0-9): ");
            scanf("%d", &c);
        }
        printf("Point one: ");
        scanf("%d", &p1a);
        while(p2a > 9 || p2a < 0 || p2a == p1a || p2a == p1b || p2a == p1c)
        {
            printf("Invalid. Point one: ");
            scanf("%d" , &p2a);
        }
        printf("Point two: ");
        scanf("%d", &p2b);
        while(p2b > 9 || p2b < 0 || p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1) || p2b == p1a || p2a == p1b || p2a == p1c)
        {
            printf("Invalid. Point two: ");
            scanf("%d", &p2b);
        }
        
        ocean[p2a][c]=OCCUPIED;
        ocean[p2b][c]=OCCUPIED;
        

    }





}

void printOcean(int ocean[ROWS][COLS],char player[]){
    int r,c;

    printf("%s's Ocean\n\n",player);

    printf("     ");
    for(c = 0; c < COLS; c++)
    {
        printf(" ");
        printf("%d",c);
    }
    printf("\n");
    printf("    ======================");

    for(r = 0; r < ROWS; r++)
    {
        printf("\n ");
        printf("%d | ",r);
        for(c = 0; c < COLS; c++)
        {
            printf(" %d",ocean[r][c]);
        }
        printf(" |");
    }
    printf("\n");
    printf("    ======================");
    printf("\n");
}

