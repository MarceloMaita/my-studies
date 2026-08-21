#include <stdio.h>
#include <stdlib.h>

/*write a C program that solve Fibonacci sequence for N terms. Iteratively and recursively.*/

double fibonacci_iterative_way(double predecessor_1, double predecessor_2, int n, int control);//separate function for the iterative approach
double fibonacci_recursive_way(int n);//separate function for the recursive approach
void menu(double predecessor_1, double predecessor_2, int n, int control);

int main()
{
    int n, i, choice=0; 
    double predecessor_1 = 0, predecessor_2 = 1, term;//both predecessors holds the first two terms of the Fibonacci sequence, term holds the current term, n is the number of terms to be printed, and i is used for iteration.
    do
    {
        menu(0, 1, n, 0);
    }while(choice>=0 && choice<=2);
    
    return 0;
}

double fibonacci_iterative_way(double predecessor_1, double predecessor_2, int n, int control)
{
    double term;
    int i;

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
        if(control == 1 && i == n) //if the user wants to see the nth term only, print it
        {
            printf(" %.0f ", term); //print the current term
        }
        else if(control == 0) //if the user wants to see the Fibonacci sequence for n terms, print each term
        {
            printf(" %.0f ", term); //print the current term
        }
        
    }
    return 0;
}

double fibonacci_recursive_way(int n)
{
 
    if(n == 1) //base case
        return 0;
    else if(n <= 2) 
        return 1; //base case
    else
        return fibonacci_recursive_way(n - 1) + fibonacci_recursive_way(n - 2); //recursive case
}
/*in the recursive way, I had problems with the first two cases (base cases)
I solved it, but understand exactly what happened is crucial*/

void menu(double predecessor_1, double predecessor_2, int n, int control)
{
    int choice, way;
    printf("what do you want to do?\n");
    printf("1. See the fibonacci sequence for n terms?\n");
    printf("2. See the nth term of the fibonacci sequence?\n");
    printf("0. Exit\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0:
            exit(0);   
        case 1:
        printf("Enter the number of terms in the Fibonacci sequence: ");
        scanf("%d", &n);
            printf("Which way do you want to see the Fibonacci sequence? Iteratively or recursively?\n1-Iteratively\n2-Recursively\n");
            scanf("%d", &way);
            fibonacci_iterative_way(0, 1, n, 0); //call the function to see the fibonacci sequence for n terms
            printf("\n");
            break;
        case 2:
            printf("Enter the position of the term you want to see: ");
            scanf("%d", &n);
            fibonacci_iterative_way(0, 1, n, 1); //call the function to see the nth term of the fibonacci sequence
            printf("\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

}