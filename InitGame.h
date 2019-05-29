#ifndef _INITGAME_H_

#define _INITGAME_H_

#ifdef __linux__

int _getch();

#define ARROW 27

#define LEFT 'D'
#define RIGHT 'C'
#define UP 'A'
#define DOWN 'B'

#elif _WIN32

void textcolor(int foreground, int background);

#define ARROW -32

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

#endif

#define SECOND_ARROW 91

#define TRUE 1
#define FALSE 0

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

void clearWindow();

int inputBoardSize();
int** allocateArr(int **arr, int size);
int** setUp(int **arr, int size);
void tilesEmptyBoard(int **board, int size);

void findEmpty();

void refreshGame(int **cur_board, int **pre_board, int size);
void undo(int **cur_board, int **pre_board, int size);
int isGameOver(int **cur_board, int size);

void save(int **cur_board, int **pre_board, int *cur_score, int *pre_score, int size);

void push(int **cur_board, char key, int size);

void merge(int **cur_board, char key, int size);

void spawnBlock(int **cur_board, int *emptyIndex, int size);

int checkMove(int **cur_board, int **pre_board, int size);

void printBoard(int **board, int size);

void printScore(int **board, int score, int save_score, int menu);

int move(char key, int **cur_board, int **pre_board, int size);

void updateScore(int **cur_board, int *cur_score, int *high_score, int size);

int isArrowKey(char key);

int isWin(int **board, int size);
void isWinPrint(int **board, int score, int high_score, int size, int win_result);

#endif
