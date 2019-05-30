#ifndef _INITGAME_H_

#define _INITGAME_H_

#ifdef _WIN32

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

void textcolor(int foreground, int background);

#define ARROW -32

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
//방향키 값 define

#elif __linux__

#define F_BLACK "[1;30m"
#define F_WHITE "[1;37m"
#define F_RED "[1;31m"

#define B_BLACK "[40m"
#define B_WHITE "[47m"
#define B_RED "[41m"
#define B_GREEN "[42m"
#define B_YELLOW "[43m"
#define B_BLUE "[44m"
#define B_PURPLE "[45m"
#define B_CYAN "[46m"
//색상 값 define

char _getch();

#define ARROW 27
#define SECOND_ARROW 91

#define LEFT 'D'
#define RIGHT 'C'
#define UP 'A'
#define DOWN 'B'
//방향키 값 define

#endif

#define MAX_BOARD_SIZE 1000

#define TRUE 1
#define FALSE 0

#define CURRENT 1
#define PREVIOUS 0
//gameboard 종류 define

char key;

void clearWindow();

int inputBoardSize();

int** allocateArr(int **arr, int size);
int** setUp(int **arr, int size);

void tilesEmptyBoard(int **board, int size);
void spawnTile(int **cur_board, int *empty_index, int size);

void refreshGame(int **cur_board, int **pre_board, int size);
void undo(int **cur_board, int **pre_board, int size);

int move(int **cur_board, int **pre_board, int size);

void push(int **cur_board, int size);
void merge(int **cur_board, int size);

void save(int **cur_board, int **pre_board, int *cur_score, int *pre_score, int size);

void updateScore(int **cur_board, int *cur_score, int *high_score, int size);

int checkMove(int **cur_board, int **pre_board, int size);

int isGameOver(int **cur_board, int size);
int isArrowKey();
int isWin(int **board, int size);

void printBoard(int **board, int size);
void printScore(int **board, int score, int save_score, int menu);
void isWinPrint(int **board, int score, int high_score, int size, int win_result);

#endif
