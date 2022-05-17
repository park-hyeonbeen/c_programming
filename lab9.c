#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_ary(int* a);
void partial_print(int* arr_start, int size);
int partial_sum(int* arr_start, int* arr_end);
void get_num(int* strt, int* end);
void print_all(int* a, int strt, int end);
void print_partial(int* a,int strt, int end);
int main() {
	int	a[10] = { 0 };
	int strt = 0;
	int end = 9;
	get_ary(a);
	print_all(a,strt, end);
	get_num(&strt, &end);
	print_partial(a, strt, end);
}
void get_ary(int* a) {
	printf("Enter 10 elements of array: " );
	for (int i = 0; i < 10; i++) {
		scanf("%d", a+i);
	}
}

void partial_print(int* arr_start, int size) {
	for (int i = 0; i <= size; i++) {
		printf("%d ",*(arr_start+i));
	}
}

int partial_sum(int* arr_start, int* arr_end) {
	int sum = 0;
	for (int i = 0; i <= arr_end-arr_start; i++) {
		sum += *(arr_start + i);
	}
	return sum;
}

void get_num(int* strt, int* end) {
	printf("\nEnter the starting and ending index: ");
	scanf("%d %d", strt, end);
}

void print_all(int* a, int strt, int end) {
	printf("Numbers that you enter are: ");
	partial_print(a, end-strt);
}

void print_partial(int* a, int strt, int end) {
	int sum;
	sum = partial_sum(a+strt,a+end);
	printf("Sum from array[%d] to array[%d] is %d\n", strt, end, sum);
	printf("partial array output: ");
	partial_print(a+strt, end-strt);
}