#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <locale.h>

int n = 1;

int fact(int n)
{
	int f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}

float recFunc(float x, float e)
{
	float Sin = sin(x);
	static float sum = 0;
	sum += pow(-1, n - 1)*powl(x, 2 * n - 1) / fact(2 * n - 1);
	float k = fabs(Sin - sum);
	if (k < e) return sum;
	else
	{
		n++;
		recFunc(x, e);
	}
	return sum; 

}

/*
float Func(float x, float e)
{
	float Sin = sin(x);
	float sum = 0;
	while (fabs(Sin - sum) > e)
	{
		sum += pow(-1, n - 1)*powf(x, 2 * n - 1) / fact(2 * n - 1);
		n++;
	}
	n--;
	return sum;
}*/
int main()
{
	setlocale(LC_CTYPE, "Russian");
	float e;
	n = 1;
	printf("Введите погрешность рассчета ");
	if (!scanf_s("%f", &e))
	{
		printf("Неверные данные ввода");
		_getch();
		return 0;
	}
	printf("Введите х, для которого исследовать справедливость равенства ");
	float x;
	if (!scanf_s("%f", &x))
	{
		
		printf("Неверные данные ввода");
		_getch();
		return 0;
	}
	
	float ressult = recFunc(x, e);
	printf("Значение функции sin(x) = %f , а значение ряда = %f\n", sin(x), ressult);
	printf("При n равном %d разность между функцией и рядом меньше е = %f", n, e);
	_getch();
}