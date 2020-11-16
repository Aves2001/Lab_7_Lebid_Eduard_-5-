#include <stdio.h>
#include "default_cfg.h"
#include <math.h>
#include <time.h>

#define _Low -100 // мінімальне число для генерації випадкових чисел
#define _High 100 // максимальне число для генерації випадкових чисел
int minn = -1, *pMINN = NULL; // індекс рядка, в якому було знайдено мінімальний добуток рядка

void init(int *size_n, int *size_m, int a[][*size_m]);
void print_mas(int *size_n, int *size_m, int a[][*size_m]);
void dob_n(int *size_n, int *size_m, int a[][*size_m]);
void dell_min_dob(int *size_n, int *size_m, int a[][*size_m]);

int main(void) {
	start_cfg();
	pMINN = &minn; // вказівник на індекс рядка, в якому було знайдено мінімальний добуток рядка

	int n, m, *size_n = NULL, *size_m = NULL;
	
	size_n = &n; // вказівник на кількість рядків
	size_m = &m; // вказівник на кількість стовпців
	
	printf("\nКількість рядків = ");
	scanf("%d", size_n);

	printf("Кількість стовпців = ");
	scanf("%d", size_m);
	
	int a[*size_n][*size_m]; // масив "а"
	init(size_n, size_m, a);
	print_mas(size_n, size_m, a);
	dob_n(size_n, size_m, a);
	dell_min_dob(size_n, size_m, a);
	print_mas(size_n, size_m, a);

	end_cfg();
	return 0;
}

void init(int *size_n, int *size_m, int a[][*size_m]){
const int Low = _Low, High = _High; 
srand((unsigned)time(0));

for (int i = 0; i < *size_n; i++)
{
	for (int j = 0; j < *size_m; j++)
	{
		a[i][j] =  Low + rand() % (High - Low + 1);
	}
}
return;
}

///////////////////////////////////////////////////////////////////////////
void print_mas(int *size_n, int *size_m, int a[][*size_m]){
		
	if (*size_n == 1 && *pMINN != -1)
	{
		SetColor(12,0);
		printf("\r\n\n У масиві лише один рядок, після його видалення, немає, що виводити на екран");
		SetColor(10,0);
		end_cfg();
		exit(1);
	}
	if (*pMINN != -1)
	{
		*size_n-=1;
	}

	printf("\r\n\n Масив:\n");
	for (int i = 0; i < *size_n; i++)
	{
		for (int j = 0; j < *size_m; j++)
		{
			printf("a[%d][%d] = %3d\t", i, j, a[i][j]);
		}
		printf("\n");
	}
}


///////////////////////////////////////////////////////////////////////////
void dob_n(int *size_n, int *size_m, int arr[][*size_m])
{
	long int dob = 1;
	_Bool check = 0;
	int min_dob = 0;
	int min_dob_i = 0;
	printf("\n");
	for (int i = 0; i < *size_n; i++)
	{
		for (int j = 0; j < *size_m; j++)
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
	*pMINN=min_dob_i;
return;
}

void dell_min_dob(int *size_n, int *size_m, int a[][*size_m]){

			for (int i = *pMINN; i < *size_n-1; i++)
			{		
				for (int j = 0; j < *size_m; j++)
				{
					a[i][j] = a[i+1][j];
				}
			}
	
return;
}