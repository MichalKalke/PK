/** @file */
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef rank_H
#define rank_H

/**Dodaje punkty zdobyte przez uzytkownika podczas rozgrywki
@param head2 Wskaznik na pierwszy element listy
@param scoreGame Zawiera punkty zdobyte przez uzytkownika
*/
void AddToScore(Score_type** head2, int scoreGame);

/**Zapisuje do pliku tekstowego nazwe oraz ilosc punktow uzytkownika
@param head2 Wskaznik na pierwszy element listy
*/
void nickToFile(Score_type** head2);

/**Funkcja do dealokacji pamieci w liscie
@param head2 Wskaznik na pierwszy element listy
*/
void deleteGamer(Score_type** head2);

/**Dodaje do listy jednokierunkowej nazwe oraz punkty uzytkownika
@param head2 Wskaznik na poczatek listy
@param nick Zawiera nazwe podana przez uzytkownika
@param score Zawiera punkty jakie zdobyl uzytkownik
*/
void addToLeader(Score_type** head2, char* nick, int score);

/**Sortuje liste jednokierunkowa malejaco
@param head2 Wskaznik na pierwszy element listy
*/
void sortRank(Score_type** head2);

/**Pobiera z pliku tekstowego nazwy i punkty uzytkownikow
@param bufor Tablica do zapisu
@param head2 Wskaznik na pierwszy element listy
*/
void leaderFromFile(char* bufor, Score_type** head2);

/**Wypisuje w kolejnosci malejacej uzytkownika wraz z punktami przez niego zdobytymi
@param head2 Poczatek listy
*/
void showLeader(Score_type* head2);
#endif // !rank_H

