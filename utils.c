#include<time.h>
#include"macro.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//����ð��� current_time ���ڿ��� �����ϴ� �Լ�
void get_current_time(char* time_string) {
	time_t current_time;
	char* new_line_pos;

	current_time = time(NULL);
	ctime_s(time_string, TIME_MAX_LEN, &current_time);
	if ((new_line_pos = strchr(time_string, '\n')) != NULL)
		*new_line_pos = '\0';
}

//log.txt�� �� ������ ����ϴ� �Լ�
void logwrite(FILE* myfile) {
	fprintf(myfile, "[�ð�]\t\t\t\t����\t�̸�\t��ȭ��ȣ\n");
}