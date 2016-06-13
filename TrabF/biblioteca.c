#include <stdio.h>
#include <stdlib.h>
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
    int r1,r2;
    int c1,c2;
    int s;
    int p2a;
    int p2b;


    


    printf("Jogador %s posicione seu navio de 3 posições (0-9) \n Linha(1) ou Coluna(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Qual linha? (0-9): ");
        scanf("%d", &r1);
        while(r1 > 9 || r1 < 0)
        {
            printf("Inválido. Qual linha? (0-9): ");
            scanf("%d", &r1);
        }
        printf("Primeira posição: ");
        scanf("%d", &p1a);
        while(p1a > 9 || p1a < 0)
        {
            printf("Inválido. Primeira posição: ");
            scanf("%d" , &p1a);
        }
        printf("Segunda posição: ");
        scanf("%d", &p1b);
        while(p1b > 9 || p1b < 0 || p1b == p1a || p1b < (p1a -1) || p1b > (p1a+1))
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p1b);
        }
        printf("Terceira posição: ");
        scanf("%d", &p1c);
        while(p1c > 9 || p1c < 0 || p1c == p1a || p1c == p1b  || p1c < (p1b -1) || p1c > (p1b +1))
        {
            printf("Inválido. Terceira posição: ");
            scanf("%d", &p1c);
        }
        ocean[r1][p1a]=OCCUPIED;
        ocean[r1][p1b]=OCCUPIED;
        ocean[r1][p1c]=OCCUPIED;
    }
    else if(s == 2)
    {
        printf("Qual coluna?(0-9): ");
        scanf("%d", &c1);
        while(c1 > 9 || c1 < 0)
        {
            printf("Inválido. Qual coluna? (0-9): ");
            scanf("%d", &c1);
        }
        printf("Primeira posição: ");
        scanf("%d", &p1a);
        while(p1a > 9 || p1a < 0)
        {
            printf("Inválido. Primeira posição: ");
            scanf("%d" , &p1a);
        }
        printf("Segunda posição: ");
        scanf("%d", &p1b);
        while(p1b > 9 || p1b < 0 || p1b == p1a || p1b < (p1a -1) || p1b > (p1a+1))
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p1b);
        }
        printf("Terceira posição: ");
        scanf("%d", &p1b);
        while(p1c > 9 || p1c < 0 || p1c == p1a || p1c == p1b  || p1c < (p1b -1) || p1c > (p1b +1))
        {
            printf("Inválido. Terceira posição: ");
            scanf("%d", &p1c);
        }
        ocean[p1a][c1]=OCCUPIED;
        ocean[p1b][c1]=OCCUPIED;
        ocean[p1c][c1]=OCCUPIED;

    }
        
    printf("Jogador %s posicione seu navio de 2 posições (0-9) \n Linha(1) ou Coluna(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Qual linha (0-9): ");
        scanf("%d", &r2);
        while(r2 > 9 || r2 < 0)
        {
            printf("Inválido. Escolhe uma linha (0-9): ");
            scanf("%d", &r2);
        }
        printf("Primeira posição: ");
        scanf("%d", &p2a);
        if(r1==r2){
			while(p2a == p1a || p2a == p1b || p2a == p1c){
				printf("Inválido. Primeira posição: ");
            	scanf("%d", &p2a);
			}
		}

		else
			{
			while(p2a > 9 || p2a < 0)
			{
            printf("Inválido. Primeira posição posição: ");
            scanf("%d", &p2a);
			}
		}
		
		printf("Segunda posição: ");
        scanf("%d", &p2b);
		if(r1==r2)
		{
			while(p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1) || p2b == p1a || p2b ==p1b || p2b == p1c){
				printf("Inválido. Segunda posição: ");
            	scanf("%d", &p2b);
			}
		}

		else
		{
			while(p2b > 9 || p2b < 0)
			{
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p2b);
			}
		}       
           
        ocean[r2][p2a]=OCCUPIED;
        ocean[r2][p2b]=OCCUPIED;
        
    }
    else if(s == 2)
    {
        printf("Qual coluna?(0-9): ");
        scanf("%d", &c2);
		while(c2 > 9 || c2 < 0)
        {
            printf("Inválido. Qual coluna? (0-9): ");
            scanf("%d", &c2);
        }
        printf("Primeiro ponto: ");
        scanf("%d", &p1a);
		if(c1==c2)
		{
			while(p2a == p1a || p2a == p1b || p2a == p1c)
			{
				printf("Inválido. Primeira posição: ");
            	scanf("%d", &p1a);
			}
		}

		else
		{
			while(p2a > 9 || p2a < 0 ){
            printf("Inválido. Primeira posição: ");
            scanf("%d", &p1a);
			}
		}       
              
        printf("Segunda posição: ");
		scanf("%d", &p2b);

		if(c1==c2){
			while(p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1) || p2b == p1a || p2a == p1b || p2a == p1c){
				printf("Inválido. Primeira posição: ");
            	scanf("%d", &p2b);
			}
		}

		else 
			{
			while(p2b > 9 || p2b < 0)
			{
            printf("Inválido. Primeira posição: ");
            scanf("%d", &p2b);
			}
		}       
        
        
        ocean[p2a][c2]=OCCUPIED;
        ocean[p2b][c2]=OCCUPIED;
        

    }





}

void printOcean(int ocean[ROWS][COLS],char player[]){
    int r,c;

    printf("Oceano do jogador %s.\n\n",player);

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

