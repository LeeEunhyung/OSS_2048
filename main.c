#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

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
	- int i, j: 반복문 실행 시 Index
	*/

	int **cur_board = NULL;
	int **pre_board = NULL;
	int size = 0;
	int cur_score = 0;
	int pre_score = 0;
	int high_score = 0;
	int *emptyIndex = NULL;
	int j = 0;
	int i = 0;

	system("mode con lines=20 cols=90");

	printf("Enter the desired game board size: ");
	scanf("%d", &size);

	cur_board = setUp(cur_board, size);//메모리 할당 후 값 0으로 초기화
	pre_board = allocateArr(pre_board, size);//메모리 할당
	updateScore(cur_board, &cur_score, &high_score, size);
	emptyIndex = (int *)malloc(sizeof(int)*(size*size));

	srand((unsigned int)time(NULL));

	printBoard(cur_board, size);
	printScore(cur_board, cur_score, high_score, CURRENT);

	while (key != 'e') {
		key = _getch();
		srand((unsigned int)time(NULL));

		if (isArrowKey(key)) {
			save(cur_board, pre_board, &cur_score, &pre_score, size);

			move(key, cur_board, pre_board, size);

			spawnBlock(cur_board, emptyIndex, size);

			system("CLS");
			printBoard(pre_board, size);
			printScore(pre_board, pre_score, high_score, PREVIOUS);

			updateScore(cur_board, &cur_score, &high_score, size);

			printBoard(cur_board, size);
			printScore(cur_board, cur_score, high_score, CURRENT);
		}
		if (key == 'x') {
			refreshGame(cur_board, &cur_score, size);

			system("CLS");
			printBoard(pre_board, size);
			printScore(pre_board, pre_score, high_score, PREVIOUS);

			printBoard(cur_board, size);
			printScore(cur_board, cur_score, high_score, CURRENT);
		}
		if (key == 'r') {
			system("CLS");

			printBoard(cur_board, size);
			printScore(cur_board, cur_score, high_score, PREVIOUS);

			printBoard(pre_board, size);
			printScore(pre_board, pre_score, high_score, CURRENT);

			undo(cur_board, pre_board, size);
		}
		if (isGameOver(cur_board, size) == 1) {
			break;
		}
		if (isWin(cur_board, size)) {
			break;
		}
	}
	updateScore(cur_board, &cur_score, &high_score, size);
	isWinPrint(cur_board, cur_score, high_score, size, isWin(cur_board, size));
	_getch();
	return 0;
}

