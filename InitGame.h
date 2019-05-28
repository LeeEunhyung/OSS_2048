#pragma once

#ifdef __linux__

int _getch();

#endif

#define CURRENT 1
#define PREVIOUS 0
//gameboard 종류 define

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTRED 12 
#define YELLOW 14 
#define WHITE 15
//색상 값 define

char key;

int** setUp(int **arr, int size);
int** allocateArr(int **arr, int size);

void findEmpty();

void inputKey();
void refreshGame();
void undo();

void save(int **cur_board, int **pre_board, int *cur_scroe, int *pre_score, int size);

void push(int **cur_board, char key, int size);

void merge(int **cur_board, char key, int size);

void spawnBlock(int **cur_board, int *emptyIndex, int size);

int checkMove(int **cur_board, int **pre_board, int size);

void printBoard(int **board, int size);
void textcolor(int foreground, int background);

int move(char key, int **cur_board, int **pre_board, int size);

void updateScore(int **cur_board, int *cur_score, int *high_score, int size);

