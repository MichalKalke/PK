/**@file */
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef animal_H
#define animal_H

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

#endif // !animal_H
