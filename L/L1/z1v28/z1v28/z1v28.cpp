// z1v28.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>
#include <locale>
#include <stdio.h>

//int Summ(int n, ...)
//{
//	int *ptr = &n;
//	ptr++;
//	int result = 0;
//	for (; n > 0; n--)
//	{
//		result += *ptr;
//		ptr++;
//	}
//	return result;
//}

int main()
{
//	int k = Summ(3, 4, 5, 6);
//	printf("%d", k);
	setlocale(LC_CTYPE, "Russian");
	setlocale(0, "ru-RU");
	int i, otv, k, rez, t, num, zf=0, f1, f2;
	printf( "Введите номер числа последовательности 1123581321345589... которое вы ходитите чтобы программа вывела\n");
	scanf_s("%d",&k);
	num = 2;
	printf( "Последовательность, заканчивающаяся на к ");
	f1 = 1;
	f2 = 1;
	if (k == 1) printf("1\n Его значение 1");
	else if (k == 2) printf("11\n Его значение 1");
	else
	{
		printf("11");
		for (i = 1; i <= k; i++)
		{

			rez = f1 + f2;
			f1 = f2;
			f2 = rez;
			while (rez>0)
			{
				rez = rez / 10;
				zf=zf+1;
			}
			rez = f2;
			while (num != k && zf>0)
			{
				t = rez / pow(10, zf - 1);
				rez = rez - t * pow(10, zf - 1);
				num = num + 1;
				otv = t;
				zf=zf-1;
				printf("%d", t);
			}

		}
		printf("\nЕго значение %d",otv);
	}
	_getch();
	return 0;
}

