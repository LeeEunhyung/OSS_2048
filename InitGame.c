#include "InitGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__

#include <termios.h>
int _getch()
{
  int ch;

  struct termios buf;
  struct termios save;

  tcgetattr(0, &save);
  buf = save;

  buf.c_lflag &= ~(ICANON|ECHO);
  buf.c_cc[VMIN] = 1;
  buf.c_cc[VTIME] = 0;

  tcsetattr(0, TCSAFLUSH, &buf);

  ch = getchar();

  tcsetattr(0, TCSAFLUSH, &save);

  return ch;
}

#endif //_getch가 정의된 conio 라이브러리가 없기 때문에 _getch 함수를 직접 정의

int** allocateArr(int **arr, int size) {
	int i=0, j=0;

	arr=(int **)malloc(sizeof(int *)*size);
	for (i=0; i<size; i++) {
		arr[i]=(int *)malloc(sizeof(int)*size);
	}
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			arr[i][j]=0;
		}
	}
	return arr;
}//arr에 size만큼 메모리 할당하고 0으로 초기화

int** setUp(int **arr, int size) {
	int k=0, i=0, j=0;
	int random=0;

	key=0;
	arr=allocateArr(arr, size);
	for (k=0; k<2; k++) {
		i=rand()%size;
		j=rand()%size;
		random=((rand()%2)+1)*2;
		arr[i][j]=random;
	}
	return arr;
}//메모리 할당된 arr에 랜덤 수 2개 생성

void printBoard() {}
void findEmpty() {}

void inputKey() {}
void refreshGame() {}
void undo() {}

void moveRight() {}
void moveLeft() {}
void moveUp() {}
void moveDown() {}

void pushRight() {}
void pushLeft() {}
void pushUp() {}
void pushDown() {}

void mergeRight() {}
void mergeLeft() {}
void mergeUp() {}
void mergeDown() {}

