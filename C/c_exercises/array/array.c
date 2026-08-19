#include <stdio.h>
#include <stdlib.h> 

int *create_array(int *array_size); 
void get_numbers(int array_size, int *array);
void menu(int *array_size, int **array);
void print_array(int *array, int array_size);
void search_number(int *array, int array_size, int number);
void insert_element(int *array, int array_size, int position, int element);
void delete_element(int *array, int array_size, int erase_position);
void filter_array(int *array, int array_size, int filter_option, int value);
void fetch_subarray(int *array, int index1, int index2);
void rotate_array(int *array, int displacement, int array_size, int rotate_option);
void merge_arrays(int **array, int *array_size, int *second_array, int second_array_size);
int print_menu(void);
void clear_input_buffer(void);
int read_integer(const char *prompt);


int main(void)
{
    int array_size = 0, *array = NULL;

    menu(&array_size, &array);
    free(array); //free the allocated memory for the array before exiting the program.
    
} 

void menu(int *array_size, int **array)
{
    int option; 

    do
    {
       option = print_menu();
       
        switch (option)
        {
        case 1:
            free(*array); //free the previously allocated memory for the array, if it exists
            *array = create_array(array_size);
            break;
         case 2:
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }

            get_numbers(*array_size, *array);

            if (*array_size > 3)
            {
                printf("position 3 of the array: %d\n", (*array)[3]);
            }
            break;
        case 3:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Enter the number to search: \n");
            int number;
            if(scanf("%d", &number) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            search_number(*array, *array_size, number);
            break;
        }
 
        case 4:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Enter the position where you want to insert the element: \n");
            int position;
            if(scanf("%d", &position) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            printf("Enter the element to insert: \n");
            int element;
            if(scanf("%d", &element) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            insert_element(*array, *array_size, position, element);
            break;
        }
        case 5:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Enter the position of the element to delete: \n");
            int erase_position;
            if(scanf("%d", &erase_position) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            delete_element(*array, *array_size, erase_position);
            break;
        }
        case 6:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Filter by one of the following conditions: \n");
            printf("1. Odd numbers\n");
            printf("2. Even numbers\n");
            printf("3. Numbers greater than a specific value\n");
            printf("4. Numbers less than a specific value\n");
            int filter_option = 0;
            if(scanf("%d", &filter_option) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            int value = 0;
            if (filter_option == 3 || filter_option == 4)
            {
                printf("Enter the specific value: \n");
                if(scanf("%d", &value) != 1)
                {
                    printf("Invalid input. Please enter a valid integer.\n");
                    clear_input_buffer(); // Clear the input buffer to remove the invalid input
                    break;
                }   
            }
            filter_array(*array, *array_size, filter_option, value);//this function is not implemented yet, but it will filter the array based on the selected condition and print the filtered array.  
            break;
        }
        case 7:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Fetch a sub array under certain conditions:");
            printf("\n1.A sub fetch within the array, between two indexes");
            printf("\nGet Indexes: ");
            int index1, index2;
            printf("\nFirst Index: ");
            if(scanf("%d", &index1) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }   
            printf("Second Index: ");
            if(scanf("%d", &index2) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }   

            fetch_subarray(*array, index1, index2); //index1-1 and index2-1 because the user enters positions starting from 1, but array indexing starts from 0.
            break;
        }
        case 8:
        {
            printf("Reverse the array:\n");
            for (int i = *array_size - 1; i >= 0; i--)
            {
                printf("%d ", (*array)[i]);
            }
            printf("\n");
            break;
        }

        case 9:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            print_array(*array, *array_size);
            break;
        }
        case 10:
        {
            if (*array == NULL)
            {
                printf("Create the array first.\n");
                break;
            }
            printf("Rotate the array: \n");
            int rotate_option;
            printf("1. Rotate left\n");
            printf("2. Rotate right\n");
            if(scanf("%d", &rotate_option) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }
            printf("How many positions?");
            int displacement;
            if(scanf("%d", &displacement) != 1)
            {
                printf("Invalid input. Please enter a valid integer.\n");
                clear_input_buffer(); // Clear the input buffer to remove the invalid input
                break;
            }

            switch (rotate_option)
            {
                case 1:
                //insert the call to the function rotate_array here, passing the array and the displacement as arguments.
                rotate_array(*array, displacement, *array_size, rotate_option);
                break;

                case 2:
                //insert the call to the function rotate_array here, passing the array and the displacement as arguments.
                rotate_array(*array, displacement, *array_size, rotate_option);
                break;
            }
            
            //printf("Rotated Array: ");
            //print_array(*array, *array_size);
            break;
        }
        case 11:
        {   
            printf("merge two arrays: \n");
            int *second_array = NULL, second_array_size = 0;
            second_array = create_array(&second_array_size);
            get_numbers(second_array_size, second_array);
            print_array(second_array, second_array_size);
            merge_arrays(array, array_size, second_array, second_array_size);
            free(second_array); //free the allocated memory for the second array after merging.
            break;
        }

        default:
            break;
        }
    }while (option != 0);
    
    
}

int *create_array(int *array_size)
{
    do{
        printf("Enter a valid size for the array: \n");
        if(scanf("%d", array_size) != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer(); // Clear the input buffer to remove the invalid input
        }
    }while(*array_size <= 0); //keep asking the user for a valid array size until they enter a positive integer.
    

   int *array = (int *)malloc(*array_size * sizeof(int)); //this variable "array" exists only in this function, so I can return it and assign it to the variable "array" in the main function.
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1); 
    }

    
    return array;
}

void get_numbers(int array_size, int *array)
{
    printf("Enter %d numbers:\n", array_size);
    for (int i = 0; i < array_size; i++)
    {
        if(scanf("%d", &array[i]) != 1)
        {
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer(); // Clear the input buffer to remove the invalid input
            i--; // Decrement i to re-prompt for the same index
        }
    }
    
}

void print_array(int *array, int array_size)
{
    if (array == NULL)
    {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void search_number(int *array, int array_size, int number)
{
    if (array == NULL)
    {
        printf("Array is empty.\n");
        return;
    }

    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == number)
        {
            printf("Number %d found at position %d.\n", number, i+1);
            return;
        }
    }
    printf("Number %d not found in the array.\n", number);
}

void insert_element(int *array, int array_size, int position, int element)
{
    if (position < 1 || position > array_size)
    {
        printf("Invalid position. Please enter a position between 1 and %d.\n", array_size);
        return;
    }

    array[position - 1] = element; //position - 1 because the user enters positions starting from 1, but array indexing starts from 0.

    printf("new array after inserting element %d at position %d:\n", element, position);
    print_array(array, array_size);
}

void delete_element(int *array, int array_size, int erase_position)
{
    if (erase_position < 1 || erase_position > array_size)
    {
        printf("Invalid position. Please enter a position between 1 and %d.\n", array_size);
        return;
    }

    array[erase_position - 1] = 0; //set the element at the specified position to 0, effectively "deleting" it.

    printf("new array after deleting element at position %d:\n", erase_position);
    print_array(array, array_size);
}

void filter_array(int *array, int array_size, int filter_option, int value)
{
    printf("Filtered array:\n");
    for (int i = 0; i < array_size; i++)
    {
        switch (filter_option)
        {
        case 1: // Odd numbers
            if (array[i] % 2 != 0)
            {
                printf("%d ", array[i]);
            }
            break;
        case 2: // Even numbers
            if (array[i] % 2 == 0)
            {
                printf("%d ", array[i]);
            }
            break;
        case 3: // Numbers greater than a specific value
            if (array[i] > value)
            {
                printf("%d ", array[i]);
            }
            break;
        case 4: // Numbers less than a specific value
            if (array[i] < value)
            {
                printf("%d ", array[i]);
            }
            break;
        
        default:
            break;
        }
    }
    printf("\n");
}

void fetch_subarray(int *array, int index1, int index2)
{
    if (index1 < 1 || index2 < 1 || index1 > index2)
    {
        printf("Invalid indexes. Please enter valid indexes.\n");
        return;
    }

    int subarray_size = index2 - index1 + 1;
    int *subarray = (int *)malloc(subarray_size * sizeof(int));
    int subarray_index = 0;
    printf("/nindex1: %d, index2: %d\n", index1, index2); //this line is just for testing, to check if the index1 and index2 variables are being updated correctly with the user's input.
    if (subarray == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }  

    for(int i=index1; i<=index2; i++)
    {
        subarray[subarray_index] = array[i];
        subarray_index ++;
    }

    printf("Sub array from position %d to %d:\n", index1, index2);
    print_array(subarray, subarray_size);

    free(subarray); //free the allocated memory for the subarray
}

void rotate_array(int *array, int displacement, int array_size, int rotate_option)
{
    int counter = 0;
    switch (rotate_option)
    {
    case 1: // Rotate left
        counter = array_size - 1;
        for(int i=array_size - 1; i>=0; i--)
        {
            if(i - displacement < 0)
            {
                printf("%d ", array[counter]);
                counter--;
            }

            else
            {
                printf("%d ", array[i - displacement]);
            }
        }
        /* code */
        break;
    case 2: // Rotate right
        counter = 0;
    
    for(int i=0; i<array_size; i++)
    {
        if(i + displacement >= array_size)
        {
            printf("%d ", array[counter]);
            counter++;
        }

        else
        {
            printf("%d ", array[i + displacement]);
        }
    }
    
    default:
        break;
    }
    
    
}

void merge_arrays(int **array, int *array_size, int *second_array, int second_array_size)
{
    int merged_array_size = *array_size + second_array_size;

    int *temp = realloc(*array, merged_array_size * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < second_array_size; i++)
    {
        temp[*array_size + i] = second_array[i];
    }

    *array = temp;
    *array_size = merged_array_size;

    printf("Merged array:\n");
    print_array(*array, *array_size);
}

int print_menu(void)
{
    printf("Menu:\n");
    printf("Choose an option:\n");
    printf("=========================\n");
    printf("1. Create an array: \n");
    printf("2. Get numbers: \n");
    printf("3. Search an specific number within the array: \n");
    printf("4. Insert Elements: \n");
    printf("5. Remove Elements: \n");
    printf("6. Filter the array at certain conditions: \n");
    printf("7. Fetch a sub array under condition: \n");
    printf("8. Reverse the array: \n");
    printf("9. Show the array: \n");
    printf("10. Rotate the array: \n");
    printf("11. Merge two arrays: \n");
    printf("0. Exit\n");
    printf("=========================\n");

    int option;
    if(scanf("%d", &option) != 1)
    {
        printf("Invalid input. Please enter a valid integer.\n");
        clear_input_buffer(); // Clear the input buffer to remove the invalid input
        return -1; // Return an error code
    }   

    printf("size of the array: %d\n", option); //this line is just for testing, to check if the option variable is being updated correctly with the user's input.
    return option;
}

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch  != EOF);
}

int read_integer(const char *prompt)
{
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1)
        {
            return value;
        }
        else
        {
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer(); // Clear the input buffer to remove the invalid input
        }
    }
}