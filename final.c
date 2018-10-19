#include "final.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void create_board(char*** board, int num_rows, int num_cols){
  // printf("bye\n");
  //  char** board = (char**) malloc(*num_rows * sizeof(char*));
  *board = (char**)malloc(num_rows*sizeof(char*));
  for(int row = 0; row < num_rows; ++row){
    (*board)[row] = (char*)malloc(num_cols*sizeof(char));
    for(int col = 0; col < num_cols; ++col){
      (*board)[row][col] = '*';
    }
  }
}

void print_board(char** board, int num_rows, int num_cols){
  //printf("You have reached the print-board function,\n");
  for(int x = num_rows - 1; x >= 0; x--) {
    printf(" %d ", num_rows - (x + 1));
    for(int y = 0; y < num_cols; y++) {
      printf(" %c ", board[x][y]);
    }
    printf("\n");
  }
  printf("   ");
  for(int x = 0; x < num_cols; x++)
    printf(" %d ", x);
  printf("\n");
}

void findingNums(int argc, char** argv, int* num_rows, int* num_cols){
  // printf("In finding nums function\n");
  // printf("hi %d\n", i);
  if(argc == 3){ // if correct number of arguements
    if (atoi(argv[1]) != 0 && atoi(argv[2]) != 0) {
      if(atoi(argv[2]) < 1){// if columns is neg
        //printf("Here or?");
        printf("The number of columns is less than 1.\nMaking default board of 10 X 10.\n");
        *num_rows = 10, *num_cols = 10;
        return;
      }
      else if( atoi(argv[1] ) < 1){ // if row is neg
        //printf("HI");
        printf("The number of rows is less than 1.\nMaking default board of 10 X 10.\n");
        *num_rows = 10, *num_cols = 10;
        return;
      }
      else{ // if positive leave as is
        // printf("good\n");
        *num_rows = atoi(argv[1]);
        *num_cols = atoi(argv[2]);
        return;
      }
    }
    else{
      // printf("before\n");
      if(!(isdigit(argv[1][0]))){ //if row 0 or neg
        printf("The number of rows is not an integer.\n");
      }
        // printf("between2\n");
      else if(!(isdigit( argv[2][0] )) ){ // if column not #
        printf("The number of columns is not an integer.\n");
      } // printf("between\n");
      else if((atoi(argv[2]) == 0)){ //if columns 0 or neg
        printf("The number of columns is less than 1.\n");
      }
        // printf("between1\n");
      else if(!(isdigit(argv[1][0]))){ //if row 0 or neg
        printf("The number of rows is not an integer.\n");
      }
      else if((atoi(argv[2]) == 0)){ //if columns 0 or neg
        printf("The number of columns is less than 1.\n");
      }
      else if((atoi(argv[1]) == 0)){ // is row not #
        printf("The number of rows is less than 1.\n");
      }// printf("after\n");
      printf("Making default board of 10 X 10.\n");
      *num_rows = 10,*num_cols = 10;
      return;
    }
  }
  else if(argc == 1){
    *num_rows = 10, *num_cols = 10;
    return;
  }
  else{ // printf("backup return\n");
    printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.\n");
    *num_rows = 10, *num_cols = 10;
    return;
  }
}

void print_help(){
  // printf("In print help function\n");
  /*if (checkEnd != '\n' ){
    printf("Unrecognized command. Type h for help.");

  }*/
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}


void slopeFunct(char** command, char** board, int num_rows, int num_cols){
  // printf("In slope line function\n");
  int X1 = atoi(command[1]);
  int X2 = atoi(command[3]);
  int Y1 = atoi(command[2]);
  int Y2 = atoi(command[4]);

  if(Y1 == Y2){
    // printf("In loop for vertical line function");
    verticalLineFunction(command, board, num_rows, num_cols);
  }
  else if(X1 == X2){
    // printf("In loop for horizontal line function");
    horizontalLineFunction(command, board, num_rows, num_cols);
  }
  else if(((X1 > X2) && (Y1 < Y2)) || ((X1 < X2) && (Y1 > Y2))){
    //left to right neg slope
    // printf("In loop for left vertical function\n");
    //printf("CHe");
    leftVerticalFunction(command, board, num_rows, num_cols);
  }else{
    //printf("HERE");
    // printf("In loop for right vertical function\n");
    rightVerticalFunction(command, board, num_rows, num_cols);
  }
}

void horizontalLineFunction(char** command, char** board, int num_rows, int num_cols){
  // printf("In horizontal line function\n");
  int x;
  int X1 = atoi(command[1]);
  int Y1 = atoi(command[2]);
  int Y2 = atoi(command[4]);

  if(Y1 <= Y2){
    for(x = Y1; x <= Y2; ++x){
      if(board[X1][x] != '-' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '-';
        // print_board(board, num_rows, num_cols);
      }
    }
  }
  if(Y1 > Y2){
    for(x = Y2; x <= Y1; ++x){
      if(board[X1][x] != '-' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '-';
        // print_board(board, num_rows, num_cols);
      }
    }
  }
}

void verticalLineFunction(char** command, char** board, int num_rows, int num_cols){
  // printf("In vertical line function\n");
  int x;
  int Y1 = atoi(command[2]);
  int X1 = atoi(command[1]);
  int X2 = atoi(command[3]);

  if(X1 <= X2){
    for(x = X1; x <= X2; ++x){
      if(board[x][Y1] != '|' && board[x][Y1] != '*'){
        board[x][Y1] = '+';
      }else{
        board[x][Y1] = '|';
        // print_board(board, num_rows, num_cols);
      }
    }
  }

  if(X1 > X2){
    for(x = X2; x <= X1; ++x){
      if(board[x][Y1] != '|' && board[x][Y1] != '*'){
        board[x][Y1] = '+';
      }else{
        board[x][Y1] = '|';
        // print_board(board, num_rows, num_cols);
      }
    }
  }
}

void leftVerticalFunction(char** command, char** board, int num_rows, int num_cols){
  // printf("In left vertical function\n");
  int x;
  int X1 = atoi(command[1]) ;
  //int row2 = command[3] ;
  int Y1 = atoi(command[2]) ;
  int Y2 = atoi(command[4]) ;
  if(Y1 < Y2){
    for(x = Y1; x <= Y2; ++x){
      if(board[X1][x] != '\\' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '\\';
        // print_board(board, num_rows, num_cols);
      }
      X1--;
    }
  }else{
    for(x = Y1; x >= Y2; --x){
      if(board[X1][x] != '\\' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '\\';
        // print_board(board, num_rows, num_cols);
      }
      X1++;
    }
  }
}

void rightVerticalFunction(char** command, char** board, int num_rows, int num_cols){
  // printf("In right vertical function\n");
  int x;
  int X1 = atoi(command[1]) ;
  int X2 = atoi(command[3]);
  int Y1 = atoi(command[2]) ;
  int Y2 = atoi(command[4]) ;

  if(X1 < X2){
    for(x = Y1; x <= Y2; ++x){
      if(board[X1][x] != '/' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '/';
        // print_board(board, num_rows, num_cols);
      }
      X1++;
    }
  }else{
    for(x = Y1; x >= Y2; --x){
      if(board[X1][x] != '/' && board[X1][x] != '*'){
        board[X1][x] = '+';
      }else{
        board[X1][x] = '/';
        // print_board(board, num_rows, num_cols);
      }
      X1--;
    }
  }
}

void what_command(char** board, int num_rows, int num_cols){
  char** command;

  command = check_Valid();
  // printf("In do loop in what command function\n");

  if(strlen(command[0]) != 1){
    printf("Unrecognized command. Type h for help.\n");
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }


  if(command[0][0] == 'q'){
    /*if (checkEnd != '\n') {
      printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.");
      print_board(board, num_rows, num_cols);
      *commandGame = ' ';
    } else {
      // printf("Here???");
      exit(0);
    }*/
    findCorrect(board, num_rows, num_cols, command, 1, "Unrecognized command. Type h for help.");
    quitANDclear(board, num_rows, num_cols);
    exit(0);
  }
  else if(command[0][0] == 'h'){
    // printf("In else if for h \n");
    findCorrect(board, num_rows, num_cols, command, 1, "Unrecognized command. Type h for help.");
    print_help();
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);

  }else if(command[0][0] == 'w'){
    //printf("Reached w else if statement\n");
    findCorrect(board, num_rows, num_cols, command, 5, "Improper draw command.");
    in_or_not(command, 4, "Improper draw command.", num_rows, num_cols, board, 1, 2, 0);

    if( command[1][0] == '2' && command[2][0] == '2' && command[3][0] == '4' && command[4][0] == '8') {
      printf("Cannot draw the line as it is not straight.");
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);

    }
    slopeFunct(command, board, num_rows, num_cols);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);

  }
  else if(command[0][0] == 'e'){
    // printf("In else if for e \n");
    findCorrect(board, num_rows, num_cols, command, 3, "Improper erase command.");
    in_or_not(command, 2, "Improper erase command.", num_rows, num_cols, board, 1, 2, 1);
    erase_point(command, board, num_rows, num_cols);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }
  else if(command[0][0] == 'r'){
    // printf("In else if for r \n");
    if( ((atoi(command[1]) <= 0)) || ((atoi(command[2]) <= 0)) ) {
      printf("Improper resize command.\n");
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }
    resize_(command, board, num_rows, num_cols);
    num_rows = atoi(command[1] );
    num_cols = atoi(command[2] );

    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);

  }

  else if(command[0][0] == 'a'){
    // printf("In else if for a \n");
    findCorrect(board, num_rows, num_cols, command, 3, "Improper add command.");

    if( strcmp(command[1], "r") == 0){
      in_or_not(command, 2, "Improper add command.", num_rows, num_cols, board, 2, 0, -1);


      addRow(command, board, num_rows, num_cols);
      num_rows = num_rows + 1;
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }
    else if( strcmp(command[1], "c") == 0){
      in_or_not(command, 2, "Improper add command.", num_rows, num_cols, board, 0, 2, -1);

      addColumn(command, board, num_rows, num_cols);
      num_cols = num_cols + 1;
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);

    }
    else{
      printf("Improper add command.\n");
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }
  }
  else if(command[0][0] == 'd'){
    // printf("In else if for d \n");
    findCorrect(board, num_rows, num_cols, command, 3, "Improper delete command.");
    if(strcmp(command[1], "r") == 0){
      in_or_not(command, 2, "Improper delete command.", num_rows , num_cols, board, 2, 0, 1);

      deleteRow(command, board, num_rows, num_cols);

      num_rows = num_rows - 1;
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }
    else if(strcmp(command[1], "c") == 0){
      // printf("In else if for c \n");
      in_or_not(command, 2, "Improper delete command.", num_rows , num_cols, board, 0, 2, 1);

      deleteColumn(command, board, num_rows, num_cols);

      num_cols = num_cols - 1;
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }
    else{
      printf("Improper delete command.\n");
      print_board(board, num_rows, num_cols);
      what_command(board, num_rows, num_cols);
    }

  }

  else if(command[0][0] == 's'){
    // printf("In else if for s \n");
    findCorrect(board, num_rows, num_cols, command, 2, "Improper save command or file could not be created.");
    save_file(board, num_rows, num_cols, command[1]);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }
  else if(command[0][0] == 'l'){
    // printf("In else if for l \n");
    findCorrect(board, num_rows, num_cols, command, 2, "Improper load command or file could not be created.");
    load_file(board, num_rows, num_cols, command[1]);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }
  //else if(command[0] == 'l'){}
}

void findCorrect(char** board, int num_rows, int num_cols, char** command, int argsNeed, char* warning){
  // printf("In find correct function \n");
  if(validityCommandChecker(command) != argsNeed){
    printf("%s\n", warning);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }
}

/*
printf("The number of rows is not an integer.\n");
printf("The number of rows is less than 1.\n");

printf("The number of columns is not an integer.\n");
printf("The number of columns is less than 1.\n");

"Improper draw command.\n"
"Improper resize command.\n"
"Improper erase command.\n"
"Improper add command.\n"
"Improper delete command.\n"
"Improper save command or file could not be created.\n"
"Improper load command or file could not be opened.\n"*/

//while(check_Valid(Argsread, Argsneed, board, num_rows, num_cols, blank_space, commandGame, RC, position, cols, rows, fileName,  row_X, row_Y, col_X, col_Y) == true);

char** check_Valid(){
  // printf("In check valid function \n");
  int size = 5;
  char* user_command = (char*)malloc(size*sizeof(char));
  int i = 0;
  int j = 0;

  printf("Enter your command: ");

  do {
    scanf("%c", &user_command[i]);
    if (user_command[i] == '\n') {
      user_command = (char*)realloc(user_command, i*sizeof(char));

      user_command[i] = '\0';
      break; //breaks out of loop
    }
    else {
      i++;
      if(i > size){
        size *= 2;
        user_command = (char*)realloc(user_command, size*sizeof(char));
      }
    }
  }
  while (true);
  char* curr_string = strtok (user_command, " ");
  char** all_commands = (char**)malloc(30*sizeof(char*));

  do {
    all_commands[j] = curr_string;
    curr_string = strtok(NULL, " ");
    j++;
  } while (curr_string != NULL);
  return all_commands;
}

void in_or_not(char** command, int numNeed, char* error_statement, int num_rows, int num_cols, char** board, int row_num, int col_num, int offset){
  // printf("In in or not function \n");
  int i;
  if(row_num != 0){
    for(i = row_num; i <= numNeed; i+=2){
      if(atoi(command[i]) > (num_rows - offset)  || atoi(command[i]) < 0){
        printf("%s\n", error_statement);
        print_board(board, num_rows, num_cols);
        what_command(board, num_rows, num_cols);

      }
    }
  }
  if(col_num != 0){
    for(i = col_num; i <= numNeed; i+=2){
      if(atoi(command[i]) > (num_cols - offset) || atoi(command[i]) < 0){
        printf("%s\n", error_statement);
        print_board(board, num_rows, num_cols);
        what_command(board, num_rows, num_cols);

      }
    }
  }
}

int validityCommandChecker(char** command){
  // printf("In validity command checker function\n");
  int i = 0;
  int count = 0;
  while(command[i] != NULL){
    count++;
    i++;
  }
  return count;
}

void resize_(char** command, char** board, int num_rows, int num_cols){
  //printf("Reached resize function\n");
  // printf("num_rows = %d, num_cols = %d\n", num_rows, num_cols);
  //print_board(board, num_rows, num_cols);
  int tempCols = atoi(command[2]);
  int tempRows = atoi(command[1]);
  //char **tempBoard= (char**) malloc(*num_rows * sizeof(char*));
  //tempBoard = board;
  //print_board(tempBoard, num_rows, num_cols);
  //board = (char**) realloc(board, nRows * sizeof(char*));
  //printf("hi\n");
  if(tempCols > num_cols){
    for(int x = 0; x < num_rows; x++){
      board[x] = (char*)realloc(board[x], tempCols * sizeof(char));
      for(int y = num_cols; y < tempCols; y++){
        board[x][y] = '*';
      }
    }
  }
  if(tempRows < num_rows){
    board = (char**)realloc(board, tempRows * sizeof(char*));
  }
  if(tempCols < num_cols) {
    for (int x = 0; x < num_rows; x++) {
      board[x] = realloc(board[x], tempCols * sizeof(char));
    }
  }
  if(tempRows > num_rows){
    int x;
    int y;
    board = (char**)realloc(board, tempRows * sizeof(char*));
    for(x = num_rows-1; x < tempRows; x++){
      board[x] = (char*)realloc(board[x], num_rows * sizeof(char));
      for(y = 0; y < num_cols; y++){
        board[x][y] = '*';
      }
    }
  }
  free(board);
}

void addColumn(char** command, char** board, int num_rows, int num_cols){
  // printf("Entered Add Single Col\n");

  int x, y;
  int tempCols = num_cols+1;
  for(int x = 0; x < num_rows; x++){
    board[x] = (char*)realloc(board[x], tempCols * sizeof(char));
    for(int y = num_cols; y < tempCols; y++){
      board[x][y] = '*';
    }
  }
  for(y = num_cols; y > atoi(command[2]); y--){
    for(x = 0; x <num_rows; x++){
      board[x][y] = board[x][y-1];
    }
  }
  for(x=0; x< num_rows; x++){
    board[x][atoi(command[2])] = '*';
  }
}


void addRow(char** command, char** board, int num_rows, int num_cols){
  // printf("Reached add row function\n");
  int x,y;
  int tempRows = num_rows + 1;
  board = (char**)realloc(board, tempRows * sizeof(char*));
  for(x = num_rows; x < tempRows; x++){
    board[x] = (char*)realloc(board[x], num_cols * sizeof(char));
    for(y = 0; y < num_cols; y++){
      board[x][y] = '*';
    }
  }
  for(int a = num_rows; a > atoi(command[2]); a--){
    for(int b = 0; b < num_cols; b++){
      board[a][b] = board[a-1][b];
    }
  }
  for(int b = 0; b < num_cols; ++b){
    board[atoi(command[2])][b] = '*';
  }
}

void deleteRow(char** command, char** board, int num_rows, int num_cols){
  // printf("Reached delete row function\n");
  int a, b;
  for(a = atoi(command[2]); a < num_rows - 1; a++){
    for(b = 0; b < num_cols; b++){
      board[a][b] = board[a+1][b];
    }
  }
  int tempRows = num_rows - 1;
  board = (char**)realloc(board, tempRows * sizeof(char*));

}

void deleteColumn(char** command, char** board, int num_rows, int num_cols){
  // printf("Reached delete column function\n");
  int a, b;
  for(b = atoi(command[2]); b < num_cols - 1; b++){
    for(a = 0; a < num_rows; a++){
      board[a][b] = board[a][b+1];
    }
  }
  for(int x = 0; x < num_rows; x++){
    int tempCols = num_cols - 1;
    board[x] = realloc(board[x], tempCols * sizeof(char));
  }
}


void save_file(char** board, int num_rows, int num_cols, char* file){
  char str[1000000];
  FILE *fp = fopen(str, "w"); //pointer to file
  if(!fp) { //opened file
    return;
  }
  fprintf(fp, "%d %d\n", num_rows, num_cols);
  for(int x = 0; x < num_rows; x++) {
    for(int y = 0; y < num_cols; y++) {
      fprintf(fp, "%c", board[x][y]);
    }
  } //close
  fclose(fp);
}

void load_file(char** board, int num_rows, int num_cols, char* file){
  // printf("Reached load filename function");
  FILE* fp; // File pointer
  //FILE* fp = NULL;
  // Try to open file
  // printf("Opening file %s\n", fileName);

  // inFile = fopen(fileName, "r");
  // fp = fopen("/Users/chelsysesma/Desktop/0-test.txt", "r");
  fp = fopen(file, "r+");


  if(fp == NULL){
    // printf("Could not open file.\n");
    printf("Failed to open file: %s\n", file);
    print_board(board, num_rows, num_cols);
    what_command(board, num_rows, num_cols);
  }

  //write into it
  // make loop
  free(board[num_rows]);
  char **tempBoard= (char**) malloc(num_rows * sizeof(char*));
  //fscanf(fp, "%c", &(*ptBroad)[0][0]);
  for(int x = 0; x < num_rows; x++) {
    for(int y = 0; x < num_cols; y++) {
      fscanf(fp, " %c", &(tempBoard)[x][y]);
    }
  }

  // Done so close file
  // printf("Closing file\n");
  fclose(fp);
  return;
}


void erase_point(char** command, char** board, int num_rows, int num_cols){
  // printf("Reached erase space function\n");
  // printf("%d %d\n", num_rows, num_cols);
  int col = atoi(command[2]);
  int row = atoi(command[1]);
  if(board[row][col] != '*'){
    board[row][col] = '*';
  }
  //print_board(board, num_rows, num_cols);
}

void quitANDclear(char** board, int num_rows, int num_cols){
  // printf("Reached quit and clear function\n");
  for(int r = 0; r < num_rows; r++){
    free(board[r]);
  }
  free(board);
  //board = NULL
  // printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.");
  exit(0);
  /*if (checkEnd != '\n') {
    printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.");
    print_board(board, num_rows, num_cols);
  } */
}
