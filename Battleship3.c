/*
Brandon McBride, Curt Rueckert, Jesse McGraw
2-3-2015
Battleship Program
*/
#include <stdio.h>
#include <string.h>


//macro
#define FLUSH_STDIN(x) {if(x[strlen(x)-1]!='\n'){do fgets(Junk,16,stdin);while(Junk[strlen(Junk)-1]!='\n');}else x[strlen(x)-1]='\0';}

//define constants
const int ROWS = 10;
const int COLS = 10;
const int NAME_SIZE = 20;
const int EMPTY    = 0;  // contains water
const int OCCUPIED = 1;  // contains a ship
const int MISSED   = 2;  // shot into ocean
const int HIT      = 3;  // shot and hit


//function prototypes
void printIntro(void);
void resetOcean(int ocean[ROWS][COLS]);
void printOcean(int ocean[ROWS][COLS],char player[]);


int main(void)
{

	int p1a, p1b, p1c, p2a,p2b,p2c;
	int r,r2;
	int c,c2;
	int s;
	int wone = 0, wtwo = 0;
	int f1, f2;
	//setup random seed time
	srand(time(NULL));

	//variables
	int randomNumber;
	char Junk[16]; // buffer for discarding excessive user input,
                   // used by "FLUSH_STDIN" macro

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
	FLUSH_STDIN(playerOne); // strip newline, flush extra chars

	printf("Player 2 please enter your name: ");
	fgets(playerTwo,sizeof(playerTwo),stdin);
    FLUSH_STDIN(playerTwo); // strip newline, flush extra chars


    //have players place their ships
printf("%s place your ship on a grid (0-9) \n Row(1) or Column(2): ", playerOne);
scanf("%d", &s);

if(s == 1)
{
printf("Which row (0-9): ");
scanf("%d", &r);
	while(r > 9 || r < 0){
		printf("Invalid. Which row (0-9): ");
		scanf("%d", &r);
	}
printf("Point one: ");
scanf("%d", &p1a);
	while(p1a > 9 || p1a < 0){
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
	oceanOne[r][p1a]=OCCUPIED;
	oceanOne[r][p1b]=OCCUPIED;
	oceanOne[r][p1c]=OCCUPIED;
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
	while(p1a > 9 || p1a < 0){
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
	oceanOne[p1a][c]=OCCUPIED;
	oceanOne[p1b][c]=OCCUPIED;
	oceanOne[p1c][c]=OCCUPIED;
}

printf("%s place your ship on a grid (0-9) \n Row(1) or Column(2): ", playerTwo);
scanf("%d", &s);

if(s == 1)
{
printf("Which row (0-9): ");
scanf("%d", &r2);
	while(r2 > 9 || r2 < 0){
		printf("Invalid. Which row (0-9): ");
		scanf("%d", &r2);
	}
printf("Point one: ");
scanf("%d", &p2a);
	while(p2a > 9 || p2a < 0){
		printf("Invalid. Point one: ");
		scanf("%d" , &p2a);
	}
printf("Point two: ");
scanf("%d", &p2b);
	while(p2b > 9 || p2b < 0 || p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1))
	{
		printf("Invalid. Point two: ");
		scanf("%d", &p2b);
	}
printf("Point three: ");
scanf("%d", &p2c);
	while(p2c > 9 || p2c < 0 || p2c == p2a || p2c == p2b  || p2c < (p2b -1) || p2c > (p2b +1))
	{
		printf("Invalid. Point three: ");
		scanf("%d", &p2c);
	}
	oceanTwo[r2][p2a]=OCCUPIED;
	oceanTwo[r2][p2b]=OCCUPIED;
	oceanTwo[r2][p2c]=OCCUPIED;
}


else if(s == 2) 
{
printf("Which Column(0-9): ");
scanf("%d", &c2);
	while(c2 > 9 || c2 < 0)
	{
		printf("Invalid. Which column (0-9): ");
		scanf("%d", &c2);
	}
printf("Point one: ");
scanf("%d", &p2a);
	while(p2a > 9 || p2a < 0){
		printf("Invalid. Point one: ");
		scanf("%d" , &p2a);
	}
printf("Point two: ");
scanf("%d", &p2b);
	while(p2b > 9 || p2b < 0 || p2b == p2a || p2b < (p2a -1) || p2b > (p2a+1))
	{
		printf("Invalid. Point two: ");
		scanf("%d", &p2b);
	}
printf("Point three: ");
scanf("%d", &p2c);
	while(p2c > 9 || p2c < 0 || p2c == p2a || p2c == p2b  || p2c < (p2b -1) || p2c > (p2b +1))
	{
		printf("Invalid. Point three: ");
		scanf("%d", &p2c);
	}
	oceanTwo[p2a][c2]=OCCUPIED;
	oceanTwo[p2b][c2]=OCCUPIED;
	oceanTwo[p2c][c2]=OCCUPIED;
}




    //now put it onto the players ocean




	//randomly select a player to start.
	randomNumber = (rand() % 10)+1;
	if (randomNumber > 5)
	{
		printf("%s will start\n", playerOne);
		while(wone <= 2 || wtwo <= 2)
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
			printOcean(oceanTwo,playerTwo);
			printf("\n\n");
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
			printOcean(oceanOne,playerOne);
		}	
	}
	else if (randomNumber < 5)
	{
		printf("%s will start\n", playerTwo);
		while(wone <= 2 || wtwo <= 2)
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
			printOcean(oceanTwo,playerTwo);
			printf("\n\n");
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
				oceanTwo[f1][f2] =	HIT;
				wone++;
			}
			else
			{
				printf("Miss.\n");
				oceanTwo[f1][f2] = MISSED;
			}
			printOcean(oceanOne,playerOne);
			printf("\n\n");
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

void printIntro(void)
{

}
void resetOcean(int ocean[ROWS][COLS])
{
    int r,c;
    for(r = 0; r < ROWS; r++)
    {
        for(c = 0; c < COLS; c++)
        {
            ocean[r][c] = EMPTY;
        }
    }
}
void printOcean(int ocean[ROWS][COLS],char player[])
{
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

