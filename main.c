#include "InitGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32

#include <conio.h>
#include <Windows.h>

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
	- int cur_score: 현재 점수(=sum) 저장
	- int pre_score: 이전 점수 저장
	- int high_score: 게임 중 가장 높은 점수 저장
	- int *emptyIndex: 랜덤 수(2 or 4) 생성 시 cur_board에서 값이 없는 빈 곳의 위치들을 저장
	- int gameover_result: 게임 종료 여부 판단
	- int win_result: 승패 여부 판단
	- int move_result: 타일 이동 여부 판단
	- int click_X: x키 클릭 여부 판단
	- int click_R: r키 클릭 여부 판단
	- int i, j: 반복문 실행 시 Index
	*/

	int **cur_board = NULL, **pre_board = NULL;
	int size = 0;
	int cur_score = 0, pre_score = 0, high_score = 0;
	int *empty_index = NULL;
	int gameover_result = 0, win_result = 0, move_result = 0;
	int click_X = 0, click_R = 0;
	int i = 0, j = 0;

	size = inputBoardSize();

	cur_board = setUp(cur_board, size);
	pre_board = allocateArr(pre_board, size);
	updateScore(cur_board, &cur_score, &high_score, size);
	empty_index = (int *)malloc(sizeof(int) * (size * size));

	srand((unsigned int)time(NULL));

	printBoard(cur_board, size);
	printScore(cur_board, cur_score, high_score, CURRENT);

	while (key != 'e' && key != 'E') {
		key = _getch();

		srand((unsigned int)time(NULL));

		if (isArrowKey()) {
			save(cur_board, pre_board, &cur_score, &pre_score, size);

			move_result = move(cur_board, pre_board, size);

			if (move_result) {
				spawnTile(cur_board, empty_index, size);
			}
			move_result = FALSE;

			clearWindow();

			printBoard(pre_board, size);
			printScore(pre_board, pre_score, high_score, PREVIOUS);

			updateScore(cur_board, &cur_score, &high_score, size);

			printBoard(cur_board, size);
			printScore(cur_board, cur_score, high_score, CURRENT);

			click_R = FALSE;
			click_X = FALSE;
		}
		else if (key == 'x' || key == 'X') {
			refreshGame(cur_board, pre_board, size);

			cur_score = 0;
			pre_score = 0;

			clearWindow();

			printBoard(pre_board, size);
			printScore(pre_board, pre_score, high_score, PREVIOUS);

			printBoard(cur_board, size);
			printScore(cur_board, cur_score, high_score, CURRENT);

			click_X = TRUE;
		}
		else if (key == 'r' || key == 'R') {
			if (!click_R && !click_X) {
				undo(cur_board, pre_board, size);

				if (high_score == cur_score) {
					high_score = pre_score;
				}
				cur_score = pre_score;
				pre_score = 0;

				clearWindow();

				printBoard(pre_board, size);
				printScore(pre_board, pre_score, high_score, PREVIOUS);

				printBoard(cur_board, size);
				printScore(cur_board, cur_score, high_score, CURRENT);
			}
			click_R = TRUE;
		}

		gameover_result = isGameOver(cur_board, size);
		if (gameover_result) {
			break;
		}

		win_result = isWin(cur_board, size);
		if (win_result) {
			break;
		}
	}

	updateScore(cur_board, &cur_score, &high_score, size);

	clearWindow();
	isWinPrint(cur_board, cur_score, high_score, size, win_result);

	_getch();

	return 0;
}
