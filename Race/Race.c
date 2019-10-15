/* 
 * File: Race.c
 * Author: Alex Durso
 * Date: 4/29/2019
 * Course: CSC345
 * Homework#: 4
 * Objective: To design and implement functions to process pointers
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moveTort(int* tPtr);
void moveHare(int* hPtr);
void printRace(int* tPtr, int* hPtr);
int finish = 70;


int main()
{
	srand(time(0));
	int hare = 1, tortoise = 1, *hPtr, *tPtr;
	hPtr = &hare;
	tPtr = &tortoise;
 
	printf("%s","BANG !!!!!\nAND THEY'RE OFF!!!!!");
	
	while(tortoise < 70 && hare < 70 )
	{
	    sleep(1);
	    moveTort(&tortoise);
	    moveHare(&hare);
	    printRace(&tortoise, &hare);
	}
	
	if(*hPtr >= 70 && *tPtr >= 70)
	{
	   printf("%s", "\nTie");
	}
	else if(*hPtr >= 70)
	{
	   printf("%s", "\nHare wins. YUCH");
	}
	else
	{
	   printf("%s", "\nTortoise wins. YAY");
	}
        hPtr = NULL;
        tPtr = NULL;
}

/*
 * Function: moveTort
 * Description: Moves tortoise based on a random number
 * Parameters: The tortoise pointer that will be incremented or decremented.
 * Returns: nothing
 */
void moveTort(int* tPtr)
{
	int randInt;
	randInt = (rand() % 10) + 1;
	if(randInt >= 1 && randInt <= 5)
	{
		*tPtr += 3;
	}
	else if (randInt >= 6 && randInt <= 7)
	{
		*tPtr -=6;
	}
	else 
	{
		*tPtr += 1;
	}
	
	if(*tPtr < 1)
	{
	    *tPtr = 1;
	}
}

/*
 * Function: moveHare
 * Description: Moves hare based on a random number
 * Parameters: The hare pointer that will be incremented or decremented.
 * Returns: nothing
 */
void moveHare(int* hPtr)
{
	int randInt;
	randInt = (rand() % 10) + 1;
	if(randInt >= 1 && randInt <= 2)
	{
		//do nothing
	}
	else if(randInt >= 3 && randInt <= 4)
	{
		*hPtr += 9;
	}
	else if(randInt == 5 )
	{
		*hPtr -= 12;
	}
	else if(randInt >= 6 && randInt <= 8)
	{
		*hPtr += 1;
	}
	else 
	{
		*hPtr -= 2;
	}
	
	if(*hPtr < 1)
	{
	    *hPtr = 1;
	}
}

/*
 * Function: printRace
 * Description: Prints H for location of hare, T for location of Tortoise,
 * and OUCH when both pointers are the same number
 * Parameters: The tortoise pointer and the hare pointer to be printed
 * Returns: nothing
 */
void printRace(int* tPtr, int* hPtr)
{
    puts("");
	for(size_t i = 0; i<=70; i++)
	{
		if(i == *tPtr || i == *hPtr)
		{
		    if(*tPtr == *hPtr)
		    {
		        printf("%s", "OUCH!");
		    }
			else if(i == *hPtr)
		    {
		        printf("%s", "H");
		    }
		    else if(i == *tPtr)
		    {
		        printf("%s", "T");
		    }
		    
		}
                else
		{
		    printf("%s", " ");
		}
	}
}
