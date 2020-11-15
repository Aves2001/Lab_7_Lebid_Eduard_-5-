#include <stdio.h>
#include "default_cfg.h"

void init(double *a, unsigned int *n); // ініціалізація масива та вивід його вмісту на екран
unsigned int sumDilyanock(const double *arr, unsigned int *n); //Сума кількісті ділянок масиву, де елементи змінюють знак.

int main(void) {
	start_cfg();

	unsigned int n, *pN = NULL;
	printf("\nРозмір = ");
	scanf("%u", &n);

	pN = &n; // вказівник на розмір масиву
	double a[*pN]; // масив "а"

	init(a, pN);
	unsigned int summ = sumDilyanock(a, pN);

	printf("\r\n\n Кількість ділянок = ");

	if (summ > 0) //якщо сумма більша нуля, тоді виводить жовтим кольором, інакше червоним
	{
		SetColor(14,0); // жовний текст
		printf("%d\n", summ);
		SetColor(10,0); // зелений текст
	}
	else {
		SetColor(12,0); // червоний текст
		printf("%d\n", summ);
		SetColor(10,0); // зелений текст
	}

	end_cfg();
	return 0;
}

///////////////////////////////////////////////////////////////////////////
unsigned int sumDilyanock(const double *arr, unsigned int *n) //Сума кількісті ділянок масиву, де елементи змінюють знак.
{
	int s = 0;

	for (int i = 1; i < *n; i++)
	{
		if (arr[i] >= 0 && arr[i-1] < 0)
		{
			s++;
		}

		else if (arr[i] < 0 && arr[i-1] >= 0)
		{
			s++;
		}
	}
return s;
}

///////////////////////////////////////////////////////////////////////////
void init(double *a, unsigned int *n){
printf("\n");
// ініціалізація масива
for (int i = 0; i < *n; i++) // заповнення масива
{
	printf("a[%d] = ", i);
	scanf("%lf", &a[i]);
}
	printf("\r\n\n Масив:\n");
	for (int i = 0; i < *n; i++) // вивід масива на екран
	{
		printf("\na[%d] = %.10g", i, a[i]);
	}
return;
}