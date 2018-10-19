//
// Created by Chelsy Sesma on 12/6/17.
//

#ifndef PAINT_PAINT_H
#define PAINT_PAINT_H
#include <stdio.h>
#include <stdbool.h>


void create_board(char*** board, int num_rows, int num_cols);
void print_board(char** board, int num_rows, int num_cols);
void findingNums(int argc, char** argv, int* num_rows, int* num_cols);
void print_help();
void slopeFunct(char** command, char** board, int num_rows, int num_cols);
void horizontalLineFunction(char** command, char** board, int num_rows, int num_cols);
void verticalLineFunction(char** command, char** board, int num_rows, int num_cols);
void leftVerticalFunction(char** command, char** board, int num_rows, int num_cols);
void rightVerticalFunction(char** command, char** board, int num_rows, int num_cols);
void what_command(char** board, int num_rows, int num_cols);
void findCorrect(char** board, int num_rows, int num_cols, char** command, int argsNeed, char* warning);
void resize_(char** command, char** board, int num_rows, int num_cols);
void addRow(char** command, char** board, int num_rows, int num_cols);
void addColumn(char** command, char** board, int num_rows, int num_cols);
void deleteRow(char** command, char** board, int num_rows, int num_cols);
void deleteColumn(char** command, char** board, int num_rows, int num_cols);
char** check_Valid();
int validityCommandChecker(char** command);
void in_or_not(char** command, int num_checks, char* error_statement, int num_rows, int num_cols, char** board, int row_num, int col_num, int offset);
void save_file(char** board, int num_rows, int num_cols, char* file);
void load_file(char** board, int num_rows, int num_cols, char* file);
void erase_point(char** command, char** board, int num_rows, int num_cols);
void quitANDclear(char** board, int num_rows, int num_cols);
bool sl_input(char *str, char *s);
void freeboard(char*** board,int num_rows);

#endif //PAINT_PAINT_H
