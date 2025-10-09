#include <stdio.h>
#include <stdlib.h>

#define N 5

int main()
{
    int numbers_array[N], i;
    int largest, smallest;

    printf("Enter %d numbers:\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &numbers_array[i]);//receiving the numbers
    }

    largest = numbers_array[0];
    smallest = numbers_array[0];

    for (i = 1; i < N; i++)
    {
        if (numbers_array[i] > largest)
        {
            largest = numbers_array[i];
        }
        if (numbers_array[i] < smallest)
        {
            smallest = numbers_array[i];
        }
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;

}