#pragma once
/** @file */
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef animal_H
#define animal_H

/**Funkcja sluzaca do losowania z listy zwierzecia do odgadniecia
@param head Poczatek listy 
@param p Wskaznik na wylosowany element
*/
void DrawFromList(GameAnimal_type* head, int* p);

/**Glowna czesc programu sluzaca do obslugi gry 
@param head2 Wskaznik na poczatek listy zwiazanej z nazwa i liczba punktow uzytkownika
@param p Poczatek listy
*/
void playGame(Score_type** head2, GameAnimal_type* p);

/**Dodaje do pliku tekstowego zwierze wraz z zagadkami podanymi przez uzytkownika
*/
void addToFile();

/**Dodaje dane pobrane wczesniej z pliku tekstowego do listy jednokierunkowej
@param head Wskaznik na poczatek listy
@param sp Zawiera informacje o gatunku
@param ani Zawiera informacje o nazwie zwierzecia
@param cOne Zawiera informacje o pierwszej zagadce
@param cTwo Zawiera informacje o drugiej zagadce
@param cThree Zawiera informacje o trzeciej zagadce
*/
void toTheList(GameAnimal_type** head, char* sp, char* ani, char* cOne, char* cTwo, char* cThree);

/**Obsluguje plik tekstowy ze zwierzetami i zagadkami
@param bufor Tablica do zapisu
@param head Wskaznik na pierwszy element listy
*/
void openFile(char* bufor, GameAnimal_type** head);

/**Funkcja dealokuje pamiec w liscie
@param head Wskaznik na pierwszy element listy
*/
deleteAnimal(GameAnimal_type** head);

/**Sluzy do obslugi wyboru uzytkownika czy chce zapisac swoj wynik do pliku czy tez nie
@param head Wskaznik na poczatek listy
@param head2 Wskaznik na poczatek listy
*/
void yourChoice(GameAnimal_type** head, Score_type** head2);

/**Glowna czesc obslugujaca menu wraz z akcjami z nim zwiazanymi
*/
void playTheGame();
#endif // !animal_H
