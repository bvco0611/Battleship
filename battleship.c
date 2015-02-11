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

int main(void)
{
	//setup random seed time
	srand(time(NULL));

	//variables
	int randomNumber;
	int r,c;
	char Junk[16]; // buffer for discarding excessive user input,
                   // used by "FLUSH_STDIN" macro

	//should be long enough for a first name
	char playerOne[NAME_SIZE];
	char playerTwo[NAME_SIZE];



	// array for the "Ocean"
	int ocean[ROWS][COLS];

	//initialize the array with 0's
	for(r = 0; r < ROWS; r++)
    {
        for(c = 0; c < COLS; c++)
        {
            ocean[r][c] = 0;
        }
    }


	//get user input

	//Ask the players to enter their name.
	printf("Player 1 please enter your name: ");
	fgets(playerOne,sizeof(playerOne),stdin);
	FLUSH_STDIN(playerOne); // strip newline, flush extra chars

	printf("Player 2 please enter your name: ");
	fgets(playerTwo,sizeof(playerTwo),stdin);
    FLUSH_STDIN(playerTwo); // strip newline, flush extra chars

	//randomly select a player to start.
	randomNumber = (rand() % 10)+1;
	if (randomNumber > 5)
	{
		printf("%s will start\n", playerOne);
	}
	else if (randomNumber < 5)
	{
		printf("%s will start\n", playerTwo);
	}

	return 0;
}
