/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * <#Name(s)#>Jazib Ahmad, Henry Ma
 * <#uniqname(s)#> jaziba
 *
 * <#A description of the project here#>  The project
 *  creates the game oh hi and allows
 *  the user to play it
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    //traverses through board and
    //counts the number of unknown squares
    int count = 0;
    for (int  i = 0 ; i < size ; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == 0)
            {
                count++;
            }
        }
    }

    
    return count;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    //loops through the row and counts the number of times
    // there are three or more consecutive tiles of the given color
    int count = 0;
    for (int i = 0 ; i < size  - 2; i++)
    {
        if (board[row][i] == color && board[row][i + 1] == color && board[row][i + 2] == color)
        {
            count++;
        }
    }
    
    //returns false if count is bigger than zero
    // otherwise returns true
    if (count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }

    
    return false;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    //loops through the column and counts the number of times
    // there are three or more consecutive tiles of the given color
    int count = 0;
    for (int i = 0 ; i < size - 2; i++)
    {
        if(board[i][col] == color && board[i + 1][col] == color && board[i + 2][col] == color)
        {
            count++;
        }
    }
    
    //returns false if count is bigger than zero
    // otherwise returns true
    if (count > 0)
    {
        return false;
    }
    else
    {
        return true;
    }

    
    return false;
    
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    //checks to see if no row or column in board
    //contains three or more consecutive red or blue squares
    for (int i = 0 ; i < size ; i ++)
    {
       if (col_has_no_threes_of_color(board, size, i, 1) == false ||
           row_has_no_threes_of_color(board, size, i, 1) == false ||
           row_has_no_threes_of_color(board, size, i, 2) == false ||
           col_has_no_threes_of_color(board, size, i, 2) == false)
          
       {
           return false;
       }
        
    }
    
    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    
    //loops and compares each element in row1 of board
    //with row2 of board. Also checks if either row contains
    // an unknown
    for (int i = 0 ; i < size ; i++)
    {
        if (board[row1][i] != board[row2][i] ||
            board[row1][i] == 0 ||
            board[row2][i] == 0)
        {
            return true;
        }
    }

    
    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    //loops and compares each element in col1 of board
    //with col2 of board. Also checks if either column contains
    // an unknown
    for (int i = 0 ; i < size ; i++)
    {
        if (board[i][col1] != board[i][col2] ||
            board[i][col1] == 0 ||
            board[i][col2] == 0)
        {
            return true;
        }
    }

    
    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {

    
    //compares each row with each other to check to see if
    //any two rows are the same
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = i + 1 ; j < size ; j++)
        {
            if (rows_are_different(board, size, i, j) == false)
            {
                return false;
            }
        }
        
    }
    
    //compares each column with each other to check to see if
    //any two columns are the same
    for (int i = 0 ; i < size ; i++)
    {
        for (int k = i + 1 ; k < size ; k++)
        {
            if (cols_are_different(board, size, i, k) == false)
            {
                return false;
            }
        }
        
    }

    
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    
    
    for (int i = 0; i < size - 1;i++)
    {
        
        //checks if consecutive tiles at the current row
        //are color red and colors tiles on either side blue
        //if they are unkown squares
        if (board[row][i] == 1 && board[row][i + 1] == 1 )
        {
            if (i != 0)
            {
                if (board[row][i - 1] == 0)
                {
                    mark_square_as(board, size, row, i - 1, 2, announce);
                }
            }
            if (i + 1 != size - 1)
            {
                if (board[row][i + 2] == 0)
                {
                    
                    mark_square_as(board, size, row, i + 2, 2, announce);
                }
            }
        }
        
        
        //checks if consecutive tiles at the current row
        //are color blue and colors tiles on either side red
        //if they are unkown squares
        if (board[row][i] == 2 && board[row][i + 1] == 2)
        {
            if (i  != 0)
            {
                if (board[row][i - 1] == 0)
                {
                    mark_square_as(board, size, row, i - 1, 1, announce);
                }
            }
            if (i + 1 != size - 1)
            {
                if (board[row][i + 2] == 0)
                {
                    mark_square_as(board, size, row, i + 2, 1, announce);
                }
            }
        }
        
        //colors unknown square blue if it is between two red squares
        //and colors square red if it is between two blue squares
        if (i != size -2)
        {
            if (board[row][i] == 1 && board[row][i + 2] == 1)
           {
               if (board[row][i + 1] == 0)
                 {
                  mark_square_as(board, size, row, i + 1, 2, announce);
                 }
           }
        
            else if (board[row][i] == 2 && board[row][i + 2] == 2)
          {
               if (board[row][i + 1] == 0)
                 {
                  mark_square_as(board, size, row, i + 1, 1, announce);
                 }
          }
            
        }
        
        
    }

    
        return;
    
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
    
    for (int i = 0; i < size - 1;i++)
    {
        //checks if consecutive tiles at the current column
        //are color red and colors tiles on either side blue
        //if they are unkown squares
        if (board[i][col] == 1 && board[i + 1][col] == 1 )
        {
            if (i != 0)
            {
                if (board[i - 1][col] == 0)
                {
                    mark_square_as(board, size, i - 1, col, 2, announce);
                }
            }
            
            if(i + 1 != size - 1)
            {

                if (board[i + 2][col] == 0)
                {
                    mark_square_as(board, size, i + 2, col, 2, announce);
                }
            }
        }
        
        
        //checks if consecutive tiles at the current column
        //are color blue and colors tiles on either side red
        //if they are unkown squares
        if (board[i][col] == 2 && board[i + 1][col] == 2)
        {
            if (i != 0)
            {
                if (board[i - 1][col] == 0)
                {

                    mark_square_as(board, size, i - 1, col, 1, announce);
                }
            }
            if (i + 1 != size - 1)
            {
                if (board[i + 2][col] == 0)
                {
                    mark_square_as(board, size, i + 2, col, 1, announce);
                }
            }
        }
        
        
        //colors unknown square blue if it is between two red squares
        //and colors square red if it is between two blue squares
        if (i != size - 2)
        {
            if (board[i][col] == 1 && board[i + 2][col] == 1)
            {
               if (board[i + 1][col] == 0)
               {
              
                  mark_square_as(board, size, i + 1, col, 2, announce);
               }
            }
            else if (board[i][col] == 2 && board[i + 2][col] == 2)
            {
                if (board[i + 1][col] == 0)
                {
                  mark_square_as(board, size, i + 1, col, 1, announce);
                }
            }
        }
        
        
    }
    

        return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    //counts number of red and blue tiles in row
    int countR = 0 ;
    int countB = 0;
    for (int i = 0 ; i <size ; i++)
    {
        
        if (board[row][i] == 2)
        {
            countB++;
        }
        if (board[row][i] == 1)
        {
            countR++;
        }
    }
    
    //checks if count of red tiles or blue tiles is half
    //if count is half then all remaining tiles are colored opposite color
    if (countR == size / 2)
    {
        for ( int i = 0 ; i < size ; i ++)
        {
            if (board[row][i] == 0 )
            {
                mark_square_as(board, size, row, i, 2, announce);
            }
        }
        
    }
    if (countB == size / 2)
    {
        for ( int i = 0 ; i < size ; i ++)
        {
            if (board[row][i] == 0)
            {
                mark_square_as(board, size, row, i, 1, announce);
            }
        }
        
    }
    

    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    
    //counts number of red and blue tiles in column
    int countR = 0 ;
    int countB = 0;
    
    
    for (int i = 0 ; i <size ; i++)
    {
        
        if (board[i][col] == 2)
        {
            countB++;
        }
        if (board[i][col] == 1)
        {
            countR++;
        }
    }
    
    //checks if count of red tiles or blue tiles is half
    //if count is half then all remaining tiles are colored opposite color
    if (countR == size / 2)
    {
        for ( int i = 0 ; i < size ; i ++)
        {
            if (board[i][col] == 0 )
            {
                mark_square_as(board, size, i, col, 2, announce);
            }
        }
        
    }
    if (countB == size / 2)
    {
        for ( int i = 0 ; i < size ; i ++)
        {
            if (board[i][col] == 0)
            {
                mark_square_as(board, size, i, col, 1, announce);
            }
        }
        
    }
    
    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    //checks if board does not have unknown square and
    //that board doesn't break rules of oh hi
    if (count_unknown_squares(board, size) == 0 &&
       board_is_valid(board, size) == true)
    {
        return true;
    }

   
    return false;
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    
    //checks if row_input is between 1 and size inclusive
    if (row_input < 1 || row_input > size  )
    {
        cout <<  "Sorry, that's not a valid input." << endl;
        return false;
    }
    
    //converts col_input to upper case and checks if it is
    // between A and (A + size - 1) inclusive
    char colInputUpper = toupper(col_input);
    if (colInputUpper < 'A' || colInputUpper > 'A' + size - 1 )
    {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    
    //checks if color is either red blue or unknown
    char color = toupper(color_char);
    if (color != UNKNOWN_LETTER &&
       color != RED_LETTER &&
       color != BLUE_LETTER)
    {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    
   
    int column = colInputUpper - 'A';
    col = column;
    row = row_input - 1;
    
    
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
   
        // if specified square in current board is not in original board
        //then prints error message
        if (current_board[row][col] == original_board[row][col] &&
            original_board[row][col] != UNKNOWN )
        {
            cout << "Sorry, original squares cannot be changed." << endl;
            return false;
        }

        //if  given color in given square of current board  creates invalid board
        //then prints error message
        int copy[MAX_SIZE][MAX_SIZE];
        copy_board(current_board, copy, size);
        copy[row][col] = color;
        if (board_is_valid(copy, size) == false)
        {
            cout << "Sorry, that move violates a rule." << endl;
            return false;
        }


        return true;
    }

