#include <windows.h>
// #include <conio.h>

int chcp, chcpOut; // start_cfg  |  end_cfg


void SetColor(int text, int background) // для встановки кольору тексту і фона
{
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Error_RED() // виводить на екран Error червоним кольором із звуком
{
	SetColor(12,0);
	printf("\r\n\a[Error] ");
	SetColor(10,0);
}

void start_cfg() // стандартні настройки при запуску програми
{
	system("color 0a"); // встановлює зелений текст і чорний фон

// Збереження значення кодової сторінки
	chcp = GetConsoleCP();
	chcpOut = GetConsoleOutputCP();

// Встановлення кодової сторінки UTF-8
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
//-------------------------------
}

void end_cfg() // стандартні настройки при завершенні програми
{
	SetColor(10,0); // встановлює зелений текст і чорний фон
	// Повернення значення кодової сторінки яке було до запуску програми
	SetConsoleCP(chcp);
	SetConsoleOutputCP(chcpOut);
	// getch();
	printf("\r\n\n");
	system("pause"); // пауза для того щоби можна було ознайомитись з результатом роботи програми
}