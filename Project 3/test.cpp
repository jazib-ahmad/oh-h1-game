/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2019
 *
 * <#Name(s)#> Jazib Ahmad, Henry Ma
 * <#uniqname(s)#>  jaziba, maguangh
 *
 * <#A description of the project here#>   The project
 *  creates the game oh hi and allows
 *  the user to play it
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();



void startTests() {
    test_count_unknown_squares();

    
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];
    
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size = 4;
    read_board_from_string(board, test_board_1, size);
    cout << "Expected: 8, Actual: " << count_unknown_squares(board, size) << endl;

    
    string test_board_2[] = { "XXX---",
                            "000---",
                            "-XXX--",
                            "-000--",
                            "--XXX-",
                            "--OOO-", };
    read_board_from_string(board, test_board_2, size);
    size = 6;
    cout << "Expected: 18, Actual: " << count_unknown_squares(board, size) << endl;
    string test_board_3[] = { "----",
                              "-0--",
                              "--XX",
                              "X0X-", };
    read_board_from_string(board, test_board_3, size);
    size = 4;
    cout << "Expected: 10, Actual: " << count_unknown_squares(board, size) << endl;

    string test_board_4[] = { "--",
                              "--", };
    read_board_from_string(board, test_board_4, size);
    size = 2;
    cout << "Expected: 4, Actual: " << count_unknown_squares(board, size) << endl;
}


void test_row_has_no_threes_of_color()
{


    int board[MAX_SIZE][MAX_SIZE];
    string test_board_1[] = {"XXXO",
                             "-OOO",
                             "OOOX",
                             "OOX-"};
    
    int size = 4;
    read_board_from_string(board, test_board_1, size);
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 2, 2 ) <<  endl;
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 0, 1 ) <<  endl;
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 1, 1 ) <<  endl;
    cout << "Expected: 1, Actual: " << row_has_no_threes_of_color(board, size, 3, 2 ) <<  endl;
    
    string test_board_2[] = {"XXXO----",
                             "-OOO----",
                             "OOXXX---",
                             "OO-OOO--",
                             "OOXXOOO-",
                             "-----XXX",
                             "OOXX----",
                             "--------"};

    size = 8;
    read_board_from_string(board, test_board_2, size);
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 2, 2 ) <<  endl;
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 0, 1 ) <<  endl;
    cout << "Expected: 0, Actual: " << row_has_no_threes_of_color(board, size, 1, 1 ) <<  endl;
    cout << "Expected: 1, Actual: " << row_has_no_threes_of_color(board, size, 3, 2 ) <<  endl;
    

}

void test_col_has_no_threes_of_color()
{
    int board[MAX_SIZE][MAX_SIZE];
    int size = 0;
    string test_board_1[] = {"XOOO",
                             "XXOO",
                             "XXOX",
                             "OXX-" };
    size = 4;
    read_board_from_string(board, test_board_1, size);
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 0, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 0, 2) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 1, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 1, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 2, 1) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 2, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 3, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 3, 2) << endl;

    string test_board_2[] = {"XXXOX-O-",
                             "-OOOXX--",
                             "OOXXXXO-",
                             "XO-OOXO-",
                             "OOOXOOO-",
                             "----OXX-",
                             "XOX-----",
                             "O-----O-" };
    size = 8;
    read_board_from_string(board, test_board_2, size);
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 0, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 0, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 1, 1) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 1, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 2, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 2, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 3, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 3, 2) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 4, 1) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 4, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 7, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 7, 2) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 6, 1) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 6, 2) << endl;
    cout << "Expected: 0, Actual: " << col_has_no_threes_of_color(board, size, 5, 1) << endl;
    cout << "Expected: 1, Actual: " << col_has_no_threes_of_color(board, size, 5, 2) << endl;
}

void test_board_has_no_threes()
{
    int board[MAX_SIZE][MAX_SIZE];
    int size = 0;
    string test_board_1[] = { "X-X-O-",
                              "------",
                              "-XXO--",
                              "OO--XX",
                              "-----X",
                              "O-----", };
    size = 6;
    read_board_from_string(board, test_board_1, size);
    cout << "Expected: 1, Actual: " <<board_has_no_threes(board, size) << endl;

    string test_board_2[] = { "X-X----X",
                              "OOOOXXXX",
                              "XOXOXOXO",
                              "XXX-----",
                              "-----OOO",
                              "O------X",
                              "O-OO-OOX",
                              "X-XX-XXO", };
    size = 8;
    read_board_from_string(board, test_board_2, size);
    cout << "Expected: 0, Actual: " << board_has_no_threes(board, size) << endl;

    string test_board_3[] = { "----",
                              "-OXO",
                              "-OXO",
                              "-XO-",};
    size = 4;
    read_board_from_string(board, test_board_3, size);
    cout << "Expected: 1, Actual: " << board_has_no_threes(board, size) << endl;

    string test_board_4[] = { "-XXX",
                              "-OXO",
                              "XOXO",
                              "-OO-", };
    size = 4;
    read_board_from_string(board, test_board_4, size);
    cout << "Expected: 0, Actual: " << board_has_no_threes(board, size) << endl;

    string test_board_5[] = { "--",
                              "--", };
    size = 2;
    read_board_from_string(board, test_board_5, size);
    cout << "Expected: 1, Actual: " << board_has_no_threes(board, size) << endl;
}

