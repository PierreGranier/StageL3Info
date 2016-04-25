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
%token INF_EGAL SUP_EGAL SUP INF
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
	;
	
Regle:
	AFF CONCLUSION Predicat Programme Predicat PREMISSE Regle
		{
			printf("Erreur : prémisse présente dans la règle AFF\n%s\n", $$);
		}
	| AFF CONCLUSION Predicat Programme Predicat
		{
			// remplacer les prédicats selon la règle
		}
	| AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			if(strcmp($5, $8) != 0)
				printf("Erreur : prédicats de la règle AFF pas égaux\n%s\n", $$);
		}
	| SEQ CONCLUSION Predicat Programme Predicat PREMISSE AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			strcat($10, ";");
			strcat($10, $15);
			if(strcmp($10, $4) != 0)
				printf("Erreur : programmes de la règle SEQ incorrects\n%s\n", $$);
		}
	;
	
Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			printf("Prédicat de valeur %s\n", $2);
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
	Valeur INF Valeur
		{ 
			strcat($$, $1);
			strcat($$,"<");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| Valeur SUP Valeur
		{ 
			strcat($$, $1);
			strcat($$,">");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| Valeur SUP_EGAL Valeur
		{ 
			strcat($$, $1);
			strcat($$,">=");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| Valeur INF_EGAL Valeur
		{ 
			strcat($$, $1);
			strcat($$,"<=");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	;
	
Valeur:
	MOT
		{
			$$ = $1;
		}
	| ENTIER
		{
			$$ = $1;
		}
	;
	
Programme:
	Expression AFFECTATION Expression
	;
	
Expression:
	 { printf("%s", $$); }
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
