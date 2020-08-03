#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "animal.h"
#include "rank.h"

void AddToScore(Score_type** head2, int scoreGame) {
	(*head2)->score += scoreGame;
}

void GimmeYourNick(Score_type** head2) {
	char* nick;
	nick = (char*)malloc(sizeof(char*));
	scanf_s("%s", nick, (unsigned)_countof(nick));
	if ((*head2) == NULL) {
		*head2 = (Score_type*)malloc(sizeof(Score_type));
		(*head2)->name = nick;
		(*head2)->score = 0;
	}
}

void nickToFile(Score_type** head2) {
	FILE* file2;
	char array2[100] = "\n";
	char hash[10] = "#";
	strcat_s(array2, 100, (*head2)->name);
	strcat_s(array2, 100, hash);
	fopen_s(&file2, "leaders.txt", "a");
	fprintf_s(file2, "%s", array2);
	fprintf_s(file2, "%d", (*head2)->score);
	fprintf_s(file2, "%s", hash);
	fclose(file2);
}

void deleteGamer(Score_type** head2) {
	Score_type* current = *head2;
	Score_type* nextCurrent;
	while (current != NULL) {
		nextCurrent = current->next;
		free(current);
		current = nextCurrent;
	}
	*head2 = NULL;
}


void addToLeader(Score_type** head2, char* nick, int score) {
	if ((*head2) == NULL) {
		*head2 = (Score_type*)malloc(sizeof(Score_type));
		(*head2)->name = nick;
		(*head2)->score = score;
		(*head2)->next = NULL;
	}
	else {
		Score_type* current = *head2;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = (Score_type*)malloc(sizeof(Score_type));
		current->next->name = nick;
		current->next->score = score;
		current->next->next = NULL;
	}
}

void sortRank(Score_type** head2) {
	if ((*head2) == NULL || ((*head2)->next) == NULL) {
		return;
	}
	Score_type* nextCurrent = (*head2)->next;
	while (nextCurrent != NULL) {
		int tmp = nextCurrent->score;
		char* nick = nextCurrent->name;
		int found = 0;
		Score_type* current = *head2;
		while (current != nextCurrent) {
			if (current->score < nextCurrent->score && found == 0) {
				tmp = current->score;
				nick = current->name;
				current->score = nextCurrent->score;
				current->name = nextCurrent->name;
				found = 1;
				current = current->next;
			}
			else {
				if (found == 1) {
					int tmp2 = tmp;
					char* nick2 = nick;
					tmp = current->score;
					nick = current->name;
					current->score = tmp2;
					current->name = nick2;
				}
				current = current->next;
			}
		}
		current->score = tmp;
		nextCurrent = nextCurrent->next;
	}
}

void leaderFromFile(char* bufor, Score_type** head2) {
	FILE* file2;
	char* nick = " ";
	char* score2 = " ";
	int score = NULL;
	char corector[] = "#";
	if (fopen_s(&file2, "leaders.txt", "r") == 0) {
		while (fgets(bufor, 1024, file2) != NULL) {
			nick = strtok_s(NULL, corector, &bufor);
			score2 = strtok_s(NULL, corector, &bufor);
			score = strtod(score2, NULL);
			addToLeader(head2, nick, score);
		}
	}
}

void showLeader(Score_type* head2) {
	Score_type* temp = head2;
	printf("\n");
	if (head2 == NULL) {
		printf("lista jest pusta!\n");
		return;
	}
	while (temp != NULL) {
		printf("Gracz %s zdobyl %d", temp->name, temp->score);
		temp = temp->next;
		printf("\n");
	}
}
