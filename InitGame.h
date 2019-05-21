#pragma once

#ifdef __linux__

int _getch();

#endif

char key;

int** setUp(int **arr, int size);
int** allocateArr(int **arr, int size);
void printBoard();
void findEmpty();

void inputKey();
void refreshGame();
void undo();

void moveRight();
void moveLeft();
void moveUp();
void moveDown();

void pushRight();
void pushLeft();
void pushUp();
void pushDown();

void mergeRight();
void mergeLeft();
void mergeUp();
void mergeDown();

