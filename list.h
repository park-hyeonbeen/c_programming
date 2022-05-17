#pragma once
typedef struct Menu {
	int chicken;
	int beer;
}MENU;

typedef struct Person {
	char* name;
	char* phone;
	struct Person* next;
} PERSON;

typedef struct Table {
	int table_id;
	struct Menu menu;
	struct Person* people;
	struct Table* next;
} TABLE;

typedef struct Tables {
	struct Table* head;
}TABLES;

void print_mask();
void enter(TABLES* table, FILE* myfile);
void get_person(TABLES* table, FILE* myfile);
void putpeople(char* name, char* phone, int table_id, TABLES* table);
void show(TABLES* table);
void order(TABLES* table);
void leave(TABLES* table, FILE* myfile);
void quit(TABLES* table, FILE* myfile);