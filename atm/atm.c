/* 
 * File:   atm.c
 * Author: Alex
 * Date: 2/21/2019
 * Course: CSC345
 * Homework #: 1
 * Problem: Write a C Program for an ATM machine by implementing functions.
 */

#include <stdio.h>
#include <stdlib.h>


int deposit();
int withdraw();
void checkBalance();
void quit();
int balance = 5000;
int receipt;
int withdrawLimit = 1000;
int depositLimit = 10000;
int transactions = 0;

int main()
{
int pin = 3014;
int pinTry;
int pinTries = 1;
int options;
int options2;

printf("Welcome to WCUPA Bank. Please enter your PIN:");
scanf("%d", &pinTry);
while(pinTries <= 3)
{
   if(pin == pinTry)
   {
       printf("Hello Nana. Which transaction would you like to perform?: \n");
       printf("1. Balance \n2. Withdrawal\n3. Deposit \n4. Quit\n");
       scanf("%d", &options);
       while(options <= 4)
       {
           switch(options)
           {
               case 1:
                   checkBalance(balance);
                   transactions++;
                   break;
               case 2:
                   withdraw(balance);
                   transactions++;
                   break;

               case 3:
                   deposit(balance);
                   transactions++;
                   break;

               case 4:
                   quit();
                   break;

           }
           printf("Would you like to perform another transaction?\n1. Yes \n2. No\n");
           scanf("%d", &options2);
           if(options2 == 1)
           {
               printf("Which transaction would you like to perform?: \n");
               printf("1. Balance \n2. Withdrawal\n3. Deposit \n4. Quit\n");
               scanf("%d", &options);
           }

           else
           {
               quit();
           }
       }
   }
   if(pinTries == 3)
   {
       printf("You have exceeded the number of tries for your PIN."
               "\nYour account will be suspended for the day\n");
       quit();
   }

   else if(pin != pinTry)
   {
       printf("You have entered an incorrect PIN. Please try again:");
       scanf("%d", &pinTry);
       pinTries++;
   }

   
}
return 0;
}


int withdraw()
{
int withdrawAmount;
int withdrawAttempts =1;
printf("Your current withdrawal limit is %d\n", withdrawLimit);
printf("Enter the amount to withdraw in a multiple of 20: ");
scanf("%d", &withdrawAmount);
while(withdrawAttempts <=3)
{
    if(withdrawAttempts == 3)
    {
        printf("Error. Too many invalid tries. Exiting ATM.");
        exit(0);         
    }
    else if(withdrawAmount <= 0)
    { 
        printf("Invalid entry. Please try again:");
        withdrawAttempts++;
        scanf("%d", &withdrawAmount);
    }
    
    else if(withdrawAmount%20 !=0)
    { 
        printf("Invalid entry. Please try again:");
        withdrawAttempts++;
        scanf("%d", &withdrawAmount);
    }
    else if(withdrawAmount > withdrawLimit)
    {
        printf("Invalid entry. Please try again:");
        withdrawAttempts++;
        scanf("%d", &withdrawAmount);
    }
    else if(withdrawAmount > balance)
    {
        printf("Invalid entry. Please try again:");
        withdrawAttempts++;
        scanf("%d", &withdrawAmount);
    }
        
    else
    {
        balance -= withdrawAmount;
        withdrawLimit -= withdrawAmount;
        printf("Would you like a receipt:\n1. Yes \n2. No\n");
        scanf("%d", &receipt);
        return balance;
    }   
}


}

int deposit()
{
  int depositAmount;
  int depositAttempts=1;
  printf("Your current deposit limit is %d\n", depositLimit);
  printf("Enter an amount you would like to deposit: ");
  scanf("%d", &depositAmount);
  while(depositAttempts <=3)
{
    if(depositAttempts ==3)
    {
        printf("Error. Too many invalid tries. Exiting ATM.");
        exit(0);    
    }
    
    else if(depositAmount <= 0)
    { 
        printf("Invalid entry. Please try again:");
        depositAttempts++;
        scanf("%d", &depositAmount);
    }
    
    else if(depositAmount > depositLimit)
    {
        printf("Invalid entry. Please try again:");
        depositAttempts++;
        scanf("%d", &depositAmount);
    }
    else
    {
        balance += depositAmount;
        depositLimit -= depositAmount;
        printf("Would you like a receipt:\n1. Yes \n2. No\n");
        scanf("%d", &receipt);
        return balance;
    }   
}
}

void checkBalance(int balance)
{
  printf("Your current balance is: %d\n", balance);
  printf("Would you like a receipt:\n1. Yes \n2. No\n");
  scanf("%d", &receipt);
return;
}

void quit()
{
  printf("Thank you for choosing WCUPA bank. Today you made %d transactions.",transactions);
  exit(0);
}
