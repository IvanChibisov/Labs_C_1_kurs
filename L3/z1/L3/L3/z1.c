#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void Swap(int R1, int R2,int** a,int n,int m,bool Wahl)
{
	if (Wahl == true)
	{
		int *Memory;
		Memory = (int *)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++)
		{
			Memory[i] = a[i][R1];
			a[i][R1] = a[i][R2];
			a[i][R2] = Memory[i];
		}
		free(Memory);
	}
	else
	{
		int *Memory;
		Memory = (int *)malloc(m * sizeof(int));
		for (int i = 0; i < m; i++)
		{
			Memory[i] = a[R1][i];
			a[R1][i] = a[R2][i];
			a[R2][i] = Memory[i];
		}
		free(Memory);
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_CTYPE, "Russian");
	int n, m;
	printf("Введите n и m, размеры матрицы/массива\n");
	if (!scanf_s("%d %d", &n, &m))
	{
		printf("Неверный ввод");
		_getch();
		return 0;
	}
	int **a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(m * sizeof(int));
	}
	printf("Сгенерированный массив \n");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j < i) 
				a[i][j] = 0;
			else 
				a[i][j] = rand() % 9+1 ;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	int *Rand;
	for (int i = 0; i <= n ; i++)
	{
		int Rand1 = rand() % m;
		int Rand2 = rand() % m;
		bool Wahl = true;
		Swap(Rand1, Rand2,a,n,m,Wahl);
	}
	// true - менять столбцы, false - строки
	for (int i = 0; i <= m ; i++)
	{
		int Rand1 = rand() % n;
		int Rand2 = rand() % n;
		bool Wahl = false;
		Swap(Rand1, Rand2, a, n, m, Wahl);
	}
	printf("Массив с случайным переставление строк и столбцов\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	int quantityNull = n - 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = i; j < m; j++)
		{
			int qtyNull = 0;
			for (int k = 0; k < n; k++)
			{
				if (a[k][j] == 0) 
					qtyNull++;
			}
			if (qtyNull == quantityNull)
			{
				quantityNull--;
				int Number;
				for (int k = i; k < n; k++)
				{
					if (a[k][j] != 0) 
						Number = k;
				}
				Swap(i, Number, a, n, m, false);
				Swap(i, j, a, n, m, true);
				break;
			}
		}
	}
	printf("Массис с обратно вернутыми строками и столбцами\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
	_getch();
}