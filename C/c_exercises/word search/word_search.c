#include "word_search.h"
#include <stdio.h> 
#include <stdlib.h>

/*Write a C programm that build a word_search.
First, build the functions to receive the matrix and fill the grid */

int main()
{
    char matrix[N][N];


    menu(matrix);//showing the menu and calling the functions
    return 0;
}

void show_matrix(char matrix[N][N])
{
    int i, j;

    for(i=0; i < N; i++)
    {
        for(j=0; j < N; j++)
        {
            printf("%c ", matrix[i][j]);//showing the matrix
        }
        printf("\n");
    }
}
//the function was altered so it can fill the matrix with random letters or with spaces
void filling_the_matrix(char matrix[N][N])
{
    //function to fill the matrix with random letters
    int i, j, option;
    char letter;//variable to store random letters - It will be genarated randomly and filled in the matrix

    printf("\t1 - Blank matrix:\n");
    printf("\t2 - Random letters:\n");
    printf("\t");
    scanf("%d", &option);

    if(option == 1)
    {
        for(i=0; i < N; i++)
        {
            for(j=0; j < N; j++)
            {
                matrix[i][j] = ' '; //fill the matrix with spaces
            }
        }
        return;
    }
    else if(option == 2)
    {
        for(i=0; i < N; i++)
        {
            for(j=0; j < N; j++)
            {
                if(matrix[i][j] == ' ')//only fill the spaces that are empty
                {
                    letter = 'A' + rand() % 26; //generate a random letter from A to Z
                    matrix[i][j] = letter; //fill the matrix with the random letter
                }
            }
        }
    }

    
}

void filling_the_main_diagonal(char matrix[N][N])
{
    int i;

    for(i=0; i < N; i++)
    {
        matrix[i][i] = 'B'; //fill the main diagonal with B
    }
}

void filling_the_second_diagonal(char matrix[N][N])
{
    int i, j;

    for(i=0; i < N; i++)
    {
        for(j=N; j>0; j--)
        {
            if(i+j == N-1)
            {
                matrix[i][j] = 'C'; //fill the second diagonal with C
            }
               
        }
        //matrix[i][N-i-1] = 'C'; //fill the second diagonal with C - interesting solution. I'll test it later
    }
}

void remove_character_by_position(char matrix[N][N], int row, int col)//function to remove a character by its position, not by its value
{
    if(row >= 0 && row < N && col >= 0 && col < N)
    {
        matrix[row][col] = ' '; //remove the character by replacing it with a space
    }
}

void write_horizontally(char matrix[N][N], int row, int col_start)//function to write a word horizontally in the matrix
{
    int i, count = 0, is_safe_return;
    char word[20];

    
    printf("Enter the word to be written horizontally: ");
    scanf("%s", word); //read the word from the user
    count = count_number_of_characters(word);
    is_safe_return = is_safe(matrix, 1, row, col_start, count);
    printf("\nreturn of is_safe function: %d\n", is_safe_return);
    //printf("\nsize of (word) = %d\n", count);
    if(is_safe_return != 1)//check if the position is safe to write the word
    {
        printf("should not write - function write_horizontally size of (word) = %d", count);
        return; 
    } 
    for(i=0; word[i] != '\0' && (col_start + i) < N; i++)
    {
        matrix[row][col_start + i] = word[i];
    }

    
}

void write_vertically(char matrix[N][N], int row_start, int col)//function to write a word vertically in the matrix
{
    int i, count = 0, is_safe_return;
    char word[20]; //word to be written in the matrix
    
    printf("Enter the word to be written vertically: ");
    scanf("%s", word); //read the word from the user
    count = count_number_of_characters(word);
    is_safe_return = is_safe(matrix, 2, row_start, col, count);
    printf("\nreturn of is_safe function: %d\n", is_safe_return);
    //printf("\nsize of (word) = %d\n", count);
    /*/**/if(is_safe_return != 1)//check if the position is safe to write the word
    {
        printf("should not write - function write_vertically: size of (word) = %d and word + N: %d\n", count, count + N);
        return; 
    }/*/*/
    for(i=0; word[i] != '\0' && (row_start + i) < N; i++)
    {
        matrix[row_start + i][col] = word[i];
    }
}

void write_diagonally(char matrix[N][N], int row_start, int col_start)//function to write a word diagonally in the matrix
{
    int i, count=0, is_safe_return;
    char word[20]; //word to be written in the matrix
    printf("Enter the word to be written diagonally: ");
    scanf("%s", word); //read the word from the user
    count = count_number_of_characters(word);
    is_safe_return = is_safe(matrix, 3, row_start, col_start, count);
    printf("\nreturn of is_safe function: %d\n", is_safe_return);
    if(is_safe_return != 1)//check if the position is safe to write the word
    {
        printf("should not write");
        return; 
    }
    for(i=0; word[i] != '\0' && (row_start + i) < N && (col_start + i) < N; i++)
    {
        matrix[row_start + i][col_start + i] = word[i];
    }
}

void menu(char matrix[N][N])
{
    int option;

   do
   {
    printf("Menu:\n");
    printf("Choose an option:\n");
    printf("=========================\n");
    printf("1. Fill the matrix: \n");
    printf("2. Fill the main diagonal with a specific letter: \n");
    printf("3. Fill the second diagonal with a specific letter: \n");
    printf("4. Remove a character by its position: \n");
    printf("5. Write a word horizontally in the matrix: \n");
    printf("6. Write a word vertically in the matrix: \n");
    printf("7. Write a word diagonally in the matrix: \n");
    printf("8. Show the matrix: \n");
    printf("0. Exit\n");
    printf("=========================\n");
    scanf("%d", &option); 
    
    
     switch (option)//It is way simpler to use switch case here instead of if else
    {
    case 1:
        filling_the_matrix(matrix);
        break;
    case 2:
        filling_the_main_diagonal(matrix);
        break;
    case 3:
        filling_the_second_diagonal(matrix);
        break;
    case 4://                                here is for row      here is for column.     -   I need to put on the readme file explaining this - I liked this way of doing it
        remove_character_by_position(matrix, get_position("row"), get_position("column")); //for now, remove the character at position (0,0)
        break;
    case 5:
        write_horizontally(matrix, get_position("row"), get_position("column")); 
        break;
    case 6:
        write_vertically(matrix, get_position("row"), get_position("column"));
        break; 
    case 7:
        write_diagonally(matrix, get_position("row"), get_position("column")); 
        break;      
    case 8:
        show_matrix(matrix);
        break;
    case 0:
        exit(0);
        break;  
   
    
    default:
        break;
    }

    

   } while (option != 0);//using zero avoids any problems when more conditions are added in the future
       
}

int get_position(char alignment[20])//funtion to get the position from the user - it can be uses for row or column
{
    int generic_position_holder;
    printf("Enter the %s number: ", alignment);
    scanf("%d", &generic_position_holder);
    return generic_position_holder;

}
/*This function receive as parameter, the matrix itself, mode, which can be only 3 different ways
so I decided to use a int variable: 1 - horizontal; 2 - vertical; 3 - diagonal - it was simpler than dealing with string comparisson right now*/
int is_safe(char matrix[N][N], int mode, int row, int col, int word_length)
{
    int i, j, count=0;

    switch (mode)//this breaks conditions should stop the running of the function and return to the calling function - how to solve it?

    {
    case 1://horizontal
        printf("\n============\nFUNCTION: is_safe. \ncase: horizontal\ninitial value of col: %d\nword_lenght: %d\nN: %d\ncol + word_length: %d\n============\n\n", col, word_length, N, col + word_length);
        if(col + word_length > N)
        {
            
            return 0; //if the word exceeds the matrix size, return 0
        } 
        for(i=0; i < word_length; i++)
        {
            if(matrix[row][col + i] != ' ')
            {
                printf("impossible to insert the word here. There is a letter already in position: [%d, %d]", row, col+i); //if the position is not empty, return 0
                count++;
                return 0;
            }
        }
        break;

    case 2://vertical
        printf("\n============\nFUNCTION: is_safe.\ncase: vertical\ninitial value of row: %d\nword_lenght: %d\nN: %d\nrow + word_length: %d\n============\n", row, word_length, N, row + word_length);
        if(row + word_length > N) return 0; //if the word exceeds the matrix size, return 0
        for(i=0; i < word_length; i++)
        {
            if(matrix[row + i][col] != ' ')
            {
                printf("impossible to insert the word here. There is a letter already in position: [%d, %d]", row+i, col); //if the position is not empty, return 0
                count++;
                return 0;
            }
        }
        break;

    case 3://diagonal
        if(row + word_length > N || col + word_length > N) return 0; //if the word exceeds the matrix size, return 0
        for(i=0; i < word_length; i++)
        {
            if(matrix[row + i][col + i] != ' ')
            {
                printf("impossible to insert the word here. There is a letter already"); //if the position is not empty, return 0
                return 0;
            }
        }
        break;
    }

    return 1; //if the position is safe, return 1
}

int count_number_of_characters(char word[])
{
    int count = 0, i=0;
    for(i=0; word[i] != '\0'; i++)
    {
        count++;
    }   
    return count;
}