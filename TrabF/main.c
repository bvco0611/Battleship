#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "biblioteca.h"

#define ROWS 10
#define COLS 10
#define NAMESIZE 20
#define OCCUPIED 1 
#define MISSED 2 
#define HIT 3


int main(void)
{
    
    srand(time(NULL));
    
    int wone = 0, wtwo = 0;
    int f1, f2;
    int randomNumber;
    int bu;


    char playerOne[NAMESIZE];
    char playerTwo[NAMESIZE];


    int oceanOne[ROWS][COLS];
    int oceanTwo[ROWS][COLS];


    resetOcean(oceanOne);
    resetOcean(oceanTwo);


    printf("Player 1 please enter your name: ");
    fgets(playerOne,sizeof(playerOne),stdin);    

    printf("Player 2 please enter your name: ");
    fgets(playerTwo,sizeof(playerTwo),stdin);


    printOcean(oceanOne,playerOne);
    placeShip(oceanOne,playerOne);
    for(bu = 0; bu <=50; bu++)
    	printf("\n");
    printOcean(oceanTwo,playerTwo);
    placeShip(oceanTwo,playerTwo);
    for(bu = 0; bu <=50; bu++)
    	printf("\n");


    randomNumber = (rand() % 10)+1;
    if (randomNumber > 5)
    {
        printf("%s will start\n", playerOne);
        while(wone != 5 || wtwo != 5)
        {
	    if(wone == 5 || wtwo == 5){
	       break;
	    }
            printf("%s FIRE (ROW)(COLUMN): ", playerOne);
            scanf("%d %d", &f1, &f2);


            while(oceanTwo[f1][f2] == MISSED || oceanTwo[f1][f2] == HIT)
            {
                printf("Position already fired upon!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanTwo[f1][f2] == OCCUPIED)
            {
                printf("That's a hit!\n");
                oceanTwo[f1][f2] = HIT;
                wone++;
            }
            else
            {
                printf("Miss.\n");
                oceanTwo[f1][f2] = MISSED;
            }

            printf("%s FIRE (ROW)(COLUMN): ", playerTwo);
            scanf("%d %d", &f1, &f2);
			if(wone == 5)
				break;
            while(oceanOne[f1][f2] == MISSED || oceanOne[f1][f2] == HIT)
            {
                printf("Position already fired upon!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanOne[f1][f2] == OCCUPIED)
            {
                printf("That's a hit!\n");
                oceanOne[f1][f2] = HIT;
                wtwo++;
            }
            else
            {
                printf("Miss.\n");
                oceanOne[f1][f2] = MISSED;
            }
        }
    }
    else if (randomNumber < 5)
    {
        printf("%s will start\n", playerTwo);
        while(wone != 5 || wtwo != 5)
        {
	    if(wone == 5 || wtwo == 5){
	       break;
	    }
            printf("%s FIRE (ROW)(COLUMN): ", playerTwo);
            scanf("%d %d", &f1, &f2);
            while(oceanOne[f1][f2] == MISSED || oceanOne[f1][f2] == HIT)
            {
                printf("Position already fired upon!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanOne[f1][f2] == OCCUPIED)
            {
                printf("That's a hit!\n");
                oceanOne[f1][f2] = HIT;
                wtwo++;
            }
            else
            {
                printf("Miss.\n");
                oceanOne[f1][f2] = MISSED;
            }

            printf("%s FIRE (ROW)(COLUMN): ", playerOne);
            scanf("%d %d", &f1, &f2);
			if(wtwo == 5)
				break;
            while(oceanTwo[f1][f2] == MISSED || oceanTwo[f1][f2] == HIT)
            {
                printf("Position already fired upon!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanTwo[f1][f2] == OCCUPIED)
            {
                printf("That's a hit!\n");
                oceanTwo[f1][f2] = HIT;
                wone++;
            }
            else
            {
                printf("Miss.\n");
                oceanTwo[f1][f2] = MISSED;
            }

        }
    }

    if(wone == 5)
    {
        printf("%s Won the Game!!\n", playerOne);
    }
    else if(wtwo == 5)
    {
        printf("%s Won the Game!!\n", playerTwo);
    }
    printf("1= Navio, 2= Tiro perdido, 3= Acerto\n");

    printOcean(oceanOne,playerOne);
    printf("\n\n");
    printOcean(oceanTwo,playerTwo);

    return 0;
}
