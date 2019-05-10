#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "InitGame.h"

int main() {
	int cur_board[5][5], pre_board[5][5], emptyIndex[16];
	int cur_score, high_score, pre_score, sum;
	int isGameover = 0, isWin;
	int emptyTile = 1, randomNum, randomIndex = 0;
	int i, j, k, flag = 0;

	setUp();
	srand(time(NULL));
	for (i = 1; i <= 4; i++) {
		for (j = 1; j <= 4; j++) {
			cur_board[i][j] = 0;
		}
	}
	pre_score = 0;
	cur_score = 0;
	high_score = 0;

	i = rand() % 3 + 1;
	j = rand() % 3 + 1;
	randomNum = rand() % 2 + 2;
	if (randomNum == 3)
		randomNum = 2;
	cur_board[i][j] = randomNum;

	i = rand() % 3 + 1;
	j = rand() % 3 + 1;
	randomNum = rand() % 2 + 2;
	if (randomNum == 3)
		randomNum = 2;
	cur_board[i][j] = randomNum;

	sum = 0;
	for (i = 1; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			sum += cur_board[i][j];
		}
	}

	high_score = sum;
	cur_score = sum;
	for (i = 1; i < 5; i++) {
		printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
	}
	printf("\nThe current state\n");
	printf("Score:%d\nHigh Score=%d", cur_score, high_score);
	printf("\nPress w to move up,press a to move left,press s to move down,press d to move right,\npress e to finish the game, press x to refresh,press r to restore \n");

	while (key != 'e') {
		key = _getch();
		srand(time(NULL));

		if (key == 'd') {
			pre_score = cur_score;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}
			for (k = 1; k <= 3; k++) {

				for (i = 1; i <= 4; i++) {
					for (j = 1; j < 4; j++) {
						if (cur_board[i][j] != 0 && cur_board[i][j + 1] == 0) {
							cur_board[i][j + 1] = cur_board[i][j];
							cur_board[i][j] = 0;
						}
					}
				}
			}
			for (i = 1; i <= 4; i++) {
				j = 1;
				flag = 0;
				while (j <= 3 && flag == 0) {

					if (cur_board[i][j] == cur_board[i][j + 1] && cur_board[i][j] != 0) {
						cur_board[i][j + 1] = cur_board[i][j + 1] + cur_board[i][j];
						cur_board[i][j] = 0;
						flag = 1;
					}
					j = j + 1;
				}
			}
			for (k = 1; k <= 3; k++) {

				for (i = 1; i <= 4; i++) {
					for (j = 1; j < 4; j++) {
						if (cur_board[i][j] != 0 && cur_board[i][j + 1] == 0) {
							cur_board[i][j + 1] = cur_board[i][j];
							cur_board[i][j] = 0;
						}
					}
				}
			}
			emptyTile = 0;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = rand() % 2 + 2;
			if (randomNum == 3)
				randomNum = 2;
			cur_board[i][j] = randomNum;

			system("cls");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]); //¿¿ ¿¿ O print
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);

			for (i = 1; i<5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}
			sum = 0;
			for (i = 1; i < 5; i++) {
				for (j = 1; j < 5; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score>high_score) {
				high_score = cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key == 'a') {
			pre_score = cur_score;

			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}
			for (k = 1; k <= 3; k++) {
				for (i = 1; i <= 4; i++) {
					for (j = 4; j > 1; j--) {
						if (cur_board[i][j] != 0 && cur_board[i][j - 1] == 0) {
							cur_board[i][j - 1] = cur_board[i][j];
							cur_board[i][j] = 0;
						}
					}
				}
			}
			for (i = 1; i <= 4; i++) {
				j = 1;
				flag = 0;

				while (j <= 3 && flag == 0) {
					if (cur_board[i][j] == cur_board[i][j + 1] && cur_board[i][j] != 0) {
						cur_board[i][j] = cur_board[i][j + 1] + cur_board[i][j];
						cur_board[i][j + 1] = 0;
						flag = 1;
					}
					j = j + 1;
				}
			}
			for (k = 1; k <= 4; k++) {
				for (i = 1; i <= 4; i++) {
					for (j = 4; j > 1; j--) {
						if (cur_board[i][j] != 0 && cur_board[i][j - 1] == 0) {
							cur_board[i][j - 1] = cur_board[i][j];
							cur_board[i][j] = 0;
						}
					}
				}
			}
			emptyTile = 0;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = rand() % 2 + 2;
			if (randomNum == 3)
				randomNum = 2;
			cur_board[i][j] = randomNum;

			system("CLS");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]);
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i = 1; i<5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}
			sum = 0;
			for (i = 1; i < 5; i++) {
				for (j = 1; j < 5; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score>high_score) {
				high_score = cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key == 's') {
			pre_score = cur_score;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}
			for (k = 1; k <= 4; k++) {
				for (j = 1; j <= 4; j++) {
					for (i = 4; i > 1; i--) {
						if (cur_board[i][j] == 0 && cur_board[i - 1][j] != 0) {
							cur_board[i][j] = cur_board[i - 1][j];
							cur_board[i - 1][j] = 0;
						}
					}
				}
			}
			for (j = 1; j <= 4; j++) {
				i = 4;
				flag = 0;
				while (i>1 && flag == 0) {
					if (cur_board[i][j] == cur_board[i - 1][j] && cur_board[i][j] != 0) {
						cur_board[i][j] = cur_board[i - 1][j] + cur_board[i][j];
						cur_board[i - 1][j] = 0;
						flag = 1;
					}
					i = i - 1;
				}
			}
			for (k = 1; k <= 4; k++) {
				for (j = 1; j <= 4; j++) {
					for (i = 4; i > 1; i--) {
						if (cur_board[i][j] == 0 && cur_board[i - 1][j] != 0) {
							cur_board[i][j] = cur_board[i - 1][j];
							cur_board[i - 1][j] = 0;
						}
					}
				}
			}
			emptyTile = 0;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}
			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = rand() % 2 + 2;
			if (randomNum == 3)
				randomNum = 2;
			cur_board[i][j] = randomNum;

			system("CLS");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]);
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}

			sum = 0;
			for (i = 1; i < 5; i++) {
				for (j = 1; j < 5; j++) {
					sum += cur_board[i][j];
				}
			}

			cur_score = sum;
			if (cur_score>high_score) {
				high_score = cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key == 'w') {
			pre_score = cur_score;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					pre_board[i][j] = cur_board[i][j];
				}
			}
			for (k = 1; k <= 3; k++) {
				for (j = 1; j <= 4; j++) {
					for (i = 1; i < 4; i++) {
						if (cur_board[i][j] == 0 && cur_board[i + 1][j] != 0) {
							cur_board[i][j] = cur_board[i + 1][j];
							cur_board[i + 1][j] = 0;
						}
					}
				}
			}
			for (j = 1; j <= 4; j++) {
				i = 1;
				flag = 0;
				while (i<4 && flag == 0) {

					if (cur_board[i][j] == cur_board[i + 1][j] && cur_board[i][j] != 0) {
						cur_board[i][j] = cur_board[i + 1][j] + cur_board[i][j];
						cur_board[i + 1][j] = 0;
						flag = 1;
					}
					i = i + 1;
				}
			}
			for (k = 1; k <= 3; k++) {
				for (j = 1; j <= 4; j++) {
					for (i = 1; i < 4; i++) {
						if (cur_board[i][j] == 0 && cur_board[i + 1][j] != 0) {
							cur_board[i][j] = cur_board[i + 1][j];
							cur_board[i + 1][j] = 0;
						}
					}
				}
			}
			emptyTile = 0;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					if (cur_board[i][j] == 0) {
						emptyIndex[emptyTile] = 10 * i + j;
						emptyTile = emptyTile + 1;
					}
				}
			}

			randomIndex = rand() % emptyTile;
			i = emptyIndex[randomIndex] / 10;
			j = emptyIndex[randomIndex] % 10;
			randomNum = rand() % 2 + 2;
			if (randomNum == 3)
				randomNum = 2;
			cur_board[i][j] = randomNum;

			system("CLS");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]);
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}
			sum = 0;
			for (i = 1; i < 5; i++) {
				for (j = 1; j < 5; j++) {
					sum += cur_board[i][j];
				}
			}
			cur_score = sum;
			if (cur_score>high_score) {
				high_score = cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score=%d", cur_score, high_score);
		}
		if (key == 'x') {
			cur_score = 0;
			for (i = 1; i <= 4; i++) {
				for (j = 1; j <= 4; j++) {
					cur_board[i][j] = 0;
				}
			}
			system("CLS");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]);
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key == 'r') {
			system("CLS");
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
			for (i = 1; i < 5; i++) {
				printf("\n| %4d    | %4d    | %4d    | %4d    |\n", pre_board[i][1], pre_board[i][2], pre_board[i][3], pre_board[i][4]);
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i = 1; i < 5; i++) {
				for (j = 1; j < 5; j++) {
					cur_board[i][j] = pre_board[i][j];
				}
			}
		}
		isGameover = 0;
		for (i = 1; i <= 4; i++) {
			for (j = 1; j <= 4; j++) {
				if (cur_board[i][j] == 0) {
					isGameover = 1;
				}
			}
		}
		for (i = 1; i <= 4; i++) {
			for (j = 1; j <= 4; j++) {
				if (i == 4 && j != 4 && cur_board[i][j] == cur_board[i][j + 1]) {
					isGameover = 1;
				}
				if (j == 4 && i != 4 && cur_board[i][j] == cur_board[i + 1][j]) {
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
		while (i<5 && isWin == 0) {
			while (j<5 && isWin == 0) {
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
	for (i = 1; i<5; i++) {
		printf("\n| %4d    | %4d    | %4d    | %4d    |\n", cur_board[i][1], cur_board[i][2], cur_board[i][3], cur_board[i][4]);
	}
	printf("\nThe current state\n");
	if (isWin != 1) {
		printf("\nYOU LOSE!");
	}
	printf("\n \n GAME OVER!\n Score: %d \n High Score:%d", cur_score, high_score);
	_getch();
	return 0;
}
