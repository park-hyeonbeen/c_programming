#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "macro.h"
#include "utils.h"
#include "list.h"

//����ũ�� �����.
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
	printf("***********************����ũ ���� �� ���� ��Ź�帳�ϴ�.**********************\n");
}

//�մ��� �̸�, ��ȭ��ȣ, ���̺� ��ȣ�� �Է¹޾� PERSON ��带 ����� TABLE��忡 �����ϴ� �Լ�
void enter(TABLES* table, FILE* myfile) {
	char mask;
	printf("����ũ �����ϼ̳���? (y/n) >> ");
	getchar();
	scanf("%c", &mask);
	switch (mask) {
		//y�� �Է¹޾��� ��
	case 121:
		get_person(table, myfile);
		show(table);
		break;
		//n�� �Է¹޾��� ��
	case 110:
		print_mask();
		break;
		//�� ���� �� �Է¹޾��� ��
	default:
		printf("�Է��� ���� ��ȿ���� �ʽ��ϴ�.\n");
		enter(table, myfile);
	}
}

//�մ��� �̸�, ��ȭ��ȣ�� ���ڿ����·� �Է¹ް�, ���̺� ��ȣ�� �Է¹޾� log.txt�� ����ϴ� �Լ�
void get_person(TABLES* table, FILE* myfile) {
	int length;
	char temp1[NAME_MAX_LEN];
	char temp2[PHONE_MAX_LEN];
	char* name;
	char* phone;
	int table_id;
	char* time_string = malloc(TIME_MAX_LEN*sizeof(char));
	printf("�̸��� �Է����ּ���. (20���̳�)>> ");
	scanf("%s", temp1);
	printf("��ȭ��ȣ�� �Է����ּ���. (-���� 11��)>> ");
	scanf("%s", temp2);
	printf("�� �� ���̺� �����ðڽ��ϱ�?>> ");
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

//PERSON node�� ����� get_person�Լ����� �Է¹��� ������ TABLE node�� ����
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
	//�Է¹��� ��ȣ�� ���̺� ��尡 �ִٸ� �� ����� ��� ����Ʈ �������� PERSON��� �߰�
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
	//���ٸ� ���̺� ��带 table_id ������ �°� ������ ����Ʈ�� �߰��ϰ� PERSON ��� �߰�
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


//table_id ������������ ���� �����, �޴��� ���� �����.
void show(TABLES* table) {
	TABLE* temp_table;
	PERSON* temp_person;
	int i = 0;
	for (temp_table = table->head; temp_table->next; temp_table = temp_table->next) {
		printf("\n-------------------------\n");
		printf("���̺� ID: %d\n", temp_table->next->table_id);
		printf("ġŲ %d����\n", temp_table->next->menu.chicken);
		printf("������ %d��\n", temp_table->next->menu.beer);
		for (temp_person = temp_table->next->people; temp_person->next; temp_person = temp_person->next) {
			printf("�մ� [%d]  �̸�:%s\n", i, temp_person->next->name);
			i++;
		}
		printf("-------------------------\n\n");
		i = 0;
	}
	//���̺��� ���� ���
	if (temp_table == table->head) {
		printf("�մ��� �ִ� ���̺��� �����ϴ�.\n\n");
	}
}

//���̺� ��ȣ�� �Է¹��� ��, �޴��ֹ��� ���ڿ����·� �ް� �� ���̺��� menu�� chicken�̳� beer�� ������Ŵ.
void order(TABLES* table) {
	int table_num;
	TABLE* tabletemp;
	TABLE* tabletemp2 = NULL;
	char food[ORDER_CODE_MAX_LEN];
	int many;
	//���̺��� �ϳ��� ���� ���
	if (table->head->next == NULL) {
		printf("�մ��� �ִ� ���̺��� �����ϴ�.\n\n");
	}
	//���̺��� �ִ� ���	
	else {
		printf("���̺��ȣ�� �Է����ּ���: ");
		scanf("%d", &table_num);
		for (tabletemp = table->head; tabletemp->next; tabletemp = tabletemp->next) {
			if (table_num == tabletemp->next->table_id) {
				tabletemp2 = tabletemp->next;
				break;
			}

		}
		//Ư�� ��ȣ�� ���� ���̺��� ���� ���
		if (!tabletemp2) {
			printf("%d�� ���̺��� �����ϴ�.\n", table_num);
		}
		//Ư�� ��ȣ�� ���� ���̺��� �ִ� ���
		else {
			printf("\n�ֹ� �ڵ带 �Է����ּ���.\n");
			printf("�ֹ� ��1) ġŲ 10����: c10\n");
			printf("�ֹ� ��2) ������ 2��: b2\n");
			printf(" >> ");
			scanf("%s", food);
			many = atoi(food + 1);
			//chicken�ֹ�����, beer�ֹ�����, �߸��� �ֹ����� Ȯ��
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
				printf("���� �ڵ�� {ġŲ:c, ������,b}�� �����մϴ�.\n\n");
			}
		}
	}
}

//���̺� ��ȣ�� ����̸��� �Է¹޾Ƽ� �ش��ϴ� ��� ��带 �Ҵ� ������ ���� �����ϰ�, log.txt�� ���
void leave(TABLES* table, FILE* myfile) {
	int table_num;
	TABLE* tabletemp;
	TABLE* tabletemp2 = NULL;
	char leave_pers[NAME_MAX_LEN];
	PERSON* pers_pre;
	PERSON* pers_pre2=NULL;
	PERSON* pers_temp;
	char* time_string = malloc(TIME_MAX_LEN * sizeof(char));
	//���̺��� �ϳ��� ���� ���
	if (table->head->next == NULL) {
		printf("�մ��� �ִ� ���̺��� �����ϴ�.\n\n");
	}
	//���̺��� �ִ� ���
	else {
		printf("���̺��ȣ�� �Է����ּ���: ");
		scanf("%d", &table_num);
		for (tabletemp = table->head; tabletemp->next; tabletemp = tabletemp->next) {
			if (table_num == tabletemp->next->table_id) {
				tabletemp2 = tabletemp->next;
				break;
			}
		}
		//�Է¹��� ��ȣ�� ���̺��� ���� ���
		if (!tabletemp2) {
			printf("%d�� ���̺��� �����ϴ�.\n", table_num);
		}
		//���̺��� �ִ� ���
		else {
			printf("�̸��� �Է��� �ּ���. (20�� �̳�) >>");
			scanf("%s", leave_pers);
			for (pers_pre = tabletemp2->people; pers_pre->next; pers_pre = pers_pre->next) {
				if (strcmp(pers_pre->next->name, leave_pers) == 0) {
					pers_pre2 = pers_pre;
					break;
				}
			}
			//���̺� �ش��ϴ� �̸��� ����� ���� ���
			if (!pers_pre2) {
				printf("%d�� ���̺� %s���� �����ϴ�.\n", table_num, leave_pers);
			}
			//�ش��ϴ� ����� �̸��� �ִ� ���
			else {
				pers_temp = pers_pre2->next;
				pers_pre2->next = pers_temp->next;

				get_current_time(time_string);
				fprintf(myfile, "%s\t\tOut\t%s\t%s\n", time_string, pers_temp->name, pers_temp->phone);
				free(pers_temp->phone);
				free(pers_temp->name);
				free(pers_temp);
				//���̺� ���� ����� ������ ���̺� ��� �Ҵ� ����
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

//table node�� PERSON node, �� ���� �͵��� ��� �Ҵ� ������ ���� �����ϰ� log.txt�� ���
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




