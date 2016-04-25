%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"

extern FILE* yyin;

%}

%union{
	char* chaine;
	int valEntiere;
}

%token FIN
%token FINFINALE
%token PREMISSE
%token CONCLUSION
%token ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token AFFECTATION
%token AFF SEQ
%token INF_EGAL SUP_EGAL SUP INF EGAL
%token PLUS MOINS FOIS
%token ET
%token<chaine> MOT
%token<chaine> ENTIER

%type<chaine> Expression
%type<chaine> Regle
%type<chaine> Predicat
%type<chaine> Programme
%type<chaine> Conditions
%type<chaine> Condition
%type<chaine> Comparaison
%type<chaine> Valeur

%start Entree

%%

Entree:
	/* Vide */
	| Regle FIN Entree
	| FINFINALE { return 0; }
	| Comparaison FIN Entree
	;
	
Regle:
	AFF CONCLUSION Predicat Programme Predicat PREMISSE Regle
		{
			printf("1- Erreur : prémisse présente dans la règle AFF\n%s\n", $$);
		}
	| AFF CONCLUSION Predicat Programme Predicat
		{
			// remplacer les prédicats selon la règle
		}
	| AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			if(strcmp($5, $8) != 0)
				printf("3- Erreur : prédicats de la règle AFF pas égaux\n%s\n", $$);
		}
	| SEQ CONCLUSION Predicat Programme Predicat PREMISSE AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			strcat($10, ";");
			strcat($10, $15);
			if(strcmp($10, $4) != 0)
				printf("4- Erreur : programmes de la règle SEQ incorrects\n%s\n", $$);
		}
	;
	
Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			printf("Prédicat de valeur |%s|\n", $2);
			$$ = $2;
		}
	;
	
Conditions:
	Condition ET Conditions
		{
			$$ = $1;
		}
	| Condition
		{
			$$ = $1;
		}
	;
	
Condition:
	Comparaison
		{
			$$ = $1;
		}
	;
	
Comparaison:
	Expression INF Expression
		{
			strcat($1,"<");
			strcat($1, $3);
			$$=$1;
		}
	| Expression SUP Expression
		{ 
			strcat($1,">");
			strcat($1, $3);
			$$=$1;
		}
	| Expression INF_EGAL Expression
		{ 
			strcat($1,"<=");
			strcat($1, $3);
			$$=$1;
		}
	| Expression SUP_EGAL Expression
		{ 
			strcat($1,">=");
			strcat($1, $3);
			$$=$1;
		}
	| Expression EGAL Expression
		{
			strcat($1,"=");
			strcat($1, $3);
			$$=$1;
		}
	;
	
Valeur:
	MOT
		{
			$$ = 0;
			// TODO a faire plus tard, en aout
		}
	| ENTIER
		{
			$$ = $1;
		}
	;
	
Programme:
	MOT AFFECTATION Expression
		{
			// TODO Faire affectation de MOT
			printf("Affectation de %s avec valeur : %s\n", $1, $3);
		}
	| MOT AFFECTATION MOT
		{
			printf("Affectation de %s avec variable : %s\n", $1, $3 )
		}
	;
	
Expression:
	Valeur PLUS Expression
		{ 
			// $$ = $1 + $3;
			strcat($1, " + ");
			strcat($1, $3);
			$$ = $1;
			printf("Valeur de l'expression %s\n", $$);
			
		}
	| Valeur MOINS Expression
		{ 
			// $$ = $1 - $3;
			strcat($1, " - ");
			strcat($1, $3);
			$$ = $1;
			printf("Valeur de l'expression %s\n", $$);
		}
	| Valeur FOIS Expression
		{ 
			// $$ = $1 - $3;
			strcat($1, " * ");
			strcat($1, $3);
			$$ = $1;
			printf("Valeur de l'expression %s\n", $$);
		}
	| Valeur 
		{
			$$ = $1;
			printf("Valeur : %s\n", $$);
		}
	;
	
%%

int yyerror(char *s) {
  printf("%s\n",s);
}

int main(int argc, char **argv) {
	if (argc == 2){
		yyin= fopen(argv[1], "r");
		printf("Fichier utilisé\n");
	}
	yyparse();
	//yylex();

	/*if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;*/
	
	return EXIT_SUCCESS;
}
