#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"utils.h"
#include"list.h"
#include"macro.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main() {
	//���� ���� ������ log.txt������ ���� �������� ����
	TABLES* table;
	table = (TABLES*) malloc(1*sizeof(TABLES));
	table->head = (TABLE*)malloc(1*sizeof(TABLE));
	table->head->people = (PERSON*)malloc(1 * sizeof(PERSON));
	table->head->next = NULL;
	FILE* myfile;
	char command[COMMAND_MAX_LEN];
	printf("�������, �濪ġŲ�Դϴ�.\n");
	myfile = fopen("log.txt", "w");
	logwrite(myfile);

	//quit�� �Է¹��� ������ ��ɾ �޾� �Լ��� ������.
	while (1) {
		printf("��ɾ �Է��ϼ���, >>");
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
			printf("\n������ �����մϴ�. ���� �ִ� �մԵ鵵 �����Ͽ� ���� ��ο� ����մϴ�.\n");
			printf("ġŲ �԰� �ǰ��ϼ���~");
			quit(table, myfile);
			break;
		}
		else
			printf("�� �� ���� ��ɾ��Դϴ�.\n\n");
		
	}

}