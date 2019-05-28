#include "InitGame.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifdef _WIN32

#include <conio.h>

#elif __linux__

#include <termios.h>

#endif //windowsOS나 linuxOS에 구애받지 않게 하기위해 추가, linux는 특정 명령어를 통해 실행(명령어는 README.md에 기술)

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
	- int sum: cur_board의 값 모두 더한 결과 저장
	- int cur_score: 현재 점수(=sum) 저장
	- int pre_score: 이전 점수 저장
	- int high_score: 게임 중 가장 높은 점수 저장
	- int *emptyIndex: 랜덤 수(2 or 4) 생성 시 cur_board에서 값이 없는 빈 곳의 위치들을 저장
	- int randomNum: 랜덤 수 저장
	- int emptyTile: 현재 비어있는 타일의 개수 저장 (emptyIndex의 크기)
	- int randomIndex: emptyIndex에서 추출된 임의의 빈 곳 위치를 저장-> 이 위치에 랜덤 수 넣음
	- int isGameover: 게임 종료 여부 저장
	- int isWin: 게임의 승패 여부
	- int i, j, k: 반복문 실행 시 Index
	- int flag: 이동 후 인접 타일 더할 때 두 번 이상 반복해 더함 방지
	*/

	int **cur_board = NULL, **pre_board = NULL, *emptyIndex = NULL;
	int size, cur_score, high_score, pre_score, sum;
	int isGameover = 0, isWin;
	int emptyTile = 1, randomNum, randomIndex = 0;
	int i, j, k, flag = 0;

	printf("Enter the desired game board size: ");
	scanf("%d", &size);

	cur_board = setUp(cur_board, size);//메모리 할당 후 값 0으로 초기화
	pre_board = allocateArr(pre_board, size);//메모리 할당
	emptyIndex = (int *)malloc(sizeof(int)*(size*size));

	srand((unsigned int)time(NULL));

	pre_score = 0;
	cur_score = 0;
	high_score = 0;
	sum = 0;

	printBoard(cur_board, size, cur_score, high_score, 1);

	while (key != 'e') {
		key = _getch();
		srand((unsigned int)time(NULL));

		if (key == 'd') {
			pre_score = cur_score;
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}

			move(key, cur_board, pre_board, size);

			emptyTile = 0;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = ((rand() % 2) + 1) * 2;
			cur_board[i][j] = randomNum;

			sum = 0;
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score > high_score) {
				high_score = cur_score;
			}
			printBoard(pre_board, size, pre_score, high_score, 0);
			printBoard(cur_board, size, cur_score, high_score, 1);
		}
		if (key == 'a') {
			pre_score = cur_score;

			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}

			move(key, cur_board, pre_board, size);

			emptyTile = 0;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = ((rand() % 2) + 1) * 2;
			cur_board[i][j] = randomNum;

			sum = 0;
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score > high_score) {
				high_score = cur_score;
			}
			printBoard(pre_board, size, pre_score, high_score, 0);
			printBoard(cur_board, size, cur_score, high_score, 1);
		}
		if (key == 's') {
			pre_score = cur_score;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}

			move(key, cur_board, pre_board, size);

			emptyTile = 0;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = ((rand() % 2) + 1) * 2;
			cur_board[i][j] = randomNum;

			sum = 0;
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					sum += cur_board[i][j];
				}
			}

			cur_score = sum;
			if (cur_score > high_score) {
				high_score = cur_score;
			}
			printBoard(pre_board, size, pre_score, high_score, 0);
			printBoard(cur_board, size, cur_score, high_score, 1);
		}
		if (key == 'w') {
			pre_score = cur_score;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}

			move(key, cur_board, pre_board, size);

			emptyTile = 0;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}

			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = ((rand() % 2) + 1) * 2;
			cur_board[i][j] = randomNum;

			sum = 0;
			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score > high_score) {
				high_score = cur_score;
			}
			printBoard(pre_board, size, pre_score, high_score, 0);
			printBoard(cur_board, size, cur_score, high_score, 1);
		}
		if (key == 'x') {
			cur_score = 0;
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j <= size - 1; j++) {
					cur_board[i][j] = 0;
				}
			}
			printBoard(pre_board, size, pre_score, high_score, 0);
			printBoard(cur_board, size, cur_score, high_score, 1);
		}
		if (key == 'r') {
			printBoard(cur_board, size, cur_score, high_score, 0);
			printBoard(pre_board, size, pre_score, high_score, 1);

			for (i = 0; i < size; i++) {
				for (j = 0; j < size; j++) {
					cur_board[i][j] = pre_board[i][j];
				}
			}
		}
		isGameover = 0;
		for (i = 0; i <= size - 1; i++) {
			for (j = 0; j <= size - 1; j++) {
				if (cur_board[i][j] == 0) {
					isGameover = 1;
				}
			}
		}
		for (i = 0; i <= size - 2; i++) {
			for (j = 0; j <= size - 2; j++) {
				if (i == size - 1 && j != size - 1 && cur_board[i][j] == cur_board[i][j + 1]) {
					isGameover = 1;
				}
				if (j == size - 1 && i != size - 1 && cur_board[i][j] == cur_board[i + 1][j]) {
					isGameover = 1;
				}
				if (cur_board[i][j] == cur_board[i + 1][j] || cur_board[i][j] == cur_board[i][j + 1]) {
					isGameover = 1;
				}
			}
		}
		if (isGameover != 1) {
			key = 'e';
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

