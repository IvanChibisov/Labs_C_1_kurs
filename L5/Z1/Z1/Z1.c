#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct List
{
	int value;
	struct List *prev;
	struct List *next;
};

void Add(struct List** ,int );

void Show(struct List*);

struct List* Reverse(struct List** );

int main()
{
	struct List *first = NULL;
	printf("Enter the List component,int Number, enter 0 to exit\n");
	int k = 1;
	while (k == 1)
	{
		int number;
		int logic = 0;
		if (!scanf("%d", &number))
		{
			printf("Wrong Enter");
			while (getchar() != '\n');
			logic = 1;
		}
		if (logic != 1)
		{
			if (getchar() != '\n')
			{
				logic = 1;
				while (getchar() != '\n');
			}
		}
		if (logic != 1)
		{
			if (number != 0)
			{
				Add(&first, number);
			}
			else
			{
				printf("Base List: \n");
				Show(first);
				first = Reverse(&first);
				printf("Transformed List: \n");
				Show(first);
				k = 0;
			}
		}
		
	}
	system("pause");
}

struct List* GetLast(struct List* p)
{
	struct List* pFind=p;
	if (pFind != NULL)
	{
		while (pFind->next != NULL)
			pFind = pFind->next;
		return pFind;
	}
	else
	{
		return NULL;
	}
}

void Add(struct List** p, int n) 
{
	struct List *pAdd = (struct List*)malloc(sizeof(struct List));
	pAdd->value = n;
	pAdd->next = NULL;
	struct List *pLast=GetLast(*p);
	if (pLast != NULL)
	{
		pAdd->prev = pLast;
		pLast->next = pAdd;
	}
	else
	{
		*p = pAdd;
		(*p)->prev = NULL;
	}
}

struct List* Reverse(struct List** p)
{
	struct List* pTime = *p;
	struct List* p2 = *p;
	while ((*p)->next != NULL)
	{
		pTime = (*p)->next;
		p2 = (*p)->next;
		if ((*p)->prev == NULL)
		{
			(*p)->prev = (*p)->next;
			(*p)->next = NULL;
		}
		else
		{
			(*p)->next = (*p)->prev;
			(*p)->prev = p2;
		}
		(*p) = p2;
	}
	if ((*p)->next == NULL)
	{
		(*p)->next = (*p)->prev;
		(*p)->prev = NULL;
	}
	return *p;
}

void Show(struct List* p)
{
	struct List* pTime = p;
	while (pTime->next != NULL)
	{
		printf("%d ", pTime->value);
		pTime = pTime->next;
	}
	printf("%d", pTime->value);
	printf("\n");
}