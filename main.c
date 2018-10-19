#include "final.h"

int main(int argc, char** argv){
  char** board = NULL;
  //  char blank_space = '*';
  int num_rows = 10, num_cols = 10;

  //char RC;
  //int position = 0;

  //int cols, rows = 0;
  //char checkEnd = '\n';
  //int nRows = 0;
  //int nCols = 0;

  findingNums(argc, argv, &num_rows, &num_cols);

  // printf("chelsy\n");
  create_board(&board, num_rows, num_cols);
  print_board(board, num_rows, num_cols);

  what_command(board, num_rows, num_cols);

  quitANDclear(board, num_rows, num_cols);
  // char *fileName = NULL;

  // print_help(board, &num_rows,&num_cols);

  return 0;
}