#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct s_expression {
	string chaine;
	int valeur;
} t_expression;

typedef struct s_proposition {
	string affirmation;
	string negation;
} t_proposition;

typedef struct s_instruction {
	string variable;
	string valeur;
} t_instruction;

typedef struct s_programme {
	string contenu;
	// Pour les programmes contenant des instructions
	t_instruction instruction;
	// Pour les programmes si alors sinon
	t_proposition si;
	string alors;
	string sinon;
	// Pour les programmes tant que faire
	t_proposition tantque;
	string faire;
} t_programme;

typedef struct s_triplet {
	t_proposition precondition;
	t_programme programme;
	t_proposition postcondition;
} t_triplet;

typedef struct s_typespe {
	string chaine;
	t_expression expression;
	t_proposition proposition;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;
} typespe;

#define YYSTYPE typespe
extern YYSTYPE yylval;
