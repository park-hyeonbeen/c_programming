#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int** file_read(FILE* myfile, int** map_infor, int* length);
int** make_map(int** map_infor, int** map, int length);
void menu(int* level, int* game);
void set_level(int* level);
void make_tree(int* arry, int many);
void make_car(int* arry, int many);
void play(int** map, int** map_infor, int length, int level, int* game, int* score, int* posx, int* posy);
void print_map(int** map, int score, int length);
void update_map(int** map, int* game, int posx, int posy);
int crash_check(int** map, int* game, int posx, int posy);
void move(int key, int** map, int* game, int* score, int* posx, int* posy);
void new_row(int** map, int** map_infor, int score);
void print_over();
void print_success();


int main(){
FILE* myfile = NULL;
int** map_infor=NULL;
int** map = NULL;
int level = 100;
int game = 1;
int length;
int score = 0;
int posx = 15;
int posy = 0;
while (1) {
	myfile = NULL;
	map_infor = NULL;
	map = NULL;
	game = 1;
	score = 0;
	posx = 15;
	posy = 0;
	menu(&level, &game);
	if (game == 0)
		return;
	map_infor = file_read(myfile, map_infor, &length);
	map = make_map(map_infor, map, length);
	play(map, map_infor, length, level, &game, &score, &posx, &posy);
	for (int i = 0; i <= 4; i++) {
		free(*(map + i));
	}
	free(map);
	for (int i = 0; i <= length; i++) {
		free(*(map_infor + i));
	}
	free(map_infor);
}


}

//�޴��� ��¹ް� 1,2,3 �� �ϳ��� �Է� �޴´�. ���� �ش��ϴ� ������ �Ѵ�.
void menu(int* level, int* game) {
	int pick;
	printf("=================\n" );
	printf("1. Quit the game\n");
	printf("2. Set the level\n");
	printf("3. Start the game\n");
	printf("=================");
	pick = _getch();
	switch (pick) {
	case 49: 
		*game = 0;
		break;
	case 50: 
		system("cls");
		set_level(level);
		menu(level, game);
	case 51:
		;
	}
}
//menu���� 2�� �Է¹޾��� �� ȣ��Ǿ� �Էµ� ���� ���� ���� �����̴� �ӵ��� �����Ѵ�.
void set_level(int* level){
	printf("=================\n");
	printf("1. easy\n");
	printf("2. normal\n");
	printf("3. hard\n");
	printf("=================");
	switch (_getch()) {
	case 49:
		*level = 200;
		break;
	case 50:
		*level = 100;
		break;
	case 51:
		*level = 50;
	}
	system("cls");
}

//������ �о� �ʿ� ���� ������ map_infor �迭�� �����Ѵ�.
int** file_read(FILE* myfile, int** map_infor, int* length) {
	if(myfile = fopen("map.txt", "r")==NULL)
		printf("FILE open Error!");
	myfile = fopen("map.txt", "r");
	fscanf(myfile,"%d", length);
	map_infor = malloc((*length + 1)*sizeof(int*));
	*(map_infor + *length) = NULL;
	for (int i = 0; *(map_infor + i); i++) {
			*(map_infor + i) = calloc(2, sizeof(int));
			fscanf(myfile, "%d %d", *(map_infor + i), *(map_infor + i) + 1);
	}
	fclose(myfile);
	return map_infor;
}

//map_infor �迭�� ������� map�迭�� �����. �� �ٸ��� make_tree�� make_car �Լ��� Ȱ���Ѵ�.
int** make_map(int** map_infor, int** map, int length) {
	int w;
	w = 5;
	if (length < 5)
	w = length;
	srand(time(NULL));
	map = malloc(5*sizeof(int*));
	for (int i = 0; i<5; i++) {
		*(map + i) = calloc(31, sizeof(int));
	}
	for (int i = 0; i< w; i++) {
		if (*(map_infor + i) != NULL) {
			switch (**(map_infor + i)) {
			case 0:
				*(*map + 15) = '@';
				*(*map + 16) = '@';
				break;
			case 1:
				make_tree(*(map + i), *(*(map_infor + i) + 1));
				break;
			case 2:
				make_car(*(map + i), *(*(map_infor + i) + 1));
				break;
			}
		}
		else
			;
	}
	return map;
}

//map�� ������ �־�� �� �ٿ� �ʿ��� ������ŭ �������� �������ش�.
void make_tree(int* arry, int many) {
	int y;
	int f;
	*arry = 1;
	int k = rand() % 5+1;
	for (int j, i = 0; i < many; i++) {
			y = rand() % 4 + 2;
			j = rand() % 3 + 4;
			*(arry + k) = '#';
			for (int q = 1; q < y; q++) {
				if (k + q > 30) {
					for(int u = 1; u<=30;u++)
					{
						*(arry + u) = NULL;
					}
					//�� ������ �����θ� ȣ���Ѵ�.
					make_tree(arry, many);
				}
				*(arry + k + q) = '#';
			}
			if (i == many - 1) {
				k = k + y;
			}
			else
				k = k + y + j;
			if (k > 30) {
				for (int u = 1; u <= 30; u++)
				{
					*(arry + u) = NULL;
				}
				//�� ������ �����θ� ȣ���Ѵ�.
				make_tree(arry, many);
			}
	}
	f = rand() % 2;
	if (f) {
		for (int p = 1; p <= 15; p++) {
			int temp;
			temp = *(arry + p);
			*(arry + p) = *(arry + 31 - p);
			*(arry + 31 - p) = temp;
		}
	}
}
//map�� ���� �־�� �� �ٿ� �ʿ��� ������ŭ �������� �������ش�.
void make_car(int* arry, int many) {
	int y;
	*arry = 2;
	int k = rand() % 4+1;
	for (int j, i = 0; i < many; i++) {
		y = rand() % 4 + 4;
		j = rand() % 3 + 4;
		*(arry + k) = '[';
		for (int q = 1; q < y; q++) {
			if (k + q > 30) {
				for (int u = 1; u <= 30; u++)
				{
					*(arry + u) = NULL;
				}
				//�� ������ �����θ� ȣ���Ѵ�.
				make_car(arry, many);
			}
			else if(q==y-1)
			*(arry + k + q) = ']';
			else
			*(arry + k + q) = '=';
		}
		if (i == many - 1) {
			k = k + y;
		}
		else
			k = k + y + j;
		if (k > 30) {
			for (int u = 1; u <= 30; u++)
			{
				*(arry + u) = NULL;
			}
			//�� ������ �����θ� ȣ���Ѵ�.
			make_car(arry, many);
		}
	}
}
//���ӽ��� �Լ��̴�.
void play(int** map, int** map_infor, int length, int level, int* game, int* score, int* posx, int* posy) {
	char k;
	while (*game) {
		//Ű���� �Է��� �� �޾Ҵ� ����
		while (!_kbhit()) {
			system("cls");
			print_map(map, *score, length);
			Sleep(level);
			update_map(map, game, *posx, *posy);
			//���� �ε����� ���ӿ���
			if (*game == 0)
			{
				print_over();
				scanf("%c", &k);
				system("cls");
				return;
			}
		}
		//Ű���� �Է��� ���� ���
		move(_getch(), map, game, score, posx, posy);
		if (*posy==1) {
			*score = *score + 1;
			new_row(map, map_infor, *score);
		}
		//���� �ε����� ���ӿ���
		if (*game == 0) {
			system("cls");
			print_map(map, *score, length);
			print_over();
			scanf("%c", &k);
			system("cls");
			return;
		}
		*posy = 0;
		//�������� ��������
		if (*score == length) {
			system("cls");
			print_map(map, *score, length);
			print_success();
			scanf("%c", &k);
			system("cls");
			return;
		}
	}
}
//map�迭�� �޾� map�� ����Ѵ�.
void print_map(int** map, int score, int length) {
	printf("score: %d/%d\n", score, length);
	for (int i = 4; i >= 0; i--) {
		for (int j = 1; j < 31; j++) {
			if (!*(*(map + i) + j))
				printf(" ");
			else
				printf("%c",*(*(map +i)+j));
		}
		printf("\n");
		printf("------------------------------");
		printf("\n");
	}
}

//���� ���������� ��ĭ �̵���Ű��, ���� ĳ���Ͱ� �ε��������� üũ�Ѵ�.
void update_map(int** map, int* game, int posx, int posy) {
	char temp;
	for (int i = 4; i >= 0; i--) {
		if (**(map + i) == 2) {
			temp = *(*(map + i) + 30);
			for (int j = 29; j >=1; j--) {
					*(*(map+i)+j+1) = *(*(map+i)+j);
			}
			*(*(map + i) + 1) = temp;
		}
	}
	crash_check(map, game, posx, posy);
	if (**(map+posy) == 2&&posx!=29) {
		*(*(map + posy) + posx) = '@';
		*(*(map + posy) + posx + 1) = '@';
		*(*(map + posy) + posx + 2) = NULL;
	}
	else if(**(map + posy) == 2 && posx == 29){
		*(*(map + posy) + posx) = '@';
		*(*(map + posy) + posx + 1) = '@';
		*(*(map + posy)+1) = NULL;
	}
		
}
//ĳ���Ͱ� ������ ��������, Ȥ�� ���� �ε������� üũ���ִ� �Լ�
int crash_check(int** map, int* game, int posx, int posy) {
	if (**(map + posy) == 1) {
		if (*(*(map + posy) + posx) == '#' || (*(*(map + posy) + posx + 1) == '#'))
			return 0;
		else
			return 1;
		}
	else if (**(map + posy) == 2) {
		if ((*(*(map + posy) + posx) == ']') || (*(*(map + posy) + posx + 1) == ']')) {
				*game = 0;
				return 0;
		}
		else if ((*(*(map + posy) + posx) == '[') || (*(*(map + posy) + posx + 1) == '[')) {
			*game = 0;
			return 0;
		}
		else if ((*(*(map + posy) + posx) == '=') || (*(*(map + posy) + posx + 1) == '=')) {
			*game = 0;
			return 0;
		}
	}
	return 1;
	}
//w,a,d�� �Է¹޾��� �� ĳ������ ��ġ������ ����, ĳ���͸� �̵���Ų��.
void move(int key, int** map, int* game, int* score, int* posx, int* posy) {
	int k=1;
	int tempx = *posx;
	int tempy = *posy;
	if (key == 'w') {
		*posy = *posy + 1;
	}
	else if (key == 'a') {
		if (*posx != 1)
			*posx = *posx - 1;
		else
			;
	}
	else if (key == 'd') {
		if (*posx != 29)
			*posx = *posx + 1;
		else
			;

	}
	else
		;
	k = crash_check(map, game, *posx, *posy);
	//������ ������ �� �̵� �� �Ѵ�.
	if (k == 0) {
		*posx = tempx;
		*posy = tempy;
	}
	else {
		*(*(map + tempy) + tempx) = NULL;
		*(*(map + tempy) + tempx+1) = NULL;
		*(*(map + *posy) + *posx) = '@';
		*(*(map + *posy) + *posx+1) = '@';
	}
	return key;
}
//wŰ�� �Է� �޾��� �� �����Ҵ��� ���� �� �Ʒ� ���� �����ϰ� �� ���� ���� ���� �����.
void new_row(int** map, int** map_infor, int score) {
	int k =1;
	int* temp;
	temp = *map;
	free(temp);
	for (int i = 1; i <= 4; i++) {
		*(map + i - 1) = *(map + i);
	}
	*(map + 4) = calloc(31,sizeof(int));
	for (int i = 0; i <= 4 + score; i++) {
		if (*(map_infor + i) == NULL) {
			k = 0;
			break;
		}
	}
	if (k == 1) {
		if (**(map_infor + 4 + score) == 1)
			make_tree(*(map + 4), *(*(map_infor + 4 + score) + 1));
		else
			make_car(*(map + 4), *(*(map_infor + 4 + score) + 1));
	}
}
//������ ������ �� ������ ������ ����ϴ� �Լ���
void print_over() {
	printf("Game Over!!!\n");
	printf("Press Enter key");
}
void print_success() {
	printf("Congratulations!!! You Win!!!\n");
	printf("Press Enter key");
}