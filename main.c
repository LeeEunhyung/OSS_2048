#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32

#include "InitGame.h"
#include <conio.h>

#elif __linux__

#include "InitGame.c" //HACK: gcc 컴파일러에 InitGame.h를 추가하지 못함 -> 함수 정의 부분인 InitGame.c를 바로 링크
#include <termios.h>

#endif //windowsOS나 linuxOS에 구애받지 않게 하기위해 추가

/*
* 저장소 명칭: OSS_2048
* 프로젝트 목적: C Code로 작성된 2048 game을 git과 github를 통해 가독성 중심의 Clean code로 개선
* 작성자: LeeEunhyung(이은형), wlals7217(전지민), 1000peach(천승아)
* 원저장소 명칭: 2048-game
* 원파일명: 2048.c
* 원작성자: mustafakbulut
* 원작성일: 2019/3/16
* 출처: https://github.com/mustafakbulut/2048-game
*/

int main() {


	/*
	- int **cur_board: 현재 gameboard 나타내는 2차원 배열
	- int **pre_board: 이전(한 타임 전) gameboard 나타내는 2차원 배열
	- int size: cur_board의 크기 (size X size)
	- int cur_score: 현재 점수(=sum) 저장
	- int pre_score: 이전 점수 저장
	- int high_score: 게임 중 가장 높은 점수 저장
	- int *emptyIndex: 랜덤 수(2 or 4) 생성 시 cur_board에서 값이 없는 빈 곳의 위치들을 저장
	- int isWin: 게임의 승패 여부
	- int i, j: 반복문 실행 시 Index
	*/

	int **cur_board = NULL;
	int **pre_board = NULL;
	int size = 0;
	int cur_score = 0;
	int pre_score = 0;
	int high_score = 0;
	int *emptyIndex = NULL;
	int isWin = 0;
	int j = 0;
	int i = 0;

	printf("Enter the desired game board size: ");
	scanf("%d", &size);

	cur_board = setUp(cur_board, size);//메모리 할당 후 값 0으로 초기화
	pre_board = allocateArr(pre_board, size);//메모리 할당
	emptyIndex = (int *)malloc(sizeof(int)*(size*size));

	srand((unsigned int)time(NULL));


	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (j == 0)
				printf("|");
			printf(" %4d   |", cur_board[i][j]);
		}
		printf("\n");
	}
	printf("\nThe current state\n");
	printf("Score:%d\nHigh Score=%d", cur_score, high_score);
	printf("\nPress w to move up,press a to move left,press s to move down,press d to move right,\npress e to finish the game, press x to refresh,press r to restore \n");

	while (key != 'e') {
		key = _getch();
		srand((unsigned int)time(NULL));

		if (key == 'w' || key == 'a' || key == 's' || key == 'd') {
			save(cur_board, pre_board, &cur_score, &pre_score, size);

			move(key, cur_board, pre_board, size);

			spawnBlock(cur_board, emptyIndex, size);

			printBoard(cur_board, pre_board, &cur_score, &pre_score, &high_score, size);
		}
		if (key == 'x') {
			refreshGame(cur_board, &cur_score, size);

			system("CLS");
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					if (j == 0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					if (j == 0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key == 'r') {
			system("CLS");
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					if (j == 0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", cur_score, high_score);
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					if (j == 0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);

			undo(cur_board, pre_board, size);
		}

		if(isGameOver(cur_board, size) == 1)
		{
			break;
		}

		i = 1;
		j = 1;
		isWin = 0;
		while (i < size && isWin == 0) {
			while (j < size && isWin == 0) {
				if (cur_board[i][j] == 2048) {
					isWin = 1;
				}
				j += 1;
			}
			i += 1;
		}
		printf("\nPress 8 to move up,press 4 to move left,press move 2 to down,press 6 to move right,\npress e to finish the game,press x to refresh,press r to restore \n");
		if (isWin == 1) {
			printf("YOU WON!\n");
			key = 'e';
		}
	}
	system("CLS");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (j == 0)
				printf("|");
			printf(" %4d   |", cur_board[i][j]);
		}
		printf("\n");
	}
	printf("\nThe current state\n");
	if (isWin != 1) {
		printf("\nYOU LOSE!");
	}
	printf("\n \n GAME OVER!\n Score: %d \n High Score:%d", cur_score, high_score);
	_getch();
	return 0;
}

