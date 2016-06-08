#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "biblioteca.h"

//define constants
const int ROWS = 10;
const int COLS = 10;
const int NAME_SIZE = 20;
const int EMPTY    = 0;  // contains water
const int OCCUPIED = 1;  // contains a ship
const int MISSED   = 2;  // shot into ocean
const int HIT      = 3;  // shot and hit


int main(void)
{
    //setup random seed time
    srand(time(NULL));
    //variables
    int wone = 0, wtwo = 0;
    int f1, f2;
    int randomNumber;
    
    //should be long enough for a first name
    char playerOne[NAME_SIZE];
    char playerTwo[NAME_SIZE];

    // array for the "Ocean"
    int oceanOne[ROWS][COLS];
    int oceanTwo[ROWS][COLS];

    //initialize the array with 0's(reset ocean)
    resetOcean(oceanOne);
    resetOcean(oceanTwo);


    //get user input

    //Ask the players to enter their name.
    printf("Player 1 please enter your name: ");
    fgets(playerOne,sizeof(playerOne),stdin);    

    printf("Player 2 please enter your name: ");
    fgets(playerTwo,sizeof(playerTwo),stdin);




    //have players place their ships
    printOcean(oceanOne,playerOne);
    placeShip(oceanOne,playerOne);
    printOcean(oceanTwo,playerTwo);
    placeShip(oceanTwo,playerTwo);



    //randomly select a player to start.
    randomNumber = (rand() % 10)+1;
    if (randomNumber > 5)
    {
        printf("%s will start\n", playerOne);
        while(wone != 3 || wtwo != 3)
        {
            printf("%s FIRE!!: ", playerOne);
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

            printf("%s FIRE!!: ", playerTwo);
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
        }
    }
    else if (randomNumber < 5)
    {
        printf("%s will start\n", playerTwo);
        while(wone != 3 || wtwo != 3)
        {
            printf("%s FIRE!!: ", playerTwo);
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

            printf("%s FIRE!!: ", playerOne);
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

        }
    }

    if(wone == 3)
    {
        printf("%s Won the Game!!\n", playerOne);
    }
    else if(wtwo == 3)
    {
        printf("%s Won the Game!!\n", playerTwo);
    }


    printOcean(oceanOne,playerOne);
    printf("\n\n");
    printOcean(oceanTwo,playerTwo);

    return 0;
}
