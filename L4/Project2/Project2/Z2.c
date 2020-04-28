#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool Strcmp(char*, char*);

void InsertWord(char*, int, int, char*);

int Length(char*);

int main()
{
	FILE *in, *out,*change;
	int index = 0;
	out = fopen("output.txt", "w");
	char** str = (char**)malloc(sizeof(char*) * 1000);
	str[index] = (char*)malloc(sizeof(char) * 1000);
	if ((in = fopen("input.txt", "rt")) != NULL)
	{
		while (!feof(in))
		{
			fgets(str[index], 1000, in);
			index++;
			str[index] = (char*)malloc(sizeof(char) * 1000);
		}
	}
	int indexChange=0;
	char** StrChange = (char**)malloc(sizeof(char*) * 1000);
	StrChange[indexChange] = (char*)malloc(sizeof(char) * 1000);
	if ((change = fopen("change.txt", "rt")) != NULL)
	{			
		while (!feof(change))
		{
			fscanf(change, "%s", StrChange[indexChange]);
			indexChange++;
			StrChange[indexChange] = (char*)malloc(sizeof(char) * 1000);
		}
	}
	for (int i = 0; i < index; i++)
	{
		for (int j = 0; j < indexChange; j = j + 2)
		{
			int l = 0;
			char* Word = (char*)malloc(sizeof(char) * 1000);
			int indexWord = 0, k = 0, indexBegin = 0, IndexEnd;
			while (str[i][k]!='\0')
			{
				if (str[i][k] == ' ' || str[i][k] == '\0' || str[i][k] == '\n' || str[i][k] == '.' || str[i][k] == '!' || str[i][k] == '?' || str[i][k] == ',')
				{
					IndexEnd = k-1 ;
					Word[indexWord] = '\0';
					if (Strcmp(Word, StrChange[j]) == true)
					{
						InsertWord(str[i], indexBegin, IndexEnd, StrChange[j + 1]);
					}
					if (str[i][k] == '\n' || str[i][k] == '.' || str[i][k] == '!' || str[i][k] == '?' || str[i][k] == ','|| str[i][k] == ' ')
						k++;
					while (str[i][k] == ' ')
						k++;
					l = 1;
					free(Word);
					char* Word = (char*)malloc(sizeof(char) * 1000);
					indexWord = 0;
					indexBegin = k;
				}
				else
				{
					Word[indexWord] = str[i][k];
					indexWord++;
					k++;
				}
				if (str[i][k] == '\0'&&l!=1)
				{
					IndexEnd = k - 1;
					Word[indexWord] = '\0';
					if (Strcmp(Word, StrChange[j]) == true)
					{
						InsertWord(str[i], indexBegin, IndexEnd, StrChange[j + 1]);
					}
					while (str[i][k] == ' ')
						k++;
					k--;
				}
			}
		}
	}
	for (int i = 0; i < index; i++)
	{
		fputs(str[i], out);
	}
	fclose(in);
	fclose(out);
	fclose(change);
	return 0;
}

void MoveLeft(char*s,int end,int begin)
{
	for (int i = end+1 ; i > begin; i--)
		if (s[i] != '\n')
			s[i - 1] = s[i];
		else
		{
			s[i - 1] = '\0';
		}
}

void MoveRigth(char* s, int begin)
{
	int leng = Length(s),i;
	for ( i = leng-1; i>=begin; i--)
		s[i + 1] = s[i];
	s[leng+1] = '\0';
}

int Length(char* s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

bool Strcmp(char* str1, char* str2)
{
	int i;
	for (i = 0; str1[i] != '\0'; i++)
		if (str1[i] != str2[i]) return false;
	for (i = 0; str2[i] != '\0'; i++)
		if (str1[i] != str2[i]) return false;
	return true;
}

void InsertWord(char* str, int Begin, int End, char* word)
{
	int lengWord = Length(word);
	int leng = End-Begin + 1;
	if (leng < lengWord)
	{
		while (leng != lengWord)
		{
			MoveRigth(str, Begin);
			End++;
			leng++;
		}
	}
	else
	{
		while (leng != lengWord)
		{
			MoveLeft(str, End, Begin);
			End--;
			leng--;
		}
	}
	int Index = 0;
	for (int i = Begin; i <= End; i++)
	{
		str[i] = word[Index];
		Index++;
	}
	int j;
	for (j = 0; str[j] != '\0'; j++);
	if (str[j - 1] != '\n')
	{
		str[j] = '\n';
		str[j + 1] = '\0';
	}

}