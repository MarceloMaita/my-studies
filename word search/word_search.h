#ifndef WORD_SEARCH_H
#define WORD_SEARCH_H  

#define N 10 //define the size of the matrix

void show_matrix(char matrix[N][N]);//function to show the matrix
void filling_the_matrix(char matrix[N][N]);
void filling_the_main_diagonal(char matrix[N][N]);//function to fill the main diagonal with a specific letter
void filling_the_second_diagonal(char matrix[N][N]);//function to fill the second diagonal with a specific letter
void remove_character_by_position(char matrix[N][N], int row, int col);//function to remove a character by its position, not by its value
void write_horizontally(char matrix[N][N], int row, int col_start);//function to write a word horizontally in the matrix
void write_vertically(char matrix[N][N], int row_start, int col);//function to write a word vertically in the matrix
void write_diagonally(char matrix[N][N], int row_start, int col_start);//function to write a word diagonally in the matrix
void menu(char matrix[N][N]);//function to show the menu and call the functions
int get_position(char alignment[20]);//funtion to get the position from the user - it can be uses for row or column
int is_safe(char matrix[N][N], int mode, int row, int col, int word_length);//function to check if the position is safe to write a word
int count_number_of_characters(char word[]);//function to count the number of characters in a word - I'm using this only because I'm not using string.h library - I could use strlen() function instead of this one
#endif