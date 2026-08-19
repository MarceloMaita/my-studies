#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void isPrime(int number); // Function prototype for isPrime

int main() {
    int number, i, count=0, /*upperLimit,*/ numberOfInteractions = 0; //COUNT holds as a flag to indicate if the number is prime or not

    printf("Enter a number to check if it is prime: ");
    do
    {
        scanf("%d", &number);//getting a number from user/* code */
    } while (number < 0);
        
    
    if (number < 2) { // 0 and 1 are not prime numbers
        printf("\nnumber is not prime\n");
        return 0;
    } 
    if (number == 2) { // 2 is the only even prime number
        printf("\nnumber is prime\n");
        return 0;
    }  
    
    isPrime(number);
   //upperLimit = sqrt(number); // Set upper limit to the square root of the number
    //upperLimit = number / 2; // No need to check beyond half of the number
    
    /*I can improve this fragment even more. I can change the initial value for
    'i'and check only odd number, cutting the amount of interactions by half */
    
}

void isPrime(int number) {
    // This function can be used to encapsulate the prime-checking logic
    // It can be implemented later to improve modularity and reusability
    int upperLimit = sqrt(number), i, count = 0, numberOfInteractions = 0;

    for(i=3;i<=upperLimit;i+=2) { // Start from 3 and check only odd numbers
        numberOfInteractions++;//this variable is used to count the number of interactions
        if(number % i == 0) {
            printf("\nnumber is not prime");
            count = 1;
                break;
        }
    }
    if (count == 0) {
        printf("\nnumber is prime\n");
    }
    //printf("upper limit: %d\n", upperLimit);
    printf("\nnumber of interactions: %d\n", numberOfInteractions);
}
// This code checks if a number is prime and counts the number of interactions, which means how many times the loop ran.
// It can be improved by checking only odd numbers and starting from 3, which would reduce
// the number of interactions significantly for larger numbers. Also, the upper limit can be set to
// the square root of the number instead of half, as no factors larger than the square root
// will divide the number evenly.
// Additionally, the code can be optimized to handle edge cases like 0 and 1,
// which are not prime numbers, and negative numbers, which are also not prime.
// The code can also be made more efficient by using a boolean flag instead of an integer for the count,
// which would make the code cleaner and more readable. Finally, using a function to encapsulate
// the prime-checking logic would improve modularity and reusability of the code.   
// The code can also be made more user-friendly by adding prompts for input and output messages.
// The code can be further improved by using a more efficient algorithm for prime checking,
// such as the Sieve of Eratosthenes for checking multiple numbers at once,
// or by implementing a more advanced primality test for larger numbers.
// The code can also be made more robust by adding error handling for invalid inputs,
// such as non-integer values or negative numbers, and by providing clear instructions to the user
// on how to use the program. Additionally, the code can be made more efficient by using
// a more efficient algorithm for prime checking, such as the Miller-Rabin primality test,
// which is a probabilistic test that can quickly determine if a number is prime or composite.
// Finally, the code can be made more modular by separating the prime-checking logic into a
// separate function, which would make the code easier to read and maintain.


/*Let's make a lista of things that I  can improve
1 - check only odd numbers and start it from 3 - ok
2 - define upper limit as the square root of the number entered by the user - ok
which I'm not using right now?)
3 - deal with edge cases, like 0 and 1 and negative numbers - ok
4 - use a function to encapsulate the prime-checkin logic - ok
5 - check for sieve of Erathostenes or Miller-Rabin*/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   