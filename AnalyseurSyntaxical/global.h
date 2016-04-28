#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef struct s_entier {
	string chaine;
	int valeur;
} t_entier;

typedef struct s_instruction {
	string variable;
	string valeur;
} t_instruction;

typedef struct s_programme {
	string contenu;
	t_instruction instruction;
} t_programme;

typedef struct s_triplet {
	string precondition;
	t_programme programme;
	string postcondition;
} t_triplet;

typedef char boolean;

typedef struct s_typespe {
	string chaine;
	t_entier entier;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;
	boolean valBool;
} typespe;

#define YYSTYPE typespe
extern YYSTYPE yylval;