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


    printf("Jogador 1, por favor informe seu nome(até 19 letras): ");
    fgets(playerOne,sizeof(playerOne),stdin);    

    printf("Jogador 2, por favor informe seu nome(até 19 letras): ");
    fgets(playerTwo,sizeof(playerTwo),stdin);


    printOcean(oceanOne,playerOne);
    placeShip(oceanOne,playerOne);
    for(bu = 0; bu <=50; bu++)
    	printf("\n");
    printOcean(oceanTwo,playerTwo);
    placeShip(oceanTwo,playerTwo);
    for(bu = 0; bu <=50; bu++)
    	printf("\n");


    randomNumber = 1 + (rand() % 10);
    if (randomNumber > 5)
    {
        printf("Jogador %s começará.\n", playerOne);
        while(wone != 5 || wtwo != 5)
        {
	    
            printf("Jogador %s dispare (linha)(coluna): ", playerOne);
            scanf("%d %d", &f1, &f2);


            while(oceanTwo[f1][f2] == MISSED || oceanTwo[f1][f2] == HIT)
            {
                printf("Você já disparou nessa posição!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanTwo[f1][f2] == OCCUPIED)
            {
                printf("Acertou!\n");
                oceanTwo[f1][f2] = HIT;
                wone++;
            }
            else
            {
                printf("ERROOOO.\n");
                oceanTwo[f1][f2] = MISSED;
            }

            printf("Jogador %s dispare (linha)(coluna): ", playerTwo);
            scanf("%d %d", &f1, &f2);
			
            while(oceanOne[f1][f2] == MISSED || oceanOne[f1][f2] == HIT)
            {
                printf("Você já disparou nessa posição!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanOne[f1][f2] == OCCUPIED)
            {
                printf("Acertou!\n");
                oceanOne[f1][f2] = HIT;
                wtwo++;
            }
            else
            {
                printf("ERROOOO.\n");
                oceanOne[f1][f2] = MISSED;
            }
        }
    }
    else if (randomNumber <= 5)
    {
        printf("Jogador %s começará.\n", playerTwo);
        while(wone != 5 || wtwo != 5)
        {
	    
            printf("Jogador %s dispare (linha)(coluna): ", playerTwo);
            scanf("%d %d", &f1, &f2);
            while(oceanOne[f1][f2] == MISSED || oceanOne[f1][f2] == HIT)
            {
                printf("Você já disparou nessa posição!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanOne[f1][f2] == OCCUPIED)
            {
                printf("Acertou!\n");
                oceanOne[f1][f2] = HIT;
                wtwo++;
            }
            else
            {
                printf("EROOOOO.\n");
                oceanOne[f1][f2] = MISSED;
            }

            printf("Jogador %s dispare (linha)(coluna): ", playerOne);
            scanf("%d %d", &f1, &f2);
			
            while(oceanTwo[f1][f2] == MISSED || oceanTwo[f1][f2] == HIT)
            {
                printf("Você já disparou nessa posição!: ");
                scanf("%d %d", &f1, &f2);
            }
            if(oceanTwo[f1][f2] == OCCUPIED)
            {
                printf("Acertou!\n");
                oceanTwo[f1][f2] = HIT;
                wone++;
            }
            else
            {
                printf("ERROOOO.\n");
                oceanTwo[f1][f2] = MISSED;
            }

        }
    }

    if(wone == 5)
    {
        printf("O jogador %s venceu!!\n", playerOne);
    }
    else if(wtwo == 5)
    {
        printf("O jogador %s venceu!!\n", playerTwo);
    }
    printf("1= Navio, 2= Tiro perdido, 3= Acerto\n");

    printOcean(oceanOne,playerOne);
    printf("\n\n");
    printOcean(oceanTwo,playerTwo);
	printf("\n\n");
    return 0;
}
