#include <stdio.h>
#include <stdlib.h>

/*
Write a C program that reads an integer (positive, up to 5 digits) 
from the user and prints the sum of its digits. */

int mod(int a, int b)//this function is an implementation of the modulus operator
{
    return a - (a / b) * b;
}

int main()
{
    int num, sum=0, i;

    do
    {
        printf("Enter a positive integer (up to 5 digits): ");
        scanf("%d", &num);

    }while(num < 0 || num > 99999);

   for(i=10; i <= 100000; i *= 10)
    {
        sum += mod(num, i) / (i / 10);//here 'i' is divided by 10 to get the place value. No need to deal with the remainder        
    }   
    printf("Sum of digits: %d", sum);
}
