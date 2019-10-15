/* 
 * File: ArraysofPointers.c
 * Author: Alex Durso
 * Date: 3/21/2019
 * Course: CSC345
 * Homework#: 3
 * Objective: To design and implement array of function pointer.
 */

#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void minimum( const int [][ EXAMS ], int, int );
void maximum( const int [][ EXAMS ], int, int );
void average( const int [][ EXAMS ], int, int );
void printArray( const int [][ EXAMS ], int, int );

int main(void)
{
   int student;
   int count;
   const int studentGrades[ STUDENTS ][ EXAMS ] =  
      { { 77, 68, 86, 73 },
        { 96, 87, 89, 78 },
        { 70, 90, 86, 81 } };
   
   //Creates array of pointers to functions
   void(*pointerArray[4])(const int[][EXAMS], int, int) = 
   {printArray, minimum, maximum, average};
   
   printf("%s", "Enter a choice: \n\t0 Print the array of grades\n\t"
           "1 Find the minimum grade\n\t2 Find the maximum grade\n\t3"
           " Print the average on all tests for "
           "each student\n\t4 End Program\n" );
   scanf("%d",&count);
   while(count != 4)
   {
       (*pointerArray[count])(studentGrades, STUDENTS, EXAMS );
       printf("%s", "\nEnter a choice: \n\t0 Print the array of grades\n\t"
           "1 Find the minimum grade\n\t2 Find the maximum grade\n\t3"
           " Print the average on all tests for "
           "each student\n\t4 End Program\n" );
       scanf("%d", &count);
   }
   
}
/*
 * Function: minimum
 * Description: finds minimum grade
 * Parameters: Array of grades, number of pupils, number of exams
 * Returns: nothing
 */
void minimum( const int grades[][ EXAMS ], 
             int pupils, int tests )
{
   int lowGrade = 100;

   for ( size_t i = 0; i <= pupils - 1; i++ )
      for ( size_t j = 0; j <= tests - 1; j++ )
         if ( grades[ i ][ j ] < lowGrade )
            lowGrade = grades[ i ][ j ];

    printf("Lowest grade is: %d.\n", lowGrade);
}

/*
 * Function: maximum
 * Description: finds maximum grade
 * Parameters: Array of grades, number of pupils, number of exams
 * Returns: nothing
 */
void maximum( const int grades[][ EXAMS ], 
             int pupils, int tests )
{
   int highGrade = 0;

   for (size_t i = 0; i <= pupils - 1; i++ )
      for (size_t j = 0; j <= tests - 1; j++ )
         if ( grades[ i ][ j ] > highGrade )
            highGrade = grades[ i ][ j ];

  printf("Highest grade is: %d.\n", highGrade);
}

/*
 * Function: average
 * Description: finds average grade of each student
 * Parameters: Array of grades, number of pupils, number of exams
 * Returns: nothing
 */
void average( const int setOfGrades[][EXAMS], int pupils, int tests )
{
   double average;
   int total = 0;
   for ( size_t i = 0; i <= pupils - 1; i++ )
   {
     total = 0;
     for(size_t j = 0; j<= tests - 1; j++)
     {
       total += setOfGrades[ i ][j];  
     }
     average = (double)total/tests;
     printf("Average for student %d is %0.1lf.\n", i, average);  
   }
}

/*
 * Function: printArray
 * Description: prints the array of grades
 * Parameters: Array of grades, number of pupils, number of exams
 * Returns: nothing
 */
void printArray( const int grades[][ EXAMS ], 
                 int pupils, int tests )
{

   printf( "                 [0]  [1]  [2]  [3]" );

   for ( size_t i = 0; i <= pupils - 1; i++ ) {
      printf( "\nstudentGrades[%d] ", i );

      for (size_t j = 0; j <= tests - 1; j++ )
         printf( "%-5d", grades[ i ][ j ] );
   }
   printf("\n");
}

