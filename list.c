#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "macro.h"
#include "utils.h"
#include "list.h"

//마스크를 출력함.
void print_mask() {
	printf("                        `-,:~<*r)|vvvvv|)r*<=:,-`                        \n");
	printf("                    .,=*?vvvvvvvvvvvvvvvvvvvvvvvv*=,.                    \n");
	printf("                `_~rvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvr~_`                \n");
	printf("             `_~?vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv?~_`             \n");
	printf("           '!\vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv|>`           \n");
	printf("         `=)vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv?=`         \n");
	printf("       `:)vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv):`       \n");
	printf("      .*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*-      \n");
	printf("    `!vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv!`    \n");
	printf("   `~vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv~`   \n");
	printf("  `~vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvxvvvvvvvvvvvvvvvvvvvvvvvv>`  \n");
	printf("  !vvvvvvvvvvvvvvvY@@@@@B##vvvvvvvvvvvvvvvvvvvvv@@@@@@vvvvvvvvvvvvvvvv!  \n");
	printf(" :vvvvvvvvvvv}K@@@@@@@@@@@@#vvvvvvvvvvvvvvVQ@@@@@@@@@@@@B9m}vvvvvvvvvvv: \n");
	printf("`rvvvvvvvvvvK@@@@@BBgdPB@@@@@vvvvvvvvvvvvvv@@@@VXPdgB@@@@@@Evvvvvvvvvvvr`\n");
	printf(":vvvvvvvvvvv@@@@dIYvvvvvv@@@@@vvvvvvvvvvvv#@@@vvvvvvvv}U@@@Rvvvvvvvvvvvv:\n");
	printf("<vvvvvvvvvvvv]ivvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvi]vvvvvvvvvvvv<\n");
	printf("._!^)vvvvvvvvvvvvvvvv?)))))))))))))))))))))))))))))|vvvvvvvvvvvvvvvv)^!_.\n");
	printf("`````-:~rvvvvvvvvv|=-```````````````````````````````-~|vvvvvvvvvr~:-`````\n");
	printf("*~:-`````.,=*vvvvv:```````````````````````````````````:vvvvvr=,.`````-:~*\n");
	printf(")vvvr<:_'````.,=*)_```````````````````````````````````,)^!,.`````_:<rvvv)\n");
	printf("^vvvvvvvv)^!_```````````````````````````````````````````````-!^)vvvvvvvv^\n");
	printf(":vvvvvvvvvvvv)^!,'`````````````````````````````````````.,!^)vvvvvvvvvvvv:\n");
	printf("`rvvvvvvvvvvvvvvv\\_```````````````````````````````````_|vvvvvvvvvvvvvvvr`\n");
	printf(" \"vvvvvvvvvvvvvvvv_```````````````````````````````````_vvvvvvvvvvvvvvvv\" \n");
	printf("  !vvvvvvvvvvvvvvv_```````````````````````````````````_vvvvvvvvvvvvvvv!  \n");
	printf("  `_\":=~^*r|vvvvvv_```````````````````````````````````_vvvvvv|r*^~!:\"_`  \n");
	printf("    ````````.-,:!=.```````````````````````````````````.=!:,-.````````    \n");
	printf("     `,_-'`````````````````````````````````````````````````````'-_,`     \n");
	printf("      .*vvv\\)*^~=:' ``````````````````````````````````.:=~^*)\vvv*.      \n");
	printf("       `:)vvvvvvvv_```````````````````````````````````_vvvvvvvv):`       \n");
	printf("         `=?vvvvvv:```````````````````````````````````:vvvvvv?=`         \n");
	printf("           `!|vvvv?!-```````````````````````````````-!?vvvv|>`           \n");
	printf("             `_~)vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv?~_`             \n");
	printf("                `_~rvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvr~_`                \n");
	printf("                    .,=*?vvvvvvvvvvvvvvvvvvvvvvv\\*=,.                    \n");
	printf("                        `-,:=<*r)?vvvvv?)r*<=:,-`                        \n");
	printf("***********************마스크 착용 후 입장 부탁드립니다.**********************\n");
}

//손님의 이름, 전화번호, 테이블 번호를 입력받아 PERSON 노드를 만들어 TABLE노드에 배정하는 함수
void enter(TABLES* table, FILE* myfile) {
	char mask;
	printf("마스크 착용하셨나요? (y/n) >> ");
	getchar();
	scanf("%c", &mask);
	switch (mask) {
		//y를 입력받았을 때
	case 121:
		get_person(table, myfile);
		show(table);
		break;
		//n을 입력받았을 때
	case 110:
		print_mask();
		break;
		//그 외의 값 입력받았을 때
	default:
		printf("입력한 값이 유효하지 않습니다.\n");
		enter(table, myfile);
	}
}

//손님의 이름, 전화번호를 문자열형태로 입력받고, 테이블 번호도 입력받아 log.txt에 출력하는 함수
void get_person(TABLES* table, FILE* myfile) {
	int length;
	char temp1[NAME_MAX_LEN];
	char temp2[PHONE_MAX_LEN];
	char* name;
	char* phone;
	int table_id;
	char* time_string = malloc(TIME_MAX_LEN*sizeof(char));
	printf("이름을 입력해주세요. (20자이내)>> ");
	scanf("%s", temp1);
	printf("전화번호를 입력해주세요. (-없이 11자)>> ");
	scanf("%s", temp2);
	printf("몇 번 테이블에 앉으시겠습니까?>> ");
	scanf("%d", &table_id);
	for (length = 0; temp1[length]; length++) {
	}
	name = (char*)malloc((length+1) * sizeof(char));
	strcpy(name, temp1);
	for (length = 0; temp2[length]; length++) {
	}
	phone = (char*)malloc((length+1) * sizeof(char));
	strcpy(phone, temp2);
	putpeople(name, phone, table_id, table);
	get_current_time(time_string);
	fprintf(myfile,"%s\t\tIn\t%s\t%s\n",time_string, name, phone);
	free(time_string);
}

//PERSON node를 만들어 get_person함수에서 입력받은 정보를 TABLE node에 저장
void putpeople(char* name, char* phone, int table_id, TABLES* table) {
	TABLE* temp;
	TABLE* temp2 = NULL;
	PERSON* last_person;
	for (temp = table->head; temp->next; temp = temp->next) {
		if (temp->next->table_id == table_id)
		{
			temp2 = temp->next;
			break;
		}
	}
	//입력받은 번호의 테이블 노드가 있다면 그 노드의 사람 리스트 마지막에 PERSON노드 추가
	if (temp2) {
		for (last_person = temp2->people; last_person->next; last_person = last_person->next) {

		}
		PERSON* people_temp;
		people_temp = (PERSON*)malloc(1 * sizeof(PERSON));
		people_temp->next = last_person->next;
		last_person->next = people_temp;
		people_temp->name = name;
		people_temp->phone = phone;
	}
	//없다면 테이블 노드를 table_id 순서에 맞게 생성후 리스트에 추가하고 PERSON 노드 추가
	else {
		TABLE* table_temp;
		TABLE* table_pre;
		TABLE* table_pre2 = table->head;
		PERSON* people_temp;
		table_temp = (TABLE*)malloc(1 * sizeof(TABLE));
		table_temp->people = (PERSON*)malloc(1 * sizeof(PERSON));
		people_temp = (PERSON*)malloc(1 * sizeof(PERSON));
		for (table_pre = table->head; table_pre->next; table_pre = table_pre->next) {
			if (table_pre->next->table_id < table_id){
				table_pre2 = table_pre->next;
				}
		}
		table_temp->menu.beer = 0;
		table_temp->menu.chicken = 0;
		table_temp->next = table_pre2->next;
		table_pre2->next = table_temp;
		
		
		
		table_temp->table_id = table_id;
		people_temp->name = name;
		people_temp->phone = phone;
		people_temp->next = NULL;
		table_temp->people->next = people_temp;

	}

}


//table_id 오름차순으로 속한 사람들, 메뉴를 전부 출력함.
void show(TABLES* table) {
	TABLE* temp_table;
	PERSON* temp_person;
	int i = 0;
	for (temp_table = table->head; temp_table->next; temp_table = temp_table->next) {
		printf("\n-------------------------\n");
		printf("테이블 ID: %d\n", temp_table->next->table_id);
		printf("치킨 %d마리\n", temp_table->next->menu.chicken);
		printf("생맥주 %d잔\n", temp_table->next->menu.beer);
		for (temp_person = temp_table->next->people; temp_person->next; temp_person = temp_person->next) {
			printf("손님 [%d]  이름:%s\n", i, temp_person->next->name);
			i++;
		}
		printf("-------------------------\n\n");
		i = 0;
	}
	//테이블이 없는 경우
	if (temp_table == table->head) {
		printf("손님이 있는 테이블이 없습니다.\n\n");
	}
}

//테이블 번호를 입력받은 후, 메뉴주문을 문자열형태로 받고 그 테이블의 menu에 chicken이나 beer를 증가시킴.
void order(TABLES* table) {
	int table_num;
	TABLE* tabletemp;
	TABLE* tabletemp2 = NULL;
	char food[ORDER_CODE_MAX_LEN];
	int many;
	//테이블이 하나도 없는 경우
	if (table->head->next == NULL) {
		printf("손님이 있는 테이블이 없습니다.\n\n");
	}
	//테이블이 있는 경우	
	else {
		printf("테이블번호를 입력해주세요: ");
		scanf("%d", &table_num);
		for (tabletemp = table->head; tabletemp->next; tabletemp = tabletemp->next) {
			if (table_num == tabletemp->next->table_id) {
				tabletemp2 = tabletemp->next;
				break;
			}

		}
		//특정 번호를 가진 테이블이 없는 경우
		if (!tabletemp2) {
			printf("%d번 테이블은 없습니다.\n", table_num);
		}
		//특정 번호를 가진 테이블이 있는 경우
		else {
			printf("\n주문 코드를 입력해주세요.\n");
			printf("주문 예1) 치킨 10마리: c10\n");
			printf("주문 예2) 생맥주 2잔: b2\n");
			printf(" >> ");
			scanf("%s", food);
			many = atoi(food + 1);
			//chicken주문인지, beer주문인지, 잘못된 주문인지 확인
			switch (food[0]) {
			case 98:
				tabletemp2->menu.beer += many;
				show(table);
				break;
			case 99:
				tabletemp2->menu.chicken += many;
				show(table);
				break;
			default:
				printf("음식 코드는 {치킨:c, 생맥주,b}만 가능합니다.\n\n");
			}
		}
	}
}

//테이블 번호와 사람이름을 입력받아서 해당하는 사람 노드를 할당 해제를 통해 삭제하고, log.txt에 출력
void leave(TABLES* table, FILE* myfile) {
	int table_num;
	TABLE* tabletemp;
	TABLE* tabletemp2 = NULL;
	char leave_pers[NAME_MAX_LEN];
	PERSON* pers_pre;
	PERSON* pers_pre2=NULL;
	PERSON* pers_temp;
	char* time_string = malloc(TIME_MAX_LEN * sizeof(char));
	//테이블이 하나도 없는 경우
	if (table->head->next == NULL) {
		printf("손님이 있는 테이블이 없습니다.\n\n");
	}
	//테이블이 있는 경우
	else {
		printf("테이블번호를 입력해주세요: ");
		scanf("%d", &table_num);
		for (tabletemp = table->head; tabletemp->next; tabletemp = tabletemp->next) {
			if (table_num == tabletemp->next->table_id) {
				tabletemp2 = tabletemp->next;
				break;
			}
		}
		//입력받은 번호의 테이블이 없는 경우
		if (!tabletemp2) {
			printf("%d번 테이블은 없습니다.\n", table_num);
		}
		//테이블이 있는 경우
		else {
			printf("이름을 입력해 주세요. (20자 이내) >>");
			scanf("%s", leave_pers);
			for (pers_pre = tabletemp2->people; pers_pre->next; pers_pre = pers_pre->next) {
				if (strcmp(pers_pre->next->name, leave_pers) == 0) {
					pers_pre2 = pers_pre;
					break;
				}
			}
			//테이블에 해당하는 이름의 사람이 없는 경우
			if (!pers_pre2) {
				printf("%d번 테이블에 %s씨는 없습니다.\n", table_num, leave_pers);
			}
			//해당하는 사람의 이름이 있는 경우
			else {
				pers_temp = pers_pre2->next;
				pers_pre2->next = pers_temp->next;

				get_current_time(time_string);
				fprintf(myfile, "%s\t\tOut\t%s\t%s\n", time_string, pers_temp->name, pers_temp->phone);
				free(pers_temp->phone);
				free(pers_temp->name);
				free(pers_temp);
				//테이블에 남은 사람이 없으면 테이블 노드 할당 해제
				if (tabletemp2->people->next == NULL) {
					tabletemp->next = tabletemp2->next;
					free(tabletemp2->people);
					free(tabletemp2);
				}
						show(table);

			}


		}
	}
	free(time_string);
}

//table node와 PERSON node, 그 외의 것들을 모두 할당 해제를 통해 삭제하고 log.txt에 출력
void quit(TABLES* table, FILE* myfile) {
	TABLE* table_temp;
	PERSON* person_temp;
	char* time_string = malloc(TIME_MAX_LEN * sizeof(char));
	for (table_temp = table->head; table_temp;) {
		if(table_temp->next)
		{
		for (person_temp = table_temp->next->people; person_temp;) {
			PERSON* person_temp2;
			get_current_time(time_string);
			if (person_temp->next)
				fprintf(myfile, "%s\t\tOut\t%s\t%s\n", time_string, person_temp->next->name, person_temp->next->phone);
			person_temp2 = person_temp;
			person_temp = person_temp2->next;
			free(person_temp2);
		}
	}
		TABLE* table_temp2;
		table_temp2 = table_temp;
		table_temp = table_temp2->next;
		free(table_temp2);
	}
	free(table);
	fclose(myfile);
	free(time_string);
}




