#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"utils.h"
#include"list.h"
#include"macro.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main() {
	//각종 변수 선언후 log.txt파일을 쓰기 형식으로 열기
	TABLES* table;
	table = (TABLES*) malloc(1*sizeof(TABLES));
	table->head = (TABLE*)malloc(1*sizeof(TABLE));
	table->head->people = (PERSON*)malloc(1 * sizeof(PERSON));
	table->head->next = NULL;
	FILE* myfile;
	char command[COMMAND_MAX_LEN];
	printf("어서오세요, 방역치킨입니다.\n");
	myfile = fopen("log.txt", "w");
	logwrite(myfile);

	//quit를 입력받을 때까지 명령어를 받아 함수를 실행함.
	while (1) {
		printf("명령어를 입력하세요, >>");
		scanf("%s", command);
		if (strcmp(command, "enter") == 0) {
			enter(table, myfile);
		}
		else if (strcmp(command, "show") == 0) {
			show(table);
		}
		else if (strcmp(command, "order") == 0) {
			order(table);
		}
		else if (strcmp(command, "leave") == 0) {
			leave(table, myfile);
		}
		else if (strcmp(command, "quit") == 0) {
			printf("\n영업을 종료합니다. 남아 있던 손님들도 퇴장하여 출입 명부에 기록합니다.\n");
			printf("치킨 먹고 건강하세요~");
			quit(table, myfile);
			break;
		}
		else
			printf("알 수 없는 명령어입니다.\n\n");
		
	}

}