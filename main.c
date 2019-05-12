#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "InitGame.h"

int main() {
	int **cur_board, size, **pre_board, *emptyIndex;
	int cur_score, high_score, pre_score, sum;
	int isGameover=0, isWin;
	int emptyTile=1, randomNum, randomIndex=0;
	int i, j, k, flag=0;

	printf("Enter the desired game board size: ");
	scanf("%d", &size);

	cur_board=(int **)malloc(sizeof(int *)*size);
	pre_board=(int **)malloc(sizeof(int *)*size);
	emptyIndex=(int *)malloc(sizeof(int)*(size*size));

	for (i=0; i<size; i++)
		cur_board[i]=(int *)malloc(sizeof(int)*size);
	for (i=0; i<size; i++)
		pre_board[i]=(int *)malloc(sizeof(int)*size);

	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			cur_board[i][j]=0;
		}
	}
	for (i=0; i<size; i++) {
		for (j=0; j<size; j++) {
			pre_board[i][j]=0;
		}
	}


	setUp();
	srand(time(NULL));

	pre_score=0;
	cur_score=0;
	high_score=0;

	i=rand()%size;
	j=rand()%size;
	randomNum=((rand()%2)+1)*2;
	cur_board[i][j]=randomNum;

	i=rand()%size;
	j=rand()%size;
	randomNum=((rand()%2)+1)*2;
	cur_board[i][j]=randomNum;

	sum=0;
	for (i=0; i < size; i++) {
		for (j=0; j < size; j++) {
			sum+=cur_board[i][j];
		}
	}

	high_score=sum;
	cur_score=sum;
	for (i=0; i < size; i++) {
		for (j=0; j<size; j++) {
			if (j==0)
				printf("|");
			printf(" %4d   |", cur_board[i][j]);
		}
		printf("\n");
	}
	printf("\nThe current state\n");
	printf("Score:%d\nHigh Score=%d", cur_score, high_score);
	printf("\nPress w to move up,press a to move left,press s to move down,press d to move right,\npress e to finish the game, press x to refresh,press r to restore \n");

	while (key!='e') {
		key=_getch();
		srand(time(NULL));

		if (key=='d') {
			pre_score=cur_score;
			for (i=0; i<size; i++) {
				for (j=0; j<size; j++) {
					pre_board[i][j]=cur_board[i][j];
				}
			}
			for (k=0; k<=size-2; k++) {

				for (i=0; i<=size-1; i++) {
					for (j=0; j < size-1; j++) {
						if (cur_board[i][j]!=0&&cur_board[i][j+1]==0) {
							cur_board[i][j+1]=cur_board[i][j];
							cur_board[i][j]=0;
						}
					}
				}
			}
			for (i=0; i<=size-1; i++) {
				j=0;
				flag=0;
				while (j<=size-2&&flag==0) {

					if (cur_board[i][j]==cur_board[i][j+1]&&cur_board[i][j]!=0) {
						cur_board[i][j+1]=cur_board[i][j+1]+cur_board[i][j];
						cur_board[i][j]=0;
						flag=1;
					}
					j=j+1;
				}
			}
			for (k=0; k<=size-2; k++) {

				for (i=0; i<=size-1; i++) {
					for (j=0; j < size-1; j++) {
						if (cur_board[i][j]!=0&&cur_board[i][j+1]==0) {
							cur_board[i][j+1]=cur_board[i][j];
							cur_board[i][j]=0;
						}
					}
				}
			}
			emptyTile=0;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size; j++) {
					if (cur_board[i][j]==0) {
						emptyIndex[emptyTile]=10*i+j;
						emptyTile=emptyTile+1;
					}
				}
			}
			randomIndex=rand()%emptyTile;
			i=emptyIndex[randomIndex]/10;
			j=emptyIndex[randomIndex]%10;
			randomNum=((rand()%2)+1)*2;
			cur_board[i][j]=randomNum;

			system("cls");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);

			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			sum=0;
			for (i=0; i < size; i++) {
				for (j=0; j < size; j++) {
					sum+=cur_board[i][j];
				}
			}
			cur_score=sum;
			if (cur_score>high_score) {
				high_score=cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d\n", cur_score, high_score);
		}
		if (key=='a') {
			pre_score=cur_score;

			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					pre_board[i][j]=cur_board[i][j];
				}
			}
			for (k=0; k<=size-2; k++) {
				for (i=0; i<=size-1; i++) {
					for (j=size-1; j > 0; j--) {
						if (cur_board[i][j]!=0&&cur_board[i][j-1]==0) {
							cur_board[i][j-1]=cur_board[i][j];
							cur_board[i][j]=0;
						}
					}
				}
			}
			for (i=0; i<=size-1; i++) {
				j=0;
				flag=0;

				while (j<=size-2&&flag==0) {
					if (cur_board[i][j]==cur_board[i][j+1]&&cur_board[i][j]!=0) {
						cur_board[i][j]=cur_board[i][j+1]+cur_board[i][j];
						cur_board[i][j+1]=0;
						flag=1;
					}
					j=j+1;
				}
			}
			for (k=0; k<=size-1; k++) {
				for (i=0; i<=size-1; i++) {
					for (j=size-1; j > 0; j--) {
						if (cur_board[i][j]!=0&&cur_board[i][j-1]==0) {
							cur_board[i][j-1]=cur_board[i][j];
							cur_board[i][j]=0;
						}
					}
				}
			}
			emptyTile=0;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					if (cur_board[i][j]==0) {
						emptyIndex[emptyTile]=10*i+j;
						emptyTile=emptyTile+1;
					}
				}
			}
			randomIndex=rand()%emptyTile;
			i=emptyIndex[randomIndex]/10;
			j=emptyIndex[randomIndex]%10;
			randomNum=((rand()%2)+1)*2;
			cur_board[i][j]=randomNum;

			system("CLS");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			sum=0;
			for (i=0; i < size; i++) {
				for (j=0; j < size; j++) {
					sum+=cur_board[i][j];
				}
			}
			cur_score=sum;
			if (cur_score>high_score) {
				high_score=cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key=='s') {
			pre_score=cur_score;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					pre_board[i][j]=cur_board[i][j];
				}
			}
			for (k=0; k<=size-1; k++) {
				for (j=0; j<=size-1; j++) {
					for (i=size-1; i > 0; i--) {
						if (cur_board[i][j]==0&&cur_board[i-1][j]!=0) {
							cur_board[i][j]=cur_board[i-1][j];
							cur_board[i-1][j]=0;
						}
					}
				}
			}
			for (j=0; j<=size-1; j++) {
				i=size-1;
				flag=0;
				while (i>0&&flag==0) {
					if (cur_board[i][j]==cur_board[i-1][j]&&cur_board[i][j]!=0) {
						cur_board[i][j]=cur_board[i-1][j]+cur_board[i][j];
						cur_board[i-1][j]=0;
						flag=1;
					}
					i=i-1;
				}
			}
			for (k=0; k<=size-1; k++) {
				for (j=0; j<=size-1; j++) {
					for (i=size-1; i > 0; i--) {
						if (cur_board[i][j]==0&&cur_board[i-1][j]!=0) {
							cur_board[i][j]=cur_board[i-1][j];
							cur_board[i-1][j]=0;
						}
					}
				}
			}
			emptyTile=0;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					if (cur_board[i][j]==0) {
						emptyIndex[emptyTile]=10*i+j;
						emptyTile=emptyTile+1;
					}
				}
			}
			randomIndex=rand()%emptyTile;
			i=emptyIndex[randomIndex]/10;
			j=emptyIndex[randomIndex]%10;
			randomNum=((rand()%2)+1)*2;
			cur_board[i][j]=randomNum;

			system("CLS");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}

			sum=0;
			for (i=0; i < size; i++) {
				for (j=0; j < size; j++) {
					sum+=cur_board[i][j];
				}
			}

			cur_score=sum;
			if (cur_score>high_score) {
				high_score=cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key=='w') {
			pre_score=cur_score;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					pre_board[i][j]=cur_board[i][j];
				}
			}
			for (k=0; k<=size-2; k++) {
				for (j=0; j<=size-1; j++) {
					for (i=0; i < size-1; i++) {
						if (cur_board[i][j]==0&&cur_board[i+1][j]!=0) {
							cur_board[i][j]=cur_board[i+1][j];
							cur_board[i+1][j]=0;
						}
					}
				}
			}
			for (j=0; j<=size-1; j++) {
				i=0;
				flag=0;
				while (i<size-1&&flag==0) {

					if (cur_board[i][j]==cur_board[i+1][j]&&cur_board[i][j]!=0) {
						cur_board[i][j]=cur_board[i+1][j]+cur_board[i][j];
						cur_board[i+1][j]=0;
						flag=1;
					}
					i=i+1;
				}
			}
			for (k=0; k<=size-2; k++) {
				for (j=0; j<=size-1; j++) {
					for (i=0; i < size-1; i++) {
						if (cur_board[i][j]==0&&cur_board[i+1][j]!=0) {
							cur_board[i][j]=cur_board[i+1][j];
							cur_board[i+1][j]=0;
						}
					}
				}
			}
			emptyTile=0;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					if (cur_board[i][j]==0) {
						emptyIndex[emptyTile]=10*i+j;
						emptyTile=emptyTile+1;
					}
				}
			}

			randomIndex=rand()%emptyTile;
			i=emptyIndex[randomIndex]/10;
			j=emptyIndex[randomIndex]%10;
			randomNum=((rand()%2)+1)*2;
			cur_board[i][j]=randomNum;

			system("CLS");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			sum=0;
			for (i=0; i < size; i++) {
				for (j=0; j < size; j++) {
					sum+=cur_board[i][j];
				}
			}
			cur_score=sum;
			if (cur_score>high_score) {
				high_score=cur_score;
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score=%d", cur_score, high_score);
		}
		if (key=='x') {
			cur_score=0;
			for (i=0; i<=size-1; i++) {
				for (j=0; j<=size-1; j++) {
					cur_board[i][j]=0;
				}
			}
			system("CLS");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", pre_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", cur_score, high_score);
		}
		if (key=='r') {
			system("CLS");
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", cur_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe previous state\n");
			printf("Score:%d\nHigh Score:%d\n", cur_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j<size; j++) {
					if (j==0)
						printf("|");
					printf(" %4d   |", pre_board[i][j]);
				}
				printf("\n");
			}
			printf("\nThe current state\n");
			printf("Score:%d\nHigh Score:%d", pre_score, high_score);
			for (i=0; i < size; i++) {
				for (j=0; j < size; j++) {
					cur_board[i][j]=pre_board[i][j];
				}
			}
		}
		isGameover=0;
		for (i=0; i<=size-1; i++) {
			for (j=0; j<=size-1; j++) {
				if (cur_board[i][j]==0) {
					isGameover=1;
				}
			}
		}
		for (i=0; i<=size-2; i++) {
			for (j=0; j<=size-2; j++) {
				if (i==size-1&&j!=size-1&&cur_board[i][j]==cur_board[i][j+1]) {
					isGameover=1;
				}
				if (j==size-1&&i!=size-1&&cur_board[i][j]==cur_board[i+1][j]) {
					isGameover=1;
				}
				if (cur_board[i][j]==cur_board[i+1][j]||cur_board[i][j]==cur_board[i][j+1]) {
					isGameover=1;
				}
			}
		}
		if (isGameover!=1) {
			key='e';
		}
		i=1;
		j=1;
		isWin=0;
		while (i<size&&isWin==0) {
			while (j<size&&isWin==0) {
				if (cur_board[i][j]==2048) {
					isWin=1;
				}
				j+=1;
			}
			i+=1;
		}
		printf("\nPress 8 to move up,press 4 to move left,press move 2 to down,press 6 to move right,\npress e to finish the game,press x to refresh,press r to restore \n");
		if (isWin==1) {
			printf("YOU WON!\n");
			key='e';
		}
	}
	system("CLS");
	for (i=0; i < size; i++) {
		for (j=0; j<size; j++) {
			if (j==0)
				printf("|");
			printf(" %4d   |", cur_board[i][j]);
		}
		printf("\n");
	}
	printf("\nThe current state\n");
	if (isWin!=1) {
		printf("\nYOU LOSE!");
	}
	printf("\n \n GAME OVER!\n Score: %d \n High Score:%d", cur_score, high_score);
	_getch();
	return 0;
}
