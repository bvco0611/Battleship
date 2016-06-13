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
    int r;
    int c;
    int s;
    int p2a;
    int p2b;


    


    printf("Jogador %s posicione seu navio de 3 posições (0-9) \n Linha(1) ou Coluna(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Qual linha? (0-9): ");
        scanf("%d", &r);
        while(r > 9 || r < 0)
        {
            printf("Inválido. Qual linha? (0-9): ");
            scanf("%d", &r);
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
        while(p1b > 9 || p1b < 0 || ocean[r][p1b] == ocean[r][p1a] || ocean[r][p1b] < ocean[r][p1a-1] || ocean[r][p1b] > ocean[r][p1a+1])
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p1b);
        }
        printf("Terceira posição: ");
        scanf("%d", &p1c);
        while(p1c > 9 || p1c < 0 || ocean[r][p1c] == ocean[r][p1a] || ocean[r][p1c] == ocean[r][p1b]  || ocean[r][p1c] < ocean[r][p1b-1] || ocean[r][p1c] > ocean[r][p1b+1])
        {
            printf("Inválido. Terceira posição: ");
            scanf("%d", &p1c);
        }
        ocean[r][p1a]=OCCUPIED;
        ocean[r][p1b]=OCCUPIED;
        ocean[r][p1c]=OCCUPIED;
    }
    else if(s == 2)
    {
        printf("Qual coluna?(0-9): ");
        scanf("%d", &c);
        while(c > 9 || c < 0)
        {
            printf("Inválido. Qual coluna? (0-9): ");
            scanf("%d", &c);
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
        while(p1b > 9 || p1b < 0 || ocean[p1b][c] == ocean[p1a][c] || ocean[p1b][c] < ocean[p1a-1][c] ||ocean[p1b][c] > ocean[p1a+1][c])
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p1b);
        }
        printf("Terceira posição: ");
        scanf("%d", &p1c);
        while(p1c > 9 || p1c < 0 || ocean[p1c][c] == ocean[p1a][c] || ocean[p1c][c] == ocean[p1b][c]  || ocean[p1c][c] < ocean[p1b-1][c] || ocean[p1c][c] > ocean[p1b+1][c])
        {
            printf("Inválido. Terceira posição: ");
            scanf("%d", &p1c);
        }
        ocean[p1a][c]=OCCUPIED;
        ocean[p1b][c]=OCCUPIED;
        ocean[p1c][c]=OCCUPIED;

    }
        
    printf("Jogador %s posicione seu navio de 2 posições (0-9) \n Linha(1) ou Coluna(2): ", player);
    scanf("%d", &s);

    if(s == 1)
    {
        printf("Qual linha (0-9): ");
        scanf("%d", &r);
        while(r > 9 || r < 0)
        {
            printf("Inválido. Escolhe uma linha (0-9): ");
            scanf("%d", &r);
        }
        printf("Primeira posição: ");
        scanf("%d", &p2a);
        while(p2a > 9 || p2a < 0 || ocean[r][p2a] == ocean[r][p1a] || ocean[r][p2a] == ocean[r][p1b] || ocean[r][p2a] == ocean[r][p1c])
        {
            printf("Inválido. Primeira posição: ");
            scanf("%d" , &p2a);
        }
        printf("Segunda posição: ");
        scanf("%d", &p2b);
        while(p2b > 9 || p2b < 0 || ocean[r][p2b] == ocean[r][p2a] || ocean[r][p2a] < ocean[r][p2a-1] || ocean[r][p2b] > ocean[r][p2a+1] || ocean[r][p2b] == ocean[r][p1a] || ocean[r][p2b] == ocean[r][p1b] || ocean[r][p2b] == ocean[r][p1c])
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p2b);
        }
        
           
        ocean[r][p2a]=OCCUPIED;
        ocean[r][p2b]=OCCUPIED;
        
    }
    else if(s == 2)
    {
        printf("Qual coluna?(0-9): ");
        scanf("%d", &c);
        while(c > 9 || c < 0)
        {
            printf("Inválido. Qual coluna? (0-9): ");
            scanf("%d", &c);
        }
        printf("Primeiro ponto: ");
        scanf("%d", &p1a);
        while(p2a > 9 || p2a < 0 || ocean[p2a][c] == ocean[p1a][c] || ocean[p2a][c] == ocean[p1b][c] || ocean[p2a][c] == ocean[p1c][c])
        {
            printf("Inválido. Primeira posição: ");
            scanf("%d" , &p2a);
        }
        printf("Segunda posição: ");
        scanf("%d", &p2b);
        while(p2b > 9 || p2b < 0 || ocean[p2b][c] == ocean[p2a][c] || ocean[p2b][c] < ocean[p2a-1][c] || ocean[p2b][c] > ocean[p2a+1][c] || ocean[p2b][c] == ocean[p1a][c] || ocean[p2a][c] == ocean[p1b][c] || ocean[p2a][c] == ocean[p1c][c])
        {
            printf("Inválido. Segunda posição: ");
            scanf("%d", &p2b);
        }
        
        ocean[p2a][c]=OCCUPIED;
        ocean[p2b][c]=OCCUPIED;
        

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

