#include <stdio.h>
#include <stdlib.h>

/*write a C program that solve Fibonacci sequence for N terms. Iteratively and recursively.*/

int fibonacci_iterative_way(int predecessor_1, int predecessor_2, int n);//separate function for the iterative approach
int fibonacci_recursive_way(int n);//separate function for the recursive approach

int main()
{
    int predecessor_1 = 0, predecessor_2 = 1, term, n, i, choice; //both predecessors holds the first two terms of the Fibonacci sequence, term holds the current term, n is the number of terms to be printed, and i is used for iteration.

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("which way do you want to solve the Fibonacci sequence?\n");
    printf("1. Iteratively\n");
    printf("2. Recursively\n");
  
    scanf("%d", &choice); 
    if(choice == 1)
    {
      fibonacci_iterative_way(predecessor_1, predecessor_2, n);
    }
    else if(choice == 2)
    {
        //printf("Fibonacci sequence: ");
        for(i = 1; i <= n; i++)
        {
            term = fibonacci_recursive_way(i); //call the recursive function to get the current term
            printf("%d ", term); //print the current term
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    
     
    
}

int fibonacci_iterative_way(int predecessor_1, int predecessor_2, int n)
{
    int term, i;

    for(i=1; i<=n; i++)//in this way, the value of 'i'mathces the n-th digit of the Fibonacci sequence
    {
        if(i == 1)
        {
            term = predecessor_1; //the first term is 0
        }
        else if(i == 2)
        {
            term = predecessor_2; //the second term is 1
        }
        else
        {
            term = predecessor_1 + predecessor_2; //the current term is the sum of the two preceding terms
            predecessor_1 = predecessor_2; //update the predecessors for the next iteration
            predecessor_2 = term;
        }
        printf("%d ", term); //print the current term
    }
    return 0;
}

int fibonacci_recursive_way(int n)
{
  //testing the erro
 //printf("value of n: %d\n", n);
    if(n == 1) //base case
        return 0;
    else if(n <= 2) 
        return 1; //base case
    else
        return fibonacci_recursive_way(n - 1) + fibonacci_recursive_way(n - 2); //recursive case
}

/*in the recursive way, I had problems with the first two cases (base cases)
I solved it, but understand exactly what happened is crucial*/