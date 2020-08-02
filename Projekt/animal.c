#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "animal.h"
#include "rank.h"

void DrawFromList(GameAnimal_type* head, int* p) {
	if (head == NULL)
		return;
	srand(time(NULL));
	char* result = head;
	GameAnimal_type* actual = head;
	int n;
	for (n = 2; actual != NULL; n++) {
		if (rand() % n == 0)
			result = actual;
		actual = actual->next;
	}
	*p = result;
}

void playGame(Score_type** head2, GameAnimal_type* p) {
	int scoreGame = 0;
	char shot[15];
	int cmp;
	char* instruction = "Wpisz zwierze, ale bez polskich znakow\n";
	printf("%s", instruction);
	printf("Gatunek: %s\n", p->specie);
	printf("%s\n jest to:", p->clueOne);
	//printf("%s\n", p->animal);
	scanf_s("%14s", shot, (unsigned)_countof(shot));
	cmp = strcmp(shot, p->animal);
	if (cmp == 0) {
		scoreGame = scoreGame + 100;
	}
	else {
		printf("%s\n jest to: ", p->clueTwo);
		scanf_s("%14s", shot, (unsigned)_countof(shot));
		cmp = strcmp(shot, p->animal);
		while ((getchar()) != '\n');
		if (cmp == 0)
		{
			scoreGame = scoreGame + 50;
		}
		else
		{
			printf("%s\n jest to: ", p->clueThree);
			scanf_s("%14s", shot, (unsigned)_countof(shot));
			cmp = strcmp(shot, p->animal);
			while ((getchar()) != '\n');
			if (cmp == 0)
			{
				scoreGame = scoreGame + 10;
			}
			else
				printf("Niestety nie, to jest %s\n", p->animal);
		}
	}
	AddToScore(head2, scoreGame);
}

void addToFile() {
	FILE* file;
	char s[100], a[100], cO[100], cT[100], cTh[100];
	char array[100] = "\n";
	char hash[10] = "#";
	printf("Podaj gatunek: ");
	gets_s(s, 100);
	strcat_s(array, 100, s);
	strcat_s(array, 100, hash);
	printf("Podaj nazwe zwierzecia: ");
	gets_s(a, 100);
	strcat_s(array, 100, a);
	strcat_s(array, 100, hash);
	printf("Podaj pierwsza wskazowke: ");
	gets_s(cO, 100);
	strcat_s(array, 100, cO);
	strcat_s(array, 100, hash);
	printf("Podaj druga wskazowke: ");
	gets_s(cT, 100);
	strcat_s(array, 100, cT);
	strcat_s(array, 100, hash);
	printf("Podaj trzecia wskazowke: ");
	gets_s(cTh, 100);
	strcat_s(array, 100, cTh);
	strcat_s(array, 100, hash);
	printf("%s", array);
	fopen_s(&file, "test.txt", "a");
	fprintf_s(file, "%s", array);
	fclose(file);
}

void toTheList(GameAnimal_type** head, char* sp, char* ani, char* cOne, char* cTwo, char* cThree) {
	if ((*head) == NULL) {
		*head = (GameAnimal_type*)malloc(sizeof(GameAnimal_type));
		(*head)->specie = sp;
		(*head)->animal = ani;
		(*head)->clueOne = cOne;
		(*head)->clueTwo = cTwo;
		(*head)->clueThree = cThree;
		(*head)->next = NULL;
	}
	else
	{
		GameAnimal_type* current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = (GameAnimal_type*)malloc(sizeof(GameAnimal_type));
		current->next->specie = sp;
		current->next->animal = ani;
		current->next->clueOne = cOne;
		current->next->clueTwo = cTwo;
		current->next->clueThree = cThree;
		current->next->next = NULL;
	}
}

void openFile(char* bufor, GameAnimal_type** head) {
	FILE* file;
	char* sp = " ";
	char* ani = " ";
	char* cOne = " ";
	char* cTwo = " ";
	char* cThree = " ";
	char corector[] = "#";
	if (fopen_s(&file, "test.txt", "r") == 0) {
		while (fgets(bufor, 1024, file) != NULL) {
			sp = strtok_s(NULL, corector, &bufor);
			ani = strtok_s(NULL, corector, &bufor);
			cOne = strtok_s(NULL, corector, &bufor);
			cTwo = strtok_s(NULL, corector, &bufor);
			cThree = strtok_s(NULL, corector, &bufor);
			toTheList(head, sp, ani, cOne, cTwo, cThree);
		}
	}
	fclose(file);
}

deleteAnimal(GameAnimal_type** head) {
	GameAnimal_type* current = *head;
	GameAnimal_type* nextCurrent;
	while (current != NULL)
	{
		nextCurrent = current->next;
		free(current);
		current = nextCurrent;
	}
	*head = NULL;
}

void playTheGame() {
	char* p;
	char bufor[1024];
	int choice, menu;
	GameAnimal_type* head;
	head = (GameAnimal_type*)malloc(sizeof(GameAnimal_type));
	head = NULL;
	Score_type* head2;
	head2 = (Score_type*)malloc(sizeof(Score_type));
	head2 = NULL;
	printf("Witaj w grze Zgadnij jakie to zwierze!\n Wybierz co chcesz zrobic\n 1 zagraj\n 2 Dodaj nowe zwierze\n 3 Wyswietl tablice wynikow\n Inne zakoncz program\n:");
	scanf_s("%d", &menu);
	while ((getchar()) != '\n');
	switch (menu)
	{
	case 1:
		openFile(bufor, &head);
		printf("Podaj swoj nick:\n");
		GimmeYourNick(&head2);
		for (int i = 0; i < 3; ++i) {
			DrawFromList(head, &p);
			playGame(&head2, p);
		}
		printf("Wynik gracza %s to %d \n Czy chcesz zapisac wynik? \n 1. Tak 2. Nie \n", head2->name, head2->score);
		scanf_s("%d", &choice);
		if (choice == 1) {
			deleteAnimal(&head);
			nickToFile(&head2);
		}
		else {
			deleteGamer(&head2);
			deleteAnimal(&head);
		}
		break;
	case 2:
		addToFile();
		deleteAnimal(&head);
		break;
	case 3:
		leaderFromFile(bufor, &head2);
		sortRank(&head2);
		showLeader(head2);
		break;
	default:
		break;
	}
}