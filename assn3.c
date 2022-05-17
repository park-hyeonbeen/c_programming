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

//메뉴를 출력받고 1,2,3 중 하나를 입력 받는다. 값에 해당하는 동작을 한다.
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
//menu에서 2를 입력받았을 시 호출되어 입력된 값에 따라 차가 움직이는 속도를 결정한다.
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

//파일을 읽어 맵에 대한 정보를 map_infor 배열에 저장한다.
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

//map_infor 배열을 기반으로 map배열을 만든다. 각 줄마다 make_tree와 make_car 함수를 활용한다.
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

//map의 나무가 있어야 할 줄에 필요한 개수만큼 랜덤으로 생성해준다.
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
					//될 때까지 스스로를 호출한다.
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
				//될 때까지 스스로를 호출한다.
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
//map의 차가 있어야 할 줄에 필요한 개수만큼 랜덤으로 생성해준다.
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
				//될 때까지 스스로를 호출한다.
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
			//될 때까지 스스로를 호출한다.
			make_car(arry, many);
		}
	}
}
//게임실행 함수이다.
void play(int** map, int** map_infor, int length, int level, int* game, int* score, int* posx, int* posy) {
	char k;
	while (*game) {
		//키보드 입력을 안 받았는 동안
		while (!_kbhit()) {
			system("cls");
			print_map(map, *score, length);
			Sleep(level);
			update_map(map, game, *posx, *posy);
			//차에 부딪혀서 게임오버
			if (*game == 0)
			{
				print_over();
				scanf("%c", &k);
				system("cls");
				return;
			}
		}
		//키보드 입력을 받은 경우
		move(_getch(), map, game, score, posx, posy);
		if (*posy==1) {
			*score = *score + 1;
			new_row(map, map_infor, *score);
		}
		//차에 부딪혀서 게임오버
		if (*game == 0) {
			system("cls");
			print_map(map, *score, length);
			print_over();
			scanf("%c", &k);
			system("cls");
			return;
		}
		*posy = 0;
		//성공으로 게임종료
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
//map배열을 받아 map을 출력한다.
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

//차를 오른쪽으로 한칸 이동시키고, 차와 캐릭터가 부딪혔는지도 체크한다.
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
//캐릭터가 나무에 막혔는지, 혹은 차에 부딪혔는지 체크해주는 함수
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
//w,a,d를 입력받았을 때 캐릭터의 위치정보를 변경, 캐릭터를 이동시킨다.
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
	//나무에 막혔을 땐 이동 안 한다.
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
//w키를 입력 받았을 때 동적할당을 통해 맨 아래 줄을 삭제하고 한 줄을 내려 새로 만든다.
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
//게임이 끝났을 때 나오는 문구를 출력하는 함수들
void print_over() {
	printf("Game Over!!!\n");
	printf("Press Enter key");
}
void print_success() {
	printf("Congratulations!!! You Win!!!\n");
	printf("Press Enter key");
}