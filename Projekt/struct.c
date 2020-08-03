#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "animal.h"
#include "rank.h"

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