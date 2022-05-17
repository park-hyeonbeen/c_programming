#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_board(char board_[][3]);
int check_board(char board_[][3]);
int player_turn(char board_[][3]);
int computer_turn(char board_[][3]);
void board_format(char board_[][3]);
void check_re(char* re);
void restart(char re, char board_[][3]);
void straight(int* bingo, char board_[][3]);


int main() {
	int turn;
	char board_[3][3] = {0};
	board_format(board_);
	print_board(board_);
	srand(time(NULL));
	turn = rand() % 2;
	if (turn)
		player_turn(board_);
	else
		computer_turn(board_);
	return 0;
}
int player_turn(char board_[][3]) {
	int user_x;
	int user_y;
	int bingo;
	char re;
	do {
		printf("\n[user] ");
		scanf("%d %d", &user_x, &user_y);
	} while (board_[user_x][user_y] == 'O'|| board_[user_x][user_y] == 'X');
	printf("\n");
	board_[user_x][user_y] = 'O';
	print_board(board_);
	bingo = check_board(board_);
	if (bingo == 3) {
		printf("\nYou Win!\n");
		check_re(&re);
		restart(re, board_);
		return 0;
	}
	else if (bingo == -1) {
		printf("\nDraw!\n");
		check_re(&re);
		restart(re, board_);
		return 0;
	}
	computer_turn(board_);
}
int computer_turn(char board_[][3]){
	srand(time(NULL));
	int x;
	int y;
	int bingo;
	char re;
	do {
		x = rand() % 3;
		y = rand() % 3;
	} while (board_[x][y] == 'O' || board_[x][y] == 'X');
	printf("\n[computer] %d %d\n\n", x, y);
	board_[x][y] = 'X';
	print_board(board_);
	bingo = check_board(board_);
	if (bingo == 3) {
		printf("\nComputer Wins!\n");
		check_re(&re);
		restart(re, board_);
		return 0;
	}
	else if (bingo == -1) {
		printf("\nDraw!\n");
		check_re(&re);
		restart(re, board_);
		return 0;
	}
	player_turn(board_);
}

void print_board(char board_[][3]) {	
		for (int i = 0; i <= 2; i++) {
			printf("+---+---+---+\n");
			for (int j = 0; j <= 2; j++) {
				printf("| %c ",board_[i][j]);
			}
			printf("|\n");
		}
		printf("+---+---+---+\n");
}

int check_board(char board_[][3]) {
	int bingo = 1;
	straight(&bingo, board_);
	if (bingo == 3)
		return bingo;
	else {
		for (int i = 0; i < 2; i++) {
			if (board_[i][i] == board_[i + 1][i + 1]&&board_[i][i]!='*')
				bingo++;
		}
	}
	if (bingo == 3)
		return bingo;
	else {
		bingo = 1;
		for (int i = 0; i < 2; i++) {
			if (board_[i][2 - i] == board_[i + 1][1 - i]&&board_[i][2-i]!='*')
				bingo++;
		}
	}
	if (bingo == 3)
		return bingo;
	for (int i = 0; i <= 2; i++) {
	for (int j = 0; j <= 2; j++) {
		if (board_[i][j] == '*')
			return 0;
	}
	}
	return -1;
}
void board_format(char board_[][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			board_[i][j] = '*';
		}
	}

}
void check_re(char* re) {
	printf("Do you want to play again? (y/n)");
	getchar();
	scanf("%c", re);
}
void restart(char re, char board_[][3]) {
	if (re == 'y') {
		board_format(board_);
		int turn_ = rand() % 2;
		if (turn_ == 1) {
			printf("\n");
			print_board(board_);
			player_turn(board_);
		}
		else
			computer_turn(board_);
	}
	else {
		printf("Goodbye!");
	}
}
void straight(int* bingo, char board_[][3]) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (board_[i][j] == board_[i][j + 1]&&board_[i][j]!='*')
				*bingo=*bingo +1;
			if (*bingo == 3)
				return;
		}
		*bingo = 1;
	}
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (board_[j][i] == board_[j+1][i] && board_[j][i] != '*')
				*bingo = *bingo + 1;
			if (*bingo == 3)
				return;
		}
		*bingo = 1;
	}
}