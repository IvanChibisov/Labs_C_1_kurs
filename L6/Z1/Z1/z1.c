#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct MyBinTree
{
	struct MyBinTree *left, *right;
	int amt;
	char letter;
};

void AddTree(struct MyBinTree ** begin, char c);

void Beat(struct MyBinTree* begin);

int vowels = 0, consonants = 0;

int main()
{
	setvbuf(stdin, NULL, _IOLBF, 32760);
	int key = 1;
	while (key == 1)
	{
		printf("Enter the string:\n");
		char k = '2';
		int leng = 1, l = 1000;
		char *str = (char*)malloc(sizeof(char) * l);
		
		while (k != '\n')
		{
			fflush(stdin);
			k=getchar();
			if (k == '\n')
				str[leng] = '\0';
			else
			{
				str[leng] = k;
				leng++;
				if (leng == l)
				{
					
					l = l + 1000;
					str = (char*)realloc(str, sizeof(char)*l);
				}
			}
		}
		struct MyBinTree *Begin = NULL;
		for (int j = 0; j < leng; j++)
		{
			AddTree(&Begin, str[j]);
		}
		Beat(Begin);
		printf("Vowels letter = %d, consonants letter= %d\n", vowels, consonants);
		if (vowels > consonants)
			printf("Vowels more!\n");
		if (vowels < consonants)
			printf("Consonants more!\n");
		if (vowels == consonants)
			printf("Number equal!\n");
		printf("To repeat, press Space\n");
		char c;
		c = getch();
		if ((int)c == 32)
		{
			key = 1;
		}
		else
			key = 0;
		vowels = 0;
		consonants = 0;
	}
}

struct MyBinTree* FindPlace(struct MyBinTree* begin, int num)
{
	struct MyBinTree* temp=NULL;
	if (begin->left == NULL && begin->right == NULL && (int)begin->letter == num)
	{
		begin->amt++;
		return NULL;
	}
	if (begin->left == NULL && begin->right == NULL)
	{
		return begin;
	}
	if (num > (int)begin->letter)
	{
		if (begin->right != NULL)
			temp=FindPlace(begin->right, num);
		else
			return begin;
	}
	if (num < (int)begin->letter)
	{
		if (begin->left != NULL)
		{
			temp=FindPlace(begin->left, num);
		}
		else
			return begin;
	}
	if (num == (int)begin->letter)
	{
		begin->amt++;
		return NULL;
	}
	return temp;
}

void AddTree(struct MyBinTree** begin, char c)
{
	struct MyBinTree* AddElem = (struct MyBinTree*)malloc(sizeof(struct MyBinTree));
	AddElem->left = NULL;
	AddElem->right = NULL;
	AddElem->amt = 1;
	AddElem->letter = c;
	if (*begin == NULL)
	{
		*begin = AddElem;
	}
	else
	{
		struct MyBinTree* time = FindPlace(*begin, (int)c);
		if (time != NULL)
		{
			if ((int)time->letter > (int)c)
				time->left = AddElem;
			if ((int)time->letter < (int)c)
				time->right = AddElem;
		}
	}
}

void Beat(struct MyBinTree* begin)
{
	if (begin == NULL)
		return;
	Beat(begin->left);
	int let = (int)begin->letter;
	if ((let > 64 && let < 91) || (let > 96 && let < 123))
	{
		if (begin->letter == 'a' || begin->letter == 'A' ||
			begin->letter == 'e' || begin->letter == 'E' ||
			begin->letter == 'i' || begin->letter == 'I' ||
			begin->letter == 'u' || begin->letter == 'U' ||
			begin->letter == 'o' || begin->letter == 'O' ||
			begin->letter == 'y' || begin->letter == 'Y')
		{
			vowels += begin->amt;
		}
		else
			consonants += begin->amt;
	}
	Beat(begin->right);
	return;
}