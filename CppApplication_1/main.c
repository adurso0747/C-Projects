/* 
 * File:   main.c
 * Author: Alex
 *
 * Created on March 2, 2019, 6:48 AM
 */

#include <stdio.h>
#include <stdlib.h>

int dArray[];
int high;
int low;
int size;
void fillArray();
int findWithRange();
void reverseArray();
void reverseArrayIndex();
int findSequence();
void printArray();
int secondMax;

int main()
{
    puts("Enter the size of array:");
    scanf("%d", &size);
    puts("Enter the max value:");
    scanf("%d", &high);
    puts("Enter the min value:");
    scanf("%d",&low);
    fillArray(dArray, low, high);
    printArray(dArray, high);
    puts("To find the max number in a range please enter min index first: ");
    scanf("%d", &low);
    puts("Please enter max index:");
    scanf("%d", &high);
    printf("Max number in the range is %d", findWithRange(dArray, low, high));
    
    return 0;
}

void fillArray(int array[], int min, int max)
{
    for(int i = low; i<high; i++)
    {
        dArray[i]= (rand() % (high + 1 - low)) + low;
    }

}

void printArray(int array[], int max)
{
    for(int i=0; i<max; i++)
    {
        printf("%d ", array[i]);
    }
}

int findWithRange(int array[], int minIndex, int maxIndex)
{
    int max=0;
    for(int i = minIndex; i<maxIndex; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

