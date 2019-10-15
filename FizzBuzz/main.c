/* 
 * File:   main.c
 * Author: Alex
 *
 * Created on March 24, 2019, 8:49 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    for(size_t i = 1; i<=100; i++)
    {
        if(i % 5 == 0 && i %3==0)
        {
            printf("%s", "FizzBuzz\n");
        }
        else if(i%3 == 0)
        {
            printf("%s","Fizz\n");
        }
        else if(i%5 == 0)
        {
            printf("%s", "Buzz\n");
        }
        else
        {
            printf("%d\n",i);
        }
    }
}

