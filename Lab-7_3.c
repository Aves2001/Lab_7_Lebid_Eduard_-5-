#include <stdio.h>
#include "default_cfg.h"
#include <math.h>
#include <time.h>

#define _Low -100
#define _High 100
#define size_n 3
#define size_m 4
int minn = 0;

int* init(int a[][size_m]);
void print_mas(char name, int n, int a[][size_m]);
void dob_n(int (arr)[size_n][size_m]);
int* dell_min_dob(int b[][size_m], int a[][size_m], int min);


int main(void) {
	start_cfg();

	int a[size_n][size_m]; // масив "а"
	int b[size_n-1][size_m];
	init(a);
	print_mas('a', size_n, a);

	dob_n(a);

	dell_min_dob(b, a, minn);

	printf("\n");
	print_mas('b', size_n-1, b);

	end_cfg();
	return 0;
}

///////////////////////////////////////////////////////////////////////////
int* init(int a[][size_m]){
const int Low = _Low, High = _High; 
srand((unsigned)time(0));

for (int i = 0; i < size_n; i++)
{
	for (int j = 0; j < size_m; j++)
	{
		a[i][j] =  Low + rand() % (High - Low + 1);
	}
}
return *a;
}

///////////////////////////////////////////////////////////////////////////
void print_mas(char name, int n, int a[][size_m]){
	printf("\r\n\n Масив:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < size_m; j++)
		{
			printf("%c[%d][%d] = %3d\t", name, i, j, a[i][j]);
		}
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////////////////
void dob_n(int (arr)[size_n][size_m])
{
	long int dob = 1;
	_Bool check = 0;
	int min_dob = 0;
	int min_dob_i = 0;
	printf("\n");
	for (int i = 0; i < size_n; i++)
	{
		for (int j = 0; j < size_m; j++)
		{
			dob *= arr[i][j];
		}
		if (!check)
		{
			min_dob = dob;
		}
		if (dob <= min_dob)
		{
			min_dob = dob;
			min_dob_i = i;
		}
		printf(" Добуток %d рядка: %ld\n", i+1, dob);
		check = 1;
		dob = 1;
	}
	printf("\n Мінімальний добуток в %d рядку (a[%d][*])", min_dob_i+1, min_dob_i);
	minn=min_dob_i;
return;
}

///////////////////////////////////////////////////////////////////////////
int* dell_min_dob(int b[][size_m], int a[][size_m], int min){
	int en = 0;

			for (int i = 0; i < size_n-1; i++)
			{		
				if (i == min)
				{
					en = 1;
				}
				for (int j = 0; j < size_m; j++)
				{
					b[i][j] = a[i+en][j];
				}
			}
	
return *b;
}
