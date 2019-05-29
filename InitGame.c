#include "InitGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32

#include <Windows.h>

void textcolor(int foreground, int background) {
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}//글자 배경색 변경

void printBoard(int **board, int size) {
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			switch (board[i][j])
			{
			case 2:
				textcolor(WHITE, RED);
				break;
			case 4:
				textcolor(WHITE, BLUE);
				break;
			case 8:
				textcolor(WHITE, GREEN);
				break;
			case 16:
				textcolor(BLACK, YELLOW);
				break;
			case 32:
				textcolor(BLACK, WHITE);
				break;
			case 64:
				textcolor(WHITE, BROWN);
				break;
			case 128:
				textcolor(WHITE, MAGENTA);
				break;
			case 256:
				textcolor(BLACK, CYAN);
				break;
			case 512:
				textcolor(WHITE, DARKGRAY);
				break;
			case 1024:
				textcolor(WHITE, LIGHTBLUE);
				break;
			case 2048:
				textcolor(WHITE, LIGHTRED);
				break;
			default:
				break;
			}//숫자에 따라 타일 색 설정
			if (board[i][j]) {
				printf("| %4d    |", board[i][j]);
			}
			else {
				printf("|         |");
			}
			textcolor(15, 0);
		}
		printf("\n");
	}
}//숫자마다 색을 구분하여 gameboard 상태를 출력

#elif __linux__

#include <termios.h>

int _getch() {
	int ch;

	struct termios buf;
	struct termios save;

	tcgetattr(0, &save);
	buf = save;

	buf.c_lflag &= ~(ICANON | ECHO);
	buf.c_cc[VMIN] = 1;
	buf.c_cc[VTIME] = 0;

	tcsetattr(0, TCSAFLUSH, &buf);

	ch = getchar();

	tcsetattr(0, TCSAFLUSH, &save);

	return ch;
}

void printBoard(int **board, int size) {
	int i, j;
	char *foreground = "\0";
	char *background = "\0";

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			switch (board[i][j])
			{
			case 2:
			 	foreground = F_WHITE;
				background = B_RED;
				break;
			case 4:
				foreground = F_WHITE;
				background = B_BLUE;
				break;
			case 8:
				foreground = F_WHITE;
				background = B_GREEN;
				break;
			case 16:
				foreground = F_BLACK;
				background = B_YELLOW;
				break;
			case 32:
				foreground = F_BLACK;
				background = B_WHITE;
				break;
			case 64:
				foreground = F_WHITE;
				background = B_BLACK;
				break;
			case 128:
				foreground = F_WHITE;
				background = B_PURPLE;
				break;
			case 256:
				foreground = F_BLACK;
				background = B_CYAN;
				break;
			case 512:
				foreground = F_BLACK;
				background = B_GREEN;
				break;
			case 1024:
				foreground = F_BLACK;
				background = B_BLUE;
				break;
			case 2048:
				foreground = F_RED;
				background = B_YELLOW;
				break;
			default:
				break;
			}//숫자에 따라 색 설정
			if (board[i][j]) {
				printf("\033%s\033%s", foreground, background);
				printf("| %4d    |", board[i][j]);
				if (i == size - 1 && j == size - 1) {
					printf("\033[0m");
					printf(" ");
				}
			}
			else {
				printf("\033[0m");
				printf("|         |");
			}
		}
		printf("\033[0m");
		printf("\n");
	}
}

#endif //각 OS 환경에 따른 필요 함수를 각각 정의

void clearWindow() {
#ifdef _WIN32

	system("CLS");

#elif __linux__

	system("clear");

#endif
}

int inputBoardSize() {
	int input_size = 0;

	while (input_size <= 1) {
		printf("\n     >>>>>>> 2 0 4 8 GAME <<<<<<<\n");
		printf("\n  Please write a number greater than 1!\n");
		printf("\n    => Enter the desired game board size: ");
		scanf("%d", &input_size);
		clearWindow();
	}
	return input_size;
}//게임 시작 시 size X size 행렬의 조건에 따라 gameboard size를 입력 받음

int** allocateArr(int **arr, int size) {
	int i = 0, j = 0;

	arr = (int **)malloc(sizeof(int *)*size);
	for (i = 0; i < size; i++) {
		arr[i] = (int *)malloc(sizeof(int)*size);
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}//arr에 size만큼 메모리 할당하고 0으로 초기화

void tilesEmptyBoard(int **board, int size) {
	int k = 0, i = 0, j = 0;
	int random = 0;

	for (k = 0; k < 2; k++) {
		i = rand() % size;
		j = rand() % size;
		random = ((rand() % 2) + 1) * 2;
		board[i][j] = random;
	}
}//처음 빈 gameboard에 랜덤 수 2개 생성

int** setUp(int **arr, int size) {
	key = 0;
	arr = allocateArr(arr, size);
	tilesEmptyBoard(arr, size);

	return arr;
}//arr에 메모리를 할당한 후 랜덤 수 2개 생성하여 return

void findEmpty() {}

void refreshGame(int **cur_board, int **pre_board, int size) {
	int i = 0, j = 0;
	int cnt = 0;
	int random = 0;

	for (i = 0; i <= size - 1; i++) {
		for (j = 0; j <= size - 1; j++) {
			cur_board[i][j] = 0;
			pre_board[i][j] = 0;
		}
	}
	for (cnt = 0; cnt < 2; cnt++) {
		i = rand() % size;
		j = rand() % size;
		random = ((rand() % 2) + 1) * 2;
		cur_board[i][j] = random;
	}
} //현재 GameBoard를 초기화하고 게임을 재 시작
void undo(int **cur_board, int **pre_board, int size) {
	int i = 0, j = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cur_board[i][j] = pre_board[i][j];
			pre_board[i][j] = 0;
		}
	}
} //최근 방향키 움직임을 취소하고 이전의 상태로 복원
int isGameOver(int **cur_board, int size) {
	int i = 0, j = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (cur_board[i][j] == 0) {
				return 0;
			}
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++) {
			if (cur_board[i][j] == cur_board[i][j + 1]) {
				return 0;
			}
		}
	}
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size; j++) {
			if (cur_board[i][j] == cur_board[i + 1][j]) {
				return 0;
			}
		}
	}

	return 1;
} //반환값이 1이면 게임 오버되어 키 입력 불가

void save(int **cur_board, int **pre_board, int *cur_score_p, int *pre_score_p, int size) {
	int i = 0;
	int j = 0;

	*pre_score_p = *cur_score_p;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			pre_board[i][j] = cur_board[i][j];
		}
	}
}

void push(int **cur_board, char key, int size) {
	int k = 0;
	int i = 0;
	int j = 0;

	switch (key) {
	case 'w':
	case 'W':
	case UP:
		for (k = 0; k <= size - 2; k++) {
			for (j = 0; j <= size - 1; j++) {
				for (i = 0; i < size - 1; i++) {
					if (cur_board[i][j] == 0 && cur_board[i + 1][j] != 0) {
						cur_board[i][j] = cur_board[i + 1][j];
						cur_board[i + 1][j] = 0;
					}
				}
			}
		}

		break;
	case 'a':
	case 'A':
	case LEFT:
		for (k = 0; k <= size - 2; k++) {
			for (i = 0; i <= size - 1; i++) {
				for (j = size - 1; j > 0; j--) {
					if (cur_board[i][j] != 0 && cur_board[i][j - 1] == 0) {
						cur_board[i][j - 1] = cur_board[i][j];
						cur_board[i][j] = 0;
					}
				}
			}
		}

		break;
	case 's':
	case 'S':
	case DOWN:
		for (k = 0; k <= size - 2; k++) {
			for (j = 0; j <= size - 1; j++) {
				for (i = size - 1; i > 0; i--) {
					if (cur_board[i][j] == 0 && cur_board[i - 1][j] != 0) {
						cur_board[i][j] = cur_board[i - 1][j];
						cur_board[i - 1][j] = 0;
					}
				}
			}
		}
		break;
	case 'd':
	case 'D':
	case RIGHT:
		for (k = 0; k <= size - 2; k++) {
			for (i = 0; i <= size - 1; i++) {
				for (j = 0; j < size - 1; j++) {
					if (cur_board[i][j] != 0 && cur_board[i][j + 1] == 0) {
						cur_board[i][j + 1] = cur_board[i][j];
						cur_board[i][j] = 0;
					}
				}
			}
		}
		break;
	}
}

void merge(int **cur_board, char key, int size) {

	int i = 0;
	int j = 0;

	switch (key) {
	case 'w':
	case 'W':
	case UP:
		for (j = 0; j <= size - 1; j++) {
			for (i = 0; i < size - 1; i++) {
				if (cur_board[i][j] == cur_board[i + 1][j] && cur_board[i][j] != 0) {
					cur_board[i][j] = cur_board[i + 1][j] + cur_board[i][j];
					cur_board[i + 1][j] = 0;
					i++;
				}
			}
		}
		break;
	case 'a':
	case 'A':
	case LEFT:
		for (i = 0; i <= size - 1; i++) {
			for (j = 0; j <= size - 2; j++) {
				if (cur_board[i][j] == cur_board[i][j + 1] && cur_board[i][j] != 0) {
					cur_board[i][j] = cur_board[i][j + 1] + cur_board[i][j];
					cur_board[i][j + 1] = 0;
					j++;
				}
			}
		}
		break;
	case 's':
	case 'S':
	case DOWN:
		for (j = 0; j <= size - 1; j++) {
			for (i = size - 1; i > 0; i--) {
				if (cur_board[i][j] == cur_board[i - 1][j] && cur_board[i][j] != 0) {
					cur_board[i][j] = cur_board[i - 1][j] + cur_board[i][j];
					cur_board[i - 1][j] = 0;
					i--;
				}
			}
		}
		break;
	case 'd':
	case 'D':
	case RIGHT:
		for (i = 0; i <= size - 1; i++) {
			for (j = size - 1; j > 0; j--) {
				if (cur_board[i][j] == cur_board[i][j - 1] && cur_board[i][j] != 0) {
					cur_board[i][j - 1] = cur_board[i][j - 1] + cur_board[i][j];
					cur_board[i][j] = 0;
					j--;
				}
			}
		}
		break;
	}
}

int checkMove(int **cur_board, int **pre_board, int size) {
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (cur_board[i][j] != pre_board[i][j])
				return TRUE;
		}
	}
	return FALSE;
}//보드에 변경사항이 있는지 검사하고 변경사항이 있으면 조기리턴한다.

void printScore(int **board, int score, int save_score, int menu) {
	if (menu == CURRENT) {
		printf("\n☆ The current state ☆\n");
		printf("   Score: %d\n   High Score: %d", score, save_score);
		printf("\n   => Press w: up / Press a:left / Press s: down / Press d: right\n");
		printf("   => Press e : finish the game / Press x : refresh / Press r : restore\n");
	}
	else if (menu == PREVIOUS) {
		printf("\n★ The previous state ★\n");
		printf("   Score: %d\n   High Score: %d\n\n", score, save_score);
	}
}//menu(CURRENT, PREVIOUS)에 따라 점수 상태, 키 안내 출력

void spawnBlock(int **cur_board, int *emptyIndex, int size) {

	int emptyTile = 0;
	int randomIndex = 0;
	int randomNum = 0;
	int i = 0;
	int j = 0;

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

}

int move(char key, int **cur_board, int **pre_board, int size) {
	push(cur_board, key, size);

	merge(cur_board, key, size);

	if (!checkMove(cur_board, pre_board, size)) {
		return FALSE;
	}//블록이 전혀 움직이지 않은 경우 FALSE를 반환하고 함수를 종료. 움직이지 않았을때 다시 키를 받도록 한다.

	push(cur_board, key, size);

	return TRUE;
}//블록을 옮기고 붙어있는 블럭을 합치고 다시 한 번 블록을 옮긴다. merge 이후 생기는 틈을 매꾼다.

void updateScore(int **cur_board, int *cur_score_p, int *high_score_p, int size) {
	int i = 0;
	int j = 0;
	int sum = 0;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			sum += cur_board[i][j];
		}
	}
	*cur_score_p = sum;
	if (*cur_score_p > *high_score_p) {
		*high_score_p = *cur_score_p;
	}
}

int isArrowKey(char key) {
	int output = 0;
	int lower = 0;
	int upper = 0;
	int arrow = 0;

	lower = key == 'w' || key == 'a' || key == 's' || key == 'd';
	upper = key == 'W' || key == 'A' || key == 'S' || key == 'D';
	arrow = key == UP || key == LEFT || key == DOWN || key == RIGHT;

	output = lower || upper || arrow;

	return output;
}// 입력받은 키가 방향조작키인지 확인하기 위한 함수 키를 받아서 방향키인지 확인 후 논리 값 출력
 //output: 출력할 논리 값 lower: 소문자 논리값 upper: 대문자 논리 값 arrow: 방향키 논리 값

int isWin(int **board, int size) {
	int i = 0, j = 0;
	int win = 0;

	while (i < size && win == 0) {
		while (j < size && win == 0) {
			if (board[i][j] == 2048) {
				win = 1;
			}
			j++;
		}
		i++;
	}
	return win;
}//게임 승패 여부 판단

void isWinPrint(int **board, int score, int high_score, int size, int win_result) {
	printBoard(board, size);
	printf("\n\n>> GAME OVER! <<\n\n");

	if (!win_result) {
		printf(": You did not make 2048.\n");
		printf("  YOU LOSE!\n");
	}
	else {
		printf(": You made 2048.\n");
		printf("  YOU WIN!\n");
	}
	printf("\n>> last turn state <<\n");
	printf(": Score: %d\n: High Score: %d\n", score, high_score);
}//승패 여부에 따른 상태 출력
