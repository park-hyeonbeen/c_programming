#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define max 30
void file_read(FILE* myfile, char comp[]);
void print_word(char word[], int found[], char user, int size);
void alpbt_input(char* user);
void random(int* choice, int option);
void print_used(char used[], char user, int try);
int same_check(char used[], char user);
int findword(char comp[], char user, int found[]);
void lifecount(int findsuccess, int* life);
int gameover(int life, char word[]);
void failcheck(int life, char word[], char comp[]);
void regame(char* re);
int checksize(char comp[]);
void variable_format(int* life, int* gameset, int* try, char* user, int found[], char used[]);


int main() {
	char comp[max];
	char user = -1;
	char word[max];
	int found[max] = {0};
	char used[max] = {0};
	int samecheck;
	char findsuccess;
	int life = 10;
	int gameset = 1;
	char re = 'n';
	int size;
	int try = 0;
	
	FILE* myfile;
	printf("Let's play the hangman game!\n");
	do {
		if(re=='y')
		variable_format(&life, &gameset, &try, &user, found, used);

		myfile = fopen("dic.txt", "r");
		file_read(myfile, comp);
		size = checksize(comp);
		print_word(word, found, user, size);
		print_used(used, user, try);
		printf("Hangman (%d life) - Input: ", life);
		while (gameset) {
			if (re == 'y'&& used[1] == 0)
				getchar();
			scanf("%c", &user);
			samecheck = same_check(used, user);
			if (samecheck)
				printf("%c: Already inserted character\n", user);
			else {
				findsuccess = findword(comp, user, found);
				lifecount(findsuccess, &life);
				try++;
			}
			print_word(word, found, user, size);
			print_used(used, user, try);
			gameset = gameover(life, word);
			printf("Hangman (%d life)", life) ;
			if(gameset)
				 printf(" - Input: ");
			getchar();
		}
		failcheck(life, word, comp);
		regame(&re);
		fclose(myfile);
	} while (re == 'y');
	printf("Goodbye!");
}

void file_read(FILE* myfile, char comp[]) {
	int choice;
	int option;
	fscanf(myfile, "%d", &option);
	random(&choice, option);
	for (int i = 0; i < choice; i++) {
		fscanf(myfile, "%s", comp);
	}
}
void random(int* choice, int option) {
	srand(time(NULL));
	*choice = rand() % option + 1;
}
void print_word(char word[], int found[], char user, int size) {
	if (user==-1) {
		for (int i = 0; i <= size - 1; i++) {
			word[i] = '_';
		}
		word[size] = NULL;
	}
	else {
		for (int i = 0; i <= size - 1; i++) {
			if (found[i] == 1 && word[i]=='_')
				word[i] = user;
		}
	}
	printf("\nword: ");
	for (int i = 0; i < size; i++) {
		printf("%c ", word[i]);
	}
	printf("\n");
}
void print_used(char used[], char user, int try) {
	if (used[try] == 0) {
		if (try == 0);
		else
		used[try] = user;
	}
	else;
	printf("used: ");
	for (int i = 0; i <= try; i++) {
		if (i == 0);
		else
		printf("%c ", used[i]);
	}
	printf("\n");
}
int same_check(char used[], char user) {
	for (int i = 0; i <= max; i++) {
		if (used[i] == user)
			return 1;
	}
	return 0;
}
int findword(char comp[], char user, int found[]) {
	int f = 0;
	for (int i = 0; i <= max; i++) {
		if (comp[i] == user) {
			found[i] = 1;
			f = 1;
		}
	}
	return f;
}
void lifecount(int findsuccess, int* life) {
	if (findsuccess);
	else
		*life = *life - 1;
}
int gameover(int life, char word[]) {
	int k = 1;
	for (int i = 0; word[i] != NULL; i++) {
		if (word[i] == '_')
			k = 0;
	}
	if (life == 0 || k)
		return 0;
	else
		return 1;
}
void failcheck(int life, char word[], char comp[]) {
	if (life == 0) {
		printf("\n\nMission failed!\n");
		printf("The answer was %s\n", comp);
	}
	else {
		printf("\n\nCongratulations!\n");
		printf("The answer was %s\n", word);
	}
}
void regame(char* re) {
	printf("\nDo you want to play again? (y/n)");
	scanf("%c", re);
}
int checksize(char comp[]) {
	int k = 0;
	for (int i = 0; comp[i] != NULL; i++) {
		k++;
	}
	return k;
}
void variable_format(int* life, int* gameset, int* try, char* user, int found[], char used[]) {
	*life = 10;
	*gameset = 1;
	*try = 0;
	*user = -1;
	for (int i = 0; i < max - 1; i++) {
		found[i] = 0;
		used[i] = 0;
	}
}