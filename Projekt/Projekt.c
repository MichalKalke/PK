#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct GameAnimal
{
	char* specie;
	char* animal;
	char* clueOne;
	char* clueTwo;
	char* clueThree;
	struct GameAnimal* next;
}GameAnimal_type;

typedef struct Score
{
	char* name;
	int score;
	struct Score* next;
}Score_type;

void DrawFromList(GameAnimal_type** head) { //nie dzia³a tak jak ma dzia³ac
	if (head == NULL)
		return;
	srand(time(NULL));
	GameAnimal_type *result = (GameAnimal_type*)malloc(sizeof(GameAnimal_type)); //dodane
	GameAnimal_type *actual = (GameAnimal_type*)malloc(sizeof(GameAnimal_type)); //dodane
	int n;
	for (n = 2; actual != NULL; n++) {
		if (rand() % n == 0)
			result = actual->animal;
		actual = actual->next;
	}
	printf("%s\n", result);
}

void toTheList(GameAnimal_type** head, char* sp, char* ani, char* cOne, char* cTwo, char* cThree) {
	GameAnimal_type* current;
	current = (GameAnimal_type*)malloc(sizeof(GameAnimal_type));
	current->specie = sp;
	current->animal = ani;
	current->clueOne = cOne;
	current->clueTwo = cTwo;
	current->clueThree = cThree;
	current->next = (*head);
	*head = current;
	/*printf("%s\n", current->specie);
	printf("%s\n", current->animal);
	printf("%s\n", current->clueOne);
	printf("%s\n", current->clueTwo);
	printf("%s\n", current->clueThree);*/
}

void openFile(char* bufor) {
	GameAnimal_type* head;
	head = (GameAnimal_type*)malloc(sizeof(GameAnimal_type));
	head = NULL;
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
			toTheList(&head, sp, ani, cOne, cTwo, cThree);
			/*printf("%s\n", sp);
			printf("%s\n", ani);
			printf("%s\n", cOne);
			printf("%s\n", cTwo);
			printf("%s\n", cThree);*/
		}
	}
	fclose(file);
}

void Menu() {
	int menu;
	printf("Witaj w grze Zgadnij jakie to zwierze!\n");
	printf("Wybierz co chcesz zrobic\n 1 zagraj\n 2 Dodaj nowe zwierze\n 3 Wyswietl tablice wynikow\n Inne zakoncz program\n: ");
	scanf_s("%d", &menu);
	GameAnimal_type* head = NULL; //dodane
	char bufor[1024];
	switch (menu)
	{
	case 1: printf("siema1, wpisuj bez polskich znakow\n");
		openFile(bufor);
		DrawFromList(&head); //dodane
		break;
	case 2: printf("siema2");
		break;
	case 3: printf("siema3");
		break;
	default:
		break;
	}
}

int main()
{
	Menu();
}