#include <stdio.h>
#include <stdlib.h>

/*Write a C code that builds a mini sudoku - 6 squares (squared) */

#define minisudoku_size 9

void show_minisudoku(int minisudoku[minisudoku_size][minisudoku_size]);//function to show the minisudoku
void filling_the_middle_square(int minisudoku[minisudoku_size][minisudoku_size]);//function to fill the middle square with 1
void randomly_filling_the_minisudoku(int minisudoku[minisudoku_size][minisudoku_size]);//function to randomly fill the minisudoku

int main()
{
    int minisudoku [minisudoku_size][minisudoku_size] = {0}; //initializing the minisudoku with zeros
    int i, j;
    
    //filling_the_middle_square(minisudoku);//filling the middle square with 1
    randomly_filling_the_minisudoku(minisudoku);//randomly filling the minisudoku
    show_minisudoku(minisudoku);//showing the minisudoku
    

    return 0;
}


void show_minisudoku(int minisudoku[minisudoku_size][minisudoku_size])
{
    int i, j;

    for(i=0; i < minisudoku_size; i++)
    {
        for(j=0; j < minisudoku_size; j++)
        {
            printf("%d ", minisudoku[i][j]);//showing the numbers
        }
        printf("\n");
    }
}

void filling_the_middle_square(int minisudoku[minisudoku_size][minisudoku_size])
{
    int i, j, number, index;

   /** There is a difference between odd and even index numbers, so I have do treat this
    * The middle of the matrix will be considerably differente if the size is odd or even
    */
    printf("value of minisudoku_size/2: %d\n", minisudoku_size/2);
    minisudoku [(minisudoku_size/2) - 1][(minisudoku_size/2) - 1] = 1; //filling the middle square with 1
}

void randomly_filling_the_minisudoku(int minisudoku[minisudoku_size][minisudoku_size])
{
    int i, j, number, index;

    for(i=0; i < minisudoku_size; i++)
    {
        for(j=0; j < minisudoku_size; j++)
        {
            if(minisudoku[i][j] == 0) //if the position is empty
            {
                number = rand() % minisudoku_size + 1; //generating a random number between 1 and minisudoku_size
                minisudoku[i][j] = number; //filling the position with the random number
            }
        }
    }
}
/*Next steps:
1 - fill the minisudoku with numbers from 1 to 6
2 - check if the number is already in the row or column
3 - check if the number is already in the square
4 - if the number is already in the row, column or square, try another number
5 - if the number is not in the row, column or square, place the number in the minisudoku
6 - repeat until the minisudoku is filled
7 - show the minisudoku filled
8 - check if the minisudoku is valid (all numbers from 1 to 6 are present in each row, column and square)
9 - if the minisudoku is not valid, try again
10 - if the minisudoku is valid, show the minisudoku filled and valid
11 - end the program
12 - */
