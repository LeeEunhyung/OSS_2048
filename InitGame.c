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


void save(int **cur_board, int **pre_board, int *cur_scroe, int *pre_score);
void push(int **cur_board, int vecx, int vecy);
void merge(int **cur_board, int vecx, int vecy);
bool checkMove(int **cur_board, int **pre_board);
void printBoard(int **cur_board, int **pre_board, int *cur_score, int *pre_score);

int move(char key, int **cur_board, int **pre_board) {
	
	int vecx = 0;
	int vecy = 0;
	
	/* 블럭이 움직이는 방향에따른 벡터값을 부여합니다. */

	switch (key) {
	case w:
		vecx = 	0;
		vecy = -1;
	break;
	case a:
		vecx = -1;
		vecy = 	0;
	break;
	case s:
		vecx = 	0;
		vecy = 	1;
	break;
	case d:
		vecx =	1;
		vecy = 	0;
	break;
	}
	
	push(cur_board, vecx, vecy);
	
	merge(cur_board, vecx, vecy);

	if(checkMove(int **cur_board, int **pre_board)){ /* 블록이  전혀 움직이지 않은 경우 
							    1을 반환하고 함수를 종료합니다.*/
		return 1;
	}
	
	push(cur_board, vecx, vecy);

}

void updateScore(int **cur_board, int *cur_score, int *high_score)



