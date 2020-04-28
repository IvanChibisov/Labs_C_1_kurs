#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Type
{
	char AirType[100];
	int NumberOfPassengers;
	int Busy;
};

typedef struct BelAvia
{
	int Number;
	struct Type AircraftType;
	char Route[100];
	char IntermediatePoint[1000];
	int DepartureTime;
	int Day[7];
	struct BelAvia *next;
	struct BelAvia *prev;
};

void Arr(struct BelAvia* l)
{
	for (int i = 0; i < 7; i++)
	{
		l->Day[i] = 0;
	}
	return;
}

struct BelAvia *Begin;
struct BelAvia *This;

void Add(char str[]);
void GetNumber(char str[]);
void GetAirLine(char str[]);
void GetRoute(char str[]);
void GetDay(char str[]);
void GetPoint(char str[]);
void GetTime(char str[]);
void ShowAll();
void Find();
void FindNumber();
void ShowItem(struct BelAvia* showElem );
void FindAirType();
void FindPassengers();
void FindBusy();
void FindRoute();
void FindPoint();
void FindTime();
void FindDay();
void NearestFlight();
void FindFlight(char day[], int time, char str[], char point[]);
void BookTickets();
void ReturnTickets();
void FreePlace();
void PrintTicket();

int main()
{

	char str[1000];
	Begin = NULL;
	This = NULL;
	FILE *file;
	file = fopen("AirLines.txt", "r");
	while (fgets(str, 1000, file) != NULL)
	{
		Add(str);
	}
	fclose(file);
	int l=1;
	while (l != 0)
	{
		system("cls");
		ShowAll();
		printf("Select an action:\n");
		printf("1.Find\n");
		printf("2.Nearest flight\n");
		printf("3.Booking tickets\n");
		printf("4.Ticket return\n");
		printf("5.View Free place\n");
		printf("6.Print tickets\n");
		scanf("%d", &l);
		switch (l)
		{
		case 1:
			Find();
			break;
		case 2:
			NearestFlight();
			break;
		case 3:
			BookTickets();
			break;
		case 4:
			ReturnTickets();
			break;
		case 5:
			FreePlace();
			break;
		case 6:
			PrintTicket();
			break;
		default:
			printf("Wrong enter!\n");
			break;
		}
		printf("Enter 0, to exit\n");
		scanf("%d", &l);
	}
	file = fopen("AirLines.txt", "w");
	while (Begin != NULL)
	{
		char PutsLine[1000];
		int index = 0;
		PutsLine[index] = '"';
		index++;
		char It[100];
		sprintf(It, "%d", Begin->Number);
		int i = 0;
		while (It[i] != '\0')
		{
			PutsLine[index] = It[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '"';
		while (Begin->AircraftType.AirType[i] != '\0')
		{
			PutsLine[index] = Begin->AircraftType.AirType[i];
			i++;
			index++;
		}
		PutsLine[index++] = ' ';
		sprintf(It, "%d", Begin->AircraftType.NumberOfPassengers);
		i = 0;
		while (It[i] != '\0')
		{
			PutsLine[index] = It[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = ' ';
		sprintf(It, "%d", Begin->AircraftType.Busy);
		while (It[i] != '\0')
		{
			PutsLine[index] = It[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '"';
		while (Begin->Route[i] != '\0')
		{
			PutsLine[index] = Begin->Route[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '"';
		while (Begin->IntermediatePoint[i] != '\0')
		{
			PutsLine[index] = Begin->IntermediatePoint[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '"';
		sprintf(It, "%d", Begin->DepartureTime);
		while (It[i] != '\0')
		{
			PutsLine[index] = It[i];
			i++;
			index++;
		}
		i = 0;
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '"';
		for (int j = 0; j < 7; j++)
		{
			if (Begin->Day[j] == 1)
				switch (j)
				{
				case 0:
					PutsLine[index++] = 'm';
					PutsLine[index++] = 'o';
					PutsLine[index++] = 'n';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 1:
					PutsLine[index++] = 't';
					PutsLine[index++] = 'u';
					PutsLine[index++] = 'e';
					PutsLine[index++] = 's';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 2:
					PutsLine[index++] = 'w';
					PutsLine[index++] = 'e';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'n';
					PutsLine[index++] = 'e';
					PutsLine[index++] = 's';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 3:
					PutsLine[index++] = 't';
					PutsLine[index++] = 'h';
					PutsLine[index++] = 'u';
					PutsLine[index++] = 'r';
					PutsLine[index++] = 's';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 4:
					PutsLine[index++] = 'f';
					PutsLine[index++] = 'r';
					PutsLine[index++] = 'i';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 5:
					PutsLine[index++] = 's';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 't';
					PutsLine[index++] = 'u';
					PutsLine[index++] = 'r';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				case 6:
					PutsLine[index++] = 's';
					PutsLine[index++] = 'u';
					PutsLine[index++] = 'n';
					PutsLine[index++] = 'd';
					PutsLine[index++] = 'a';
					PutsLine[index++] = 'y';
					PutsLine[index++] = ' ';
					break;
				}
		}
		if (PutsLine[index - 1] = ' ')
		{
			index = index - 1;
		}
		PutsLine[index++] = '"';
		PutsLine[index++] = ' ';
		PutsLine[index++] = '\n';
		PutsLine[index++] = '\0';
		fputs(PutsLine, file);
		Begin=Begin->next;
	}
	fclose(file);
	return 0;
}

void ShowItem(struct BelAvia *showElem)
{
	This = showElem;
	int C = This->DepartureTime / 60;
	int O = This->DepartureTime % 60;
	fprintf(stdout, "Number: %d , Type %s , Passengers: %d , Busy Place: %d , Route: %s , Intermediate Point: %s , Depature Time: %d:%d , Flight Day: ", This->Number,
		This->AircraftType.AirType,
		This->AircraftType.NumberOfPassengers,
		This->AircraftType.Busy,
		This->Route, This->IntermediatePoint,
		C, O);
	for (int i = 0; i < 7; i++)
	{
		if (This->Day[i] == 1)
			switch (i)
			{
			case 0:
				printf("monday ");
				break;
			case 1:
				printf("tuesday ");
				break;
			case 2:
				printf("wednesday ");
				break;
			case 3:
				printf("thursday ");
				break;
			case 4:
				printf("friday ");
				break;
			case 5:
				printf("saturday ");
				break;
			case 6:
				printf("sunday");
				break;
			}
	}
	printf("\n");

}

void Add(char str[])
{
	struct BelAvia *AddFly = (struct BelAvia*)malloc(sizeof(struct BelAvia));
	This = AddFly;
	This->next = NULL;
	This->prev = NULL;
	Arr(This);
	if (Begin == NULL)
	{
		Begin = This;
	}
	else
	{
		AddFly = Begin;
		while (AddFly->next != NULL)
		{
			AddFly = AddFly->next;
		}
		AddFly->next = This;
		This->prev = AddFly;
	}
	int Pick=0,index=0;
	int quote = 0;
	char Mem[100];
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '"')
		{
			quote++;
			continue;
		}
		if (quote == 2)
		{
			Mem[index] = '\0';
			quote = 0;
			switch (Pick)
			{
			case 0:
				GetNumber(Mem);
				break;
			case 1:
				GetAirLine(Mem);
				break;
			case 2:
				GetRoute(Mem);
				break;
			case 3:
				GetPoint(Mem);
				break;
			case 4:
				GetTime(Mem);
				break;
			case 5:
				GetDay(Mem);
				break;
			default:
				break;
			}
			index = 0;
			Pick++;
		}
		if (quote == 1)
		{
			Mem[index] = str[i];
			index++;
		}
	}
}

void GetNumber(char str[])
{
	This->Number = atoi(str);
	return;
}

void GetAirLine(char str[])
{
	int i = 0;
	char temp[100];
	while (str[i] != ' ')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	strcpy(This->AircraftType.AirType, temp);
	i++;
	int k = 0;
	while (str[i] != ' ')
	{
		temp[k] = str[i];
		i++;
		k++;
	}
	temp[k] = '\0';
	This->AircraftType.NumberOfPassengers = atoi(temp);
	i++;
	k = 0;
	while (str[i] != '\0')
	{
		temp[k] = str[i];
		i++;
		k++;
	}
	temp[k] = '\0';
	This->AircraftType.Busy = atoi(temp);
	return;
}

void GetRoute(char str[])
{
	strcpy(This->Route, str);
}

void GetPoint(char str[])
{
	strcpy(This->IntermediatePoint, str);
}

void GetTime(char str[])
{
	This->DepartureTime = atoi(str);
}

void GetDay(char str[])
{
	char thisday[100];
	int index = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			thisday[index] = '\0';
			if (strcmp(thisday, "monday") == 0)
				This->Day[0] = 1;
			if (strcmp(thisday, "tuesday") == 0)
				This->Day[1] = 1;
			if (strcmp(thisday, "wednesday") == 0)
				This->Day[2] = 1;
			if (strcmp(thisday, "thursday") == 0)
				This->Day[3] = 1;
			if (strcmp(thisday, "friday") == 0)
				This->Day[4] = 1;
			if (strcmp(thisday, "saturday") == 0)
				This->Day[5] = 1;
			if (strcmp(thisday, "sunday") == 0)
				This->Day[6] = 1;
			index = 0;
		}
		else
		{
			thisday[index] = str[i];
			index++;
		}
	}
	thisday[index] = '\0';
	if (strcmp(thisday, "monday") == 0)
		This->Day[0] = 1;
	if (strcmp(thisday, "tuesday") == 0)
		This->Day[1] = 1;
	if (strcmp(thisday, "wednesday") == 0)
		This->Day[2] = 1;
	if (strcmp(thisday, "thursday") == 0)
		This->Day[3] = 1;
	if (strcmp(thisday, "friday") == 0)
		This->Day[4] = 1;
	if (strcmp(thisday, "saturday") == 0)
		This->Day[5] = 1;
	if (strcmp(thisday, "sunday") == 0)
		This->Day[6] = 1;
	index = 0;
}

void ShowAll()
{
	This = Begin;
	while (This != NULL)
	{
		int C = This->DepartureTime / 60;
		int O = This->DepartureTime % 60;
		fprintf(stdout, "Number: %d , Type %s , Passengers: %d , Busy Place: %d , Route: %s , Intermediate Point: %s , Depature Time: %d:%d , Flight Day: ", This->Number,
			This->AircraftType.AirType,
			This->AircraftType.NumberOfPassengers,
			This->AircraftType.Busy,
			This->Route, This->IntermediatePoint,
			C,O);
		for (int i = 0; i < 7; i++)
		{
			if (This->Day[i]==1)
				switch (i)
				{
				case 0:
					printf("monday ");
					break;
				case 1:
					printf("tuesday ");
					break;
				case 2:
					printf("wednesday ");
					break;
				case 3:
					printf("thursday ");
					break;
				case 4:
					printf("friday ");
					break;
				case 5:
					printf("saturday ");
					break;
				case 6:
					printf("sunday");
					break;
				}
		}
		printf("\n");
		This = This->next;
	}
}

void Find()
{
	printf("On which field to look for?\n");
	printf("1.Number\n");
	printf("2.Aircraft type\n");
	printf("3.Number of Passengers\n");
	printf("4.Busy number\n");
	printf("5.Route\n");
	printf("6.Intermediate Point\n");
	printf("7.Time\n");
	printf("8.Day\n");
	int w;
	scanf("%d", &w);
	switch (w)
	{
	case 1:
		FindNumber();
		break;
	case 2:
		FindAirType();
		break;
	case 3:
		FindPassengers();
		break;
	case 4:
		FindBusy();
		break;
	case 5:
		FindRoute();
		break;
	case 6:
		FindPoint();
		break;
	case 7:
		FindTime();
		break;
	case 8:
		FindDay();
		break;
	default:
		printf("Wrong enter!\n");
		break;
	}
}

void FindNumber()
{
	printf("Enter the Find Number\n");
	int find;
	scanf("%d", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (This->Number == find)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}	
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindAirType()
{
	printf("Enter the Find Aircraft type\n");
	getchar();
	char find[100];
	scanf("%s", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (strcmp(This->AircraftType.AirType, find)==0)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindPassengers()
{
	printf("Enter the Find Number of Passengers\n");
	int find;
	scanf("%d", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (This->AircraftType.NumberOfPassengers == find)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindBusy()
{
	printf("Enter the Find busy number\n");
	int find;
	scanf("%d", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (This->AircraftType.Busy == find)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindRoute()
{
	printf("Enter the Find Route\n");
	getchar();
	char find[100];
	scanf("%s", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (strcmp(This->Route, find) == 0)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindPoint()
{
	printf("Enter the Find Intermediate Point\n");
	getchar();
	char find[100];
	scanf("%s", &find);
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		char str[1000], findStr[1000];
		int index = 0;
		strcpy(str,This->IntermediatePoint);
		for (int i = 0; i < strlen(str); i++)
		{
			
			if (str[i] == ' ')
			{
				findStr[index] = '\0';
				if (strcmp(find, findStr) == 0)
				{
					k = 1;
					ShowItem(This);
				}
				index = 0;
			}
			else
			{
				findStr[index] = str[i];
				index++;
			}
			if (str[i + 1] == '\0')
			{
				findStr[index] = '\0';
				if (strcmp(find, findStr) == 0)
				{
					k = 1;
					ShowItem(This);
				}
				index = 0;
			}
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindTime()
{
	printf("Enter the Find time\n");
	char find[10],str[5];
	int index = 0;
	scanf("%s", &find);
	int C,O;
	for (int i = 0; i < strlen(find); i++)
	{
		if (find[i] == ':')
		{
			str[index] = '\0';
			index = 0;
			C = atoi(str);
		}
		else
		{
			str[index] = find[i];
			index++;
		}
	}
	str[index] = '\0';
	O = atoi(str);
	int findTime = 60 * C + O;
	This = Begin;
	int k = 0;
	while (This != NULL)
	{
		if (This->DepartureTime == findTime)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void FindDay()
{
	printf("Enter the Find day\n");
	getchar();
	char find[100];
	scanf("%s", &find);
	This = Begin;
	int d = -1;
	if (strcmp(find, "monday") == 0)
		d = 0;
	if (strcmp(find, "tuesday") == 0)
		d = 1;
	if (strcmp(find, "wednesday") == 0)
		d = 2;
	if (strcmp(find, "thursday") == 0)
		d = 3;
	if (strcmp(find, "friday") == 0)
		d = 4;
	if (strcmp(find, "saturday") == 0)
		d = 5;
	if (strcmp(find, "sunday") == 0)
		d = 6;
	int k = 0;
	while (This != NULL)
	{
		if (This->Day[d] == 1)
		{
			k = 1;
			ShowItem(This);
		}
		This = This->next;
	}
	if (k == 0)
	{
		printf("There's no such thing\n");
	}
}

void NearestFlight()
{
	printf("What day of the week is it?\n");
	char day[100];
	scanf("%s", &day);
	printf("What time is it now?\n");
	char find[10], str[5];
	int index = 0;
	scanf("%s", &find);
	int C, O;
	for (int i = 0; i < strlen(find); i++)
	{
		if (find[i] == ':')
		{
			str[index] = '\0';
			index = 0;
			C = atoi(str);
		}
		else
		{
			str[index] = find[i];
			index++;
		}
	}
	str[index] = '\0';
	O = atoi(str);
	int Time = 60 * C + O;
	printf("From where we fly out?\n");
	char Punkt[100];
	scanf("%s", &Punkt);
	printf("Where are we flying?\n");
	char point[100];
	scanf("%s", &point);
	FindFlight(day,Time,Punkt,point);
}

void FindFlight(char day[], int time, char str[], char point[])
{
	This = Begin;
	struct BelAvia* temp;
	temp = NULL;
	int d = -1;
	if (strcmp(day, "monday") == 0)
		d = 0;
	if (strcmp(day, "tuesday") == 0)
		d = 1;
	if (strcmp(day, "wednesday") == 0)
		d = 2;
	if (strcmp(day, "thursday") == 0)
		d = 3;
	if (strcmp(day, "friday") == 0)
		d = 4;
	if (strcmp(day, "saturday") == 0)
		d = 5;
	if (strcmp(day, "sunday") == 0)
		d = 6;
	int rez = d;
	int minTime = 100000;
	while (This != NULL)
	{
		char route[100];
		char mem[100];
		d = rez;
		int index = 0,w=1,ThisTime;
		bool dep, arriv;
		dep = arriv = false;
		strcpy(route, This->Route);
		for (int i = 0; i < strlen(route); i++)
		{
			if (route[i] == '-')
			{
				mem[index] = '\0';
				if (strcmp(str, mem) == 0)
				{
					dep = true;
				}
				index = 0;
			}
			else
			{
				mem[index] = route[i];
				index++;
			}
		}
		mem[index] = '\0';
		if (strcmp(point, mem) == 0)
		{
			arriv = true;
		}
		index = 0;
		if (dep == true)
		{
			if (arriv == true)
			{
				if (This->Day[d] == 1)
				{
					if (time < This->DepartureTime)
					{
						ThisTime = This->DepartureTime - time;
						if (minTime > ThisTime)
						{
							minTime = ThisTime;
							temp = This;
						}
					}
					else
					{
						int NumberDay = 0;
						while (This->Day[d] != 1)
						{
							d++;
							if (d == 7)
								d = 0;
							NumberDay++;
						}
						ThisTime = This->DepartureTime - time + NumberDay * 1440;
						if (ThisTime < minTime)
						{
							minTime = ThisTime;
							temp = This;
						}
					}
				}
				else
				{
					int NumberDay = 0;
					while (This->Day[d] != 1)
					{
						d++;
						if (d == 7)
							d = 0;
						NumberDay++;
					}
					ThisTime = This->DepartureTime - time + NumberDay * 1440;
					if (ThisTime < minTime)
					{
						minTime = ThisTime;
						temp = This;
					}
				}
			}
			else
			{
				char Points[1000];
				char findStr[1000];
				int k = 0;
				strcpy(Points, This->IntermediatePoint);
				for (int i = 0; i < strlen(Points); i++)
				{
					if (Points[i] == ' ')
					{
						findStr[index] = '\0';
						if (strcmp(point, findStr) == 0)
						{
							k = 1;
						}
						index = 0;
					}
					else
					{
						findStr[index] = Points[i];
						index++;
					}
					if (Points[i + 1] == '\0')
					{
						findStr[index] = '\0';
						if (strcmp(point, findStr) == 0)
						{
							k = 1;
						}
						index = 0;
					}
				}
				if (k == 1)
				{
					if (This->Day[d] == 1)
					{
						if (time < This->DepartureTime)
						{
							ThisTime = This->DepartureTime - time;
							if (minTime > ThisTime&&This->AircraftType.Busy != This->AircraftType.NumberOfPassengers)
							{
								minTime = ThisTime;
								temp = This;
							}
						}
						else
						{
							d++;
							if (d == 7)
								d = 0;
							int NumberDay = 1;
							while (This->Day[d] != 1)
							{
								d++;
								if (d == 7)
									d = 0;
								NumberDay++;
							}
							ThisTime = This->DepartureTime - time + NumberDay * 1440;
							if (ThisTime < minTime&&This->AircraftType.Busy != This->AircraftType.NumberOfPassengers)
							{
								minTime = ThisTime;
								temp = This;
							}
						}
					}
					else
					{
						int NumberDay = 0;
						while (This->Day[d] != 1)
						{
							d++;
							if (d == 7)
								d = 0;
							NumberDay++;
						}
						ThisTime = This->DepartureTime - time + NumberDay * 1440;
						if (ThisTime < minTime&&This->AircraftType.Busy!=This->AircraftType.NumberOfPassengers)
						{
							minTime = ThisTime;
							temp = This;
						}
					}
				}
			}
		}
		This = This->next;
	}
	if (temp != NULL)
		ShowItem(temp);
	else
		printf("There is no such route\n");
}

void BookTickets()
{
	printf("Enter the flight number\n");
	int FlightNumber;
	scanf("%d", &FlightNumber);
	This = Begin;
	while (This!=NULL)
	{
		if (This->Number == FlightNumber)
		{
			if (This->AircraftType.Busy == This->AircraftType.NumberOfPassengers)
			{
				printf("Sorry, no vacancy\n");
			}
			else
			{
				This->AircraftType.Busy++;
				printf("Place successfully booked!\n");
			}
		}
		This = This->next;
		
	}
}

void ReturnTickets()
{
	printf("Enter the flight number\n");
	int FlightNumber;
	scanf("%d", &FlightNumber);
	This = Begin;
	while (This != NULL)
	{
		if (This->Number == FlightNumber)
		{
			if (This->AircraftType.Busy == 0)
			{
				printf("Sorry, all places are already empty\n");
			}
			else
			{
				This->AircraftType.Busy--;
				printf("Place successfully freed!\n");
			}
		}
		This = This->next;
	}
}

void FreePlace()
{
	This = Begin;
	while (This != NULL)
	{
		int fr = This->AircraftType.NumberOfPassengers - This->AircraftType.Busy;
		printf("Number %d , Route %s , Free Place %d\n", This->Number, This->Route, fr);
		This = This->next;
	}
}

void PrintTicket()
{
	printf("Enter the flight number\n");
	int num;
	scanf("%d", &num);
	This = Begin;
	int k;
	while (This != NULL)
	{
		k = 1;
		if (This->Number == num)
			break;
		k = 0;
		This = This->next;
	}
	int C = This->DepartureTime / 60;
	int O = This->DepartureTime % 60;
	printf("_________________________________________________________________________________________________________\n");
	printf("    Number of Flight %d                                             Time %d:%d                       \n", This->Number,C,O);
	printf("                                                                                                        \n");
	printf("      Route: %s                                                                               \n",This->Route);
	printf("                                             monday tuesday wednesday thursday friday saturday sunday   \n");
	printf("                      Day:                    %d       %d        %d         %d       %d      %d       %d         \n",This->Day[0], This->Day[1], This->Day[2], This->Day[3], This->Day[4], This->Day[5], This->Day[6]);
	printf("   Intermediate Point: %s                                                                                                     \n",This->IntermediatePoint);
	printf("________________________________________________________________________________________________________\n");
}