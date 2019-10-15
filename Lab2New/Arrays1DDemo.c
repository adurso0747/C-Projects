/* 
 * File: Arrays1DDemo.c
 * Author: Alex Durso
 * Date: 3/2/2019
 * Course: CSC345
 * Homework#: 2
 * Objective: To design and implement functions to process 1D arrays
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */
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
int maxIndex;
int minIndex;
int tom;
int jerry;

int main()
{
    
    printf("%s", "Enter the size of array: ");
    scanf("%d", &size);
    int reverseArraywIndex[size];
    int dArray[size];
    int reversedArray[size];
    
    printf("%s", "Enter the max value: ");
    scanf("%d", &high);
    printf("%s", "Enter the min value: ");
    scanf("%d",&low);
    fillArray(dArray, size, low, high);
    puts("Array is: ");
    printArray(dArray, size);
    
    printf("%s", "\n\nTo find the max number in a range please enter min index first: ");
    scanf("%d", &minIndex);
    printf("%s", "Please enter max index: ");
    scanf("%d", &maxIndex);
    printf("Max number in the range is: %d \n", findWithRange(dArray, minIndex, maxIndex, size));
    
    reverseArray(dArray, reversedArray, size);
    puts("\nReversed array is:");
    printArray(reversedArray, size);
    
    printf("%s", "\n\nTo reverse the array within a certain index please enter min index: ");
    scanf("%d", &minIndex);
    printf("%s", "Enter max index: ");
    scanf("%d", &maxIndex);
    reverseArrayIndex(dArray, reverseArraywIndex, minIndex, maxIndex, size);
    puts("Reversed between array indexes:");
    printArray(reverseArraywIndex, size);
    printf("%s", "\n\nTo find a sequence please enter two numbers: ");
    scanf("%d %d", &tom, &jerry);
    if(findSequence(dArray, tom, jerry, size) == -1)
    {
        puts("Sequence not found");            
    }
    else
    {
        printf("Sequence found at index %d", findSequence(dArray, tom, jerry, size));
    }
        
    
    return 0;
}

/*
 * Function: fillArray
 * Description: Fills array with random numbers from min to max
 * Parameters: Array to be filled, the size of the array,
 * the min and max numbers that can be entered into the array
 * Returns: nothing
 */
void fillArray(int array[], int arraySize, int min, int max)
{
    srand(time(0));
    for(int i = 0; i<arraySize; i++)
    {
        array[i]= (rand() % (max + 1 - min)) + min;
    }

}

/*
 * Function: printArray
 * Description: prints an array
 * Parameters: The array to be printed and it's max index
 * Returns: nothing
 */
void printArray(int array[], int max)
{
    for(int i=0; i<max; i++)
    {
        printf("%d ", array[i]);
    }
}

/*
 * Function: findWithRange
 * Description: Finds the max number in between two array indices
 * Parameters: The array to be searched, the minimum index, the max index,
 * and the max index of the array
 * Returns: The largest integer within the array
 */
int findWithRange(int array[], int minIndex, int maxIndex, int arraySize)
{
    int trigger = 1;
    while(trigger !=0)
    {
        if(maxIndex > arraySize -1)
        {
            puts("Max index out of bounds of array. Input another number: ");
            scanf("%d", &maxIndex);
        }
        else if(minIndex > maxIndex)
        {
            puts("Min index greater than max index. Enter new min index: ");
            scanf("%d", &minIndex);    
            puts("Enter new max index: ");
            scanf("%d", &maxIndex);
        }
        else
        {
            int max = 0;
            for(int i = minIndex; i<maxIndex; i++)
            {
                if(array[i] > max)
                    {
                        max = array[i];
                    }
            }
            trigger = 0;
            return max;
            
        }
    }
    
}

/*
 * Function: reverseArray
 * Description: Reverses an array
 * Parameters: The array to be reversed, an array to store the newly reversed 
 * array, and the maximum index of the array
 * Returns: nothing
 */
void reverseArray(int array[], int result[], int maxIndex)
{
    int counter = maxIndex - 1;
    for(int i = 0; i<maxIndex; i++ )
    {
        result[counter] = array[i];
        counter--;
    }
}

/*
 * Function: reverseArrayIndex
 * Description: Reverses an array between two indices
 * Parameters: The array that the reversal will take place on, an array to store
 * the results, the starting index for the reversal, the ending index for the 
 * reversal, and the max index of the array
 * Returns: nothing
 */
void reverseArrayIndex(int array[], int result[], int minIndex, int maxIndex, 
                       int arraySize)
{
    int trigger = 1;
    while(trigger !=0)
    {
        if(maxIndex > arraySize -1)
        {
            puts("Max index out of bounds of array. Input another number: ");
            scanf("%d", &maxIndex);
        }
        else if(minIndex > maxIndex)
        {
            puts("Min index greater than max index. Enter new min index: ");
            scanf("%d", &minIndex);    
            puts("Enter new max index: ");
            scanf("%d", &maxIndex);
        }
        else
        {
            int counter = maxIndex;
            for(int i = 0; i<size; i++)
            {
                result[i] = array[i];
            }
            for (int i = minIndex; i<=maxIndex; i++)
            {
                result[counter] = array[i];
                counter--;
            }
        }
        trigger = 0;
    }
}

/*
 * Function: findSequence
 * Description: Determines whether an array contains a two integer sequence
 * Parameters: The array to be searched,the first number of the sequence,
 * the second number of the sequence, the maximum index of the array
 * Returns: Index of first element tom or -1 if sequence is not found
 */
int findSequence(int array[], int tom, int jerry, int arraySize)
{
    for(int i = 0; i <arraySize; i++)
    {
        if(array[i] == tom & array[i+1] == jerry)
        {
            return i;
        }
    }
    return -1;
}