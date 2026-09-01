#include <stdio.h>
#include <stdlib.h>

/*Write a C program that reads numbers up to N and then sort it*
I'm not trained in dynamic memory allocation, so I'll define myself the N using #define*/
/*points to add - generate the numbers randomly, sort the numbers, show the numbers sorted*/

#define N 5
void get_numbers(int numbers_array[]); //function to get the numbers
void show_the_numbers(int numbers_array[]);//function to show the numbers
void bubble_sort_numbers(int numbers_array[]);//function to sort the numbers using bubble sort algorithm
int find_smallest(int numbers_array[]);//function to find the smallest number in the array
void selection_sort_numbers(int numbers_array[]);//function to sort the numbers using selection sort algorithm
void array_copying(int numbers_array[], int auxiliary_array[]);//function to copy the numbers from one array to another

int main()
{

    int numbers_array[N], auxiliary_array[N], i;

    get_numbers(numbers_array);//getting the numbers
    
    array_copying(numbers_array, auxiliary_array);//copying the numbers from one array to another
    show_the_numbers(numbers_array);//showing the numbers
   

    bubble_sort_numbers(numbers_array);//sorting the numbers
    printf("\nSorted numbers:\n");
    show_the_numbers(numbers_array);//showing the numbers sorted
    /*
    get_numbers(numbers_array);//getting the numbers again
    show_the_numbers(numbers_array);//showing the numbers*/
    printf("\n");
    selection_sort_numbers(auxiliary_array);//sorting the numbers using selection sort
    printf("\n");
    printf("\nSorted numbers (Selection Sort):\n");
    show_the_numbers(auxiliary_array);//showing the numbers sorted
    printf("\n");

    return 0;
    
}
void get_numbers(int numbers_array[])
{
    int i;

    printf("Enter %d numbers:\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &numbers_array[i]);//receiving the numbers
    }
}

void show_the_numbers(int numbers_array[])
{
    int i;

    for(i=0; i < N; i++)
    {
        printf("%d ", numbers_array[i]);//showing the numbers
    }


}

void bubble_sort_numbers(int numbers_array[])
{
    int i, j, temp, count=0;

    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (numbers_array[j] > numbers_array[j + 1])
            {
                // Swap the numbers
                temp = numbers_array[j];
                numbers_array[j] = numbers_array[j + 1];
                numbers_array[j + 1] = temp;
                count++;
            }
        }
    }
    printf("\nNumber of comparisons: %d\n", count);
}

int find_smallest(int numbers_array[])
{
    int i, smallest = numbers_array[0], smallest_index = 0;

    for (i = 1; i < N; i++){
        if(numbers_array[i] < smallest){
            smallest = numbers_array[i];
            smallest_index = i;
        }
    }
    return smallest_index;
}

void selection_sort_numbers(int numbers_array[])
{
    int i, j, smallest_index, temp, count=0;

    for (i = 0; i < N - 1; i++)
    {
        smallest_index = find_smallest(numbers_array + i) + i; // Find the index of the smallest number in the unsorted part
        // Swap the found smallest number with the first number of the unsorted part
        temp = numbers_array[i];
        numbers_array[i] = numbers_array[smallest_index];
        numbers_array[smallest_index] = temp;
        count++;
    }
    printf("\nNumber of comparisons: %d\n", count);
}

void array_copying(int numbers_array[], int auxiliary_array[])
{
    int i;

    for (i = 0; i < N; i++)
    {
        auxiliary_array[i] = numbers_array[i];//copying the numbers from one array to another
    }
}

/*Next steps:
1 - get the numbers randomly - There is no difference in enter the numbers by the user 
2 - implement quick sort
    2.1 - find the pivot - in a really simple manner, I did. 
    2.2 - sort the numbers using the pivot - I have to implement this
 */   