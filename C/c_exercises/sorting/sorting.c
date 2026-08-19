#include <stdio.h>
#include <stdlib.h>

/*Write a C program that reads numbers up to N and the sort it*
I'm not trained in dynamic memory allocation, so I'll define myself the N using #define*/
/*points to add - generate the numbers randomly, sort the numbers, show the numbers sorted*/

#define N 5
void get_numbers(int numbers_array[]); //function to get the numbers
void show_the_numbers(int numbers_array[]);//function to show the numbers
void bubble_sort_numbers(int numbers_array[]);//function to sort the numbers using bubble sort algorithm



int main()
{

    int numbers_array[N], i;

    get_numbers(numbers_array);//getting the numbers

    show_the_numbers(numbers_array);//showing the numbers
   

    bubble_sort_numbers(numbers_array);//sorting the numbers
    printf("\nSorted numbers:\n");
    show_the_numbers(numbers_array);//showing the numbers sorted

    

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



/*Next steps:
1 - get the numbers randomly - There is no difference in enter the numbers by the user 
2 - implement quick sort
    2.1 - find the pivot - in a really simple manner, I did. 
    2.2 - sort the numbers using the pivot - I have to implement this
 */   