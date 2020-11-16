#include <stdio.h>
#include "default_cfg.h"
#include <math.h>
#include <time.h>

#define _Low -100 // мінімальне число для генерації випадкових чисел
#define _High 100 // максимальне число для генерації випадкових чисел

void init(int *a, int *n);  // ініціалізація масива та вивід його вмісту на екран
int minABS(const int *arr, int *n); // мінімальний за модулем елемент масиву
void dobutok00(const int *arr, int *n); //  добуток елементів масиву, розташованих між першим й останнім нульовими елементами

int main(void) {
	start_cfg();

	int n, *pN = NULL;
	printf("\nРозмір = ");
	scanf("%d", &n);

	pN = &n; // вказівник на розмір масиву

	int a[*pN]; // масив "а"

	init(a, pN);

	printf("\r\n\n 1) Мінамальний за модулем елемент = ");

		SetColor(14,0); // жовний текст
		printf("%d\n", minABS(a, pN));
		SetColor(10,0); // зелений текст

		dobutok00(a, pN);

	end_cfg();
	return 0;
}


///////////////////////////////////////////////////////////////////////////
int minABS(const int *arr, int *n)
{
	int min = arr[0];

	for (int i = 0; i < *n; i++)
	{
		if (abs(arr[i]) < abs(min))
		{
			min = arr[i];
		}
	}
return min;
}

///////////////////////////////////////////////////////////////////////////
void dobutok00(const int *arr, int *n){
	int dob = 1;
	int index_1 = -1;
	int index_2 = -1;

	for (int i = 0; i < *n; i++) // індекс першого нуля
	{
		if (arr[i] == 0)
		{
			index_1 = i;
			// printf("\n         %d", index_1);
			break;
		}
	}

	for (int j = *n-1; j >= 0; j--) // індекс останнього нуля
	{
		if (arr[j] == 0)
		{
			index_2 = j;
			// printf("\n         %d", index_2);
			break;
		}
	}

	// printf("\nindex_1 = %d| \n index_2 = %d|", index_1, index_2);

	if (index_1 == -1 && index_2 == -1)
	{
		SetColor(12,0);
		printf("\r\n\n У масиві немає нульових елементів");
		end_cfg();
		exit(1);
	} else if (index_1 == index_2)
	{
		SetColor(12,0);
		printf("\r\n\n У масиві тільки один нульовий елемент");
		end_cfg();
		exit(2);
	} else if (index_2 - index_1 == 1)
	{
		SetColor(12,0);
		printf("\r\n\n У масиві два нульові елементи, які знаходяться поряд один з одним");
		end_cfg();
		exit(3);
	}
		for (int i = index_1+1; i < index_2; i++)
		{
			dob *= arr[i];
		}

		printf("\r\n 2) добуток елементів масиву,\n розташованих між першим й останнім\n нульовими елементами = ");

		SetColor(14,0); // жовний текст
		printf("%d\n", dob);
		SetColor(10,0); // зелений текст
return;
}

///////////////////////////////////////////////////////////////////////////
void init(int *a, int *n){
const int Low = _Low, High = _High; 
srand((unsigned)time(0)); // для генерації нових чисел кожного разу при запуску програми
printf("\n");
for (int i = 0; i < *n; i++)
{
	a[i] = Low + rand() % (High - Low + 1); //заповнення масива випадковими числами в діапазоні від Low до High
}
	printf("\r\n\n Масив:\n");
	for (int i = 0; i < *n; i++)
	{
		printf("\na[%d] = %d", i, a[i]);
	}
return;
}