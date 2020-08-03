/**@file */
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef struct_H
#define struct_H

/**Przechowuje informacje o gatunku, nazwie zwierzecia, trzech zagadkach oraz wskaznik na nastepny element
*/
typedef struct GameAnimal
{
	char* specie; ///< Informacja o gatunku
	char* animal; ///< Informacja o nazwie zwierzecia
	char* clueOne; ///< Pierwsza zagadka
	char* clueTwo; ///< Druga zagadka
	char* clueThree; ///< Trzecia zagadka
	struct GameAnimal* next; ///< Wskaznik na nastepny element
}GameAnimal_type;

/**Przechowuje punkty oraz nazwe uzytkownika i wskaznik na nastepny element
*/
typedef struct Score
{
	char* name; ///< Nazwa uzytkownika
	int score; ///< Ilosc punktow zdobytych przez uzytkownika
	struct Score* next; ///< Wskaznik na nastepny element
}Score_type;

#endif // !animal_H
