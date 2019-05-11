#include "InitGame.h"
#include <stdlib.h>
#include <string.h>

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
