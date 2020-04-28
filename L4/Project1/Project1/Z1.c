#include <stdio.h>
#include <conio.h>

int lengthStr(char* str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return i;
}

void MoveLeft(char* s,int BeginMove,int EndMove, int MoveSize)
{
	int Leng = lengthStr(s);
	for (int i = 0; i < MoveSize; i++)
	{
		for (int j = BeginMove; j <= EndMove; j++)
		{
			s[j-1] = s[j];
		}
		BeginMove--;
	}
	

}

void MoveRight(char* s, int BeginMove, int EndMove, int MoveSize)
{
	int Leng = lengthStr(s);
	for (int i = 0; i < MoveSize; i++)
	{
		for (int j = EndMove; j >= BeginMove; j--)
		{
			s[j +1] = s[j];
		}
		EndMove++;
	}

}

struct status_type
{
	unsigned e : 1;
	unsigned z : 1;
	unsigned d : 1;
	unsigned v : 1;
	unsigned f : 1;
	unsigned s : 1;
	unsigned sib : 1;
	unsigned a : 1;
}status;

void Swap(char* str, int BeginMax, int EndMax, int BeginMin, int EndMin);

int Summ(int n, ...)
{
	int *ptr = &n;
	ptr++;
	int result = 0;
	for (; n > 0; n--)
	{
		result += *ptr;
		ptr++;
	}
	return result;
}
int main()
{
	int k = Summ(3, 4, 5, 6);
	printf("%d", k);
	status = 10;
	int k = 1, i = 0;
	char**str = (char**)malloc(sizeof(char*) * 1000);
	printf("Enter the drains. To complete the input, enter 0\n");
	while (k != 0)
	{
		str[i] = (char*)malloc(sizeof(char) * 1000);
		gets(str[i]);
		if (str[i][0] == '0'&&lengthStr(str[i]) == 1)
			k = 0;
		i++;
	}
	int maxAll = 0, minAll = 1001;
	for (int j = 0; j < i; j++)
	{
		int max = 0,indexMaxBegin=0,indexMaxEnd=0,indexMinBegin=0,indexMinEnd=0,min=1001;
		int timeIndexBegin = 0;
		for ( int g=0 ; str[j][g] != '\0';g++)
		{
			int timeIndexEnd = 0;
			
			if (str[j][g]==' ')
			{
				timeIndexEnd = g - 1;
				while (str[j][g] == ' ')
				{
					g++;
				}
				int timeMax = 0;
				timeMax = timeIndexEnd - timeIndexBegin+1;
				if (timeMax > max)
				{
					indexMaxBegin = timeIndexBegin;
					indexMaxEnd = timeIndexEnd;
					max = timeMax;
				}
				if (timeMax < min)
				{
					indexMinBegin = timeIndexBegin;
					indexMinEnd = timeIndexEnd;
					min = timeMax;
				}
				timeIndexBegin = g;
			}
			if (str[j][g] == '!' || str[j][g] == '?' || str[j][g] == '.')
			{
				
				timeIndexEnd = g - 1;
				int timeMax = 0;
				timeMax = timeIndexEnd - timeIndexBegin + 1;
				if (timeMax > max)
				{
					indexMaxBegin = timeIndexBegin;
					indexMaxEnd = timeIndexEnd;
					max = timeMax;
				}
				if (timeMax < min)
				{
					indexMinBegin = timeIndexBegin;
					indexMinEnd = timeIndexEnd;
					min = timeMax;
				}
				timeIndexBegin = g;
				Swap(str[j], indexMaxBegin, indexMaxEnd, indexMinBegin, indexMinEnd);
				if (maxAll < max)
					maxAll = max;
				if (minAll > min)
					minAll = min;
				max = 0;
				indexMaxBegin = 0;
				indexMaxEnd = 0;
				indexMinBegin = 0;
				indexMinEnd = 0;
				min = 1001;
				g++;
				while (str[j][g] == ' ')
				{
					g++;
				}
				timeIndexBegin=g;
			}
			
		}
		
	}
	printf("The biggest word is long %d , The smallest word is long %d\n", maxAll, minAll);
	for (int j = 0; j < i-1; j++)
		{
			puts(str[j]);
		}
	_getch();
	return 0;
}
void Swap(char* str, int BeginMax, int EndMax, int BeginMin, int EndMin)
{
	if (BeginMax > BeginMin)
	{
		int Difference;
		char str1[200], str2[200];
		int Index = 0;
		for (int i = BeginMax; i <= EndMax; i++)
		{
			str1[Index] = str[i];
			Index++;
		}
		str1[Index] = '\0';
		Index = 0;
		for (int i = BeginMin; i <= EndMin; i++)
		{
			str2[Index] = str[i];
			Index++;
		}
		str2[Index] = '\0';
		Difference = (EndMax - BeginMax) - (EndMin - BeginMin);
		MoveRight(str, EndMin, BeginMax, Difference);
		Index = 0;
		for (int i = BeginMax+Difference; i <= BeginMax+Difference + EndMin - BeginMin; i++)
		{
			str[i] = str2[Index];
			Index++;
		}
		Index = 0;
		for (int i = BeginMin ; i <= BeginMin + EndMax - BeginMax; i++)
		{
			str[i] = str1[Index];
			Index++;
		}
	}
	else
	{
		int Difference;
		char str1[200], str2[200];
		int Index = 0;
		for (int i = BeginMax; i <= EndMax; i++)
		{
			str1[Index] = str[i];
			Index++;
		}
		str1[Index] = '\0';
		Index = 0;
		for (int i = BeginMin; i <= EndMin; i++)
		{
			str2[Index] = str[i];
			Index++;
		}
		str2[Index] = '\0';
		Difference = (EndMax - BeginMax) - (EndMin - BeginMin);
		MoveLeft(str, EndMax, BeginMin, Difference);
		Index = 0;
		for (int i = BeginMax; i <= BeginMax + EndMin - BeginMin; i++)
		{
			str[i] = str2[Index];
			Index++;
		}
		Index = 0;
		for (int i = BeginMin-Difference; i <= BeginMin + EndMax - BeginMax-Difference; i++)
		{
			str[i] = str1[Index];
			Index++;
		}
	}
}