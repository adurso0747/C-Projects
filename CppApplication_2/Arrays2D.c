/* 
 * File: Arrays2D.c
 * Author: Alex Durso
 * Date: 3/21/2019
 * Course: CSC345
 * Homework#: 3
 * Objective: To design and implement functions to process 2D arrays
 */

#include <stdio.h>
#include <stdlib.h>

int rows;
int cols;
int max(int array[rows][cols]);
int rowSum(int array[rows][cols], int tempRow);
int columnSum(int array[rows][cols], int tempCol);
int isSquare(int rows, int cols);
void displayOutputs(int array[rows][cols]);

int main() {
    printf("%s", "Let's create a 2Dim array!\n\n\tHow Many rows? ");
    scanf("%d", &rows);
    printf("%s", "\tHow Many Columns? ");
    scanf("%d", &cols);
    printf("%s","\n");
    int twoArray[rows][cols];
    int tempNum;
    
    //Allows user to enter values into 2D Array
    for(size_t i = 0; i < rows; i++)
    {
       for(size_t j = 0; j < cols; j++)
       {
           
           printf("\tenter [%d][%d]: ", i, j);
           scanf("%d", &tempNum); 
           twoArray[i][j] = tempNum;
       }
    }
    printf("\nMax number in array = %d\n\n", max(twoArray));
    
    //Prints sum of rows
    for(size_t i = 0; i< rows; i++)
    {
     printf("Sum of row %d = %d\n", i+1, rowSum(twoArray, i+1) );   
    }
    printf("%s","\n");
    
    //Prints sum of columns 
    for(size_t j = 0; j< cols; j++)
    {
     printf("Sum of column %d = %d\n", j+1, columnSum(twoArray, j+1) );   
    }
    printf("%s","\n");
    
    if(isSquare(rows, cols) == 1)
    {
        printf("%s", "\nThis is a square array.\n\n");
    }
    else
    {
        printf("%s", "\nThis is not a square array.\n\n");
    }
    displayOutputs(twoArray);
    
    
    
    return 0;
}

/*
 * Function: max
 * Description: finds maximum value in array
 * Parameters: array to be searched
 * Returns: the max value of the array
 */
int max(int array[rows][cols])
{
    int max = 0;
    for(size_t i = 0; i < rows; i++)
    {
       for(size_t j = 0; j < cols; j++)
       {
           if (array[i][j] > max)
           {
               max = array[i][j];
           }
       }
    }
    return max;
    
    
}

/*
 * Function: displayOutputs
 * Description: prints the 2D array
 * Parameters: 2D array to be printed
 * Returns: nothing
 */
void displayOutputs(int array[rows][cols])
{
    printf("%s", "Here is your 2Dim array:\n");
    for(size_t i = 0; i < rows; i++)
    {
       printf("%s","\n[");
       for(size_t j = 0; j < cols-1; j++)
       {
           printf("%d, ", array[i][j]);
       }
       printf("%d]", array[i][cols-1]);
    }
}

/*
 * Function: rowSum
 * Description: finds the sum of a row
 * Parameters: 2D array, the row to be summed from the 2D array
 * Returns: An integer value of the sum of the row
 */
int rowSum(int array[rows][cols], int tempRow)
{
    int sum = 0;
    for(size_t i = 0; i<cols; i++)
    {
        sum += array[tempRow - 1][i];
    }
    return sum;
}

/*
 * Function: columnSum
 * Description: finds the sum of a column
 * Parameters: 2D array, the column to be summed from the 2D array
 * Returns: An integer value of the sum of the column
 */
int columnSum(int array[rows][cols], int tempCol)
{
    int sum = 0;
    for(size_t i = 0; i<rows; i++)
    {
        sum += array[i][tempCol-1];   
    }
    return sum;
}

/*
 * Function: isSquare
 * Description: determines if 2d array is square
 * Parameters: the number of rows and columns
 * Returns: 1 if 2d array is square, 0 if not
 */
int isSquare(int rows, int cols)
{
    if(rows == cols)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}