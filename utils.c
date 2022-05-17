#include<time.h>
#include"macro.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

//현재시간을 current_time 문자열에 저장하는 함수
void get_current_time(char* time_string) {
	time_t current_time;
	char* new_line_pos;

	current_time = time(NULL);
	ctime_s(time_string, TIME_MAX_LEN, &current_time);
	if ((new_line_pos = strchr(time_string, '\n')) != NULL)
		*new_line_pos = '\0';
}

//log.txt의 맨 윗줄을 출력하는 함수
void logwrite(FILE* myfile) {
	fprintf(myfile, "[시간]\t\t\t\t출입\t이름\t전화번호\n");
}