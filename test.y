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
}

%token AFFECTATION
%token PREMISSE
%token CONSEQUENCE
%token ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token AFF
%token SEQ
%token FINFINALE
%token INF_EGAL SUP_EGAL SUP INF
%token<chaine> MOT
%token<valEntiere> ENTIER
%token FIN

%type<chaine> Expression
%type<chaine> Regle
%type<chaine> Predicat
%type<chaine> Condition

%start Entree

%%

Entree:
	/* Vide */
	| Regle FIN Entree
	| FINFINALE { return 0; }
	;
	
Regle:
	AFF PREMISSE Regle CONSEQUENCE Predicat Programme Predicat
		{
			//$$ = $5;
			printf("la preuve est fausse (premisse présente) : %s\n", $$);
		}
	| AFF CONSEQUENCE Predicat Programme Predicat
		{
			// Calcul à faire
			printf("bravo");
		}
	;

Predicat:
	ACCOLADE_OUVRANTE Condition ACCOLADE_FERMANTE
		{
			printf("Prédicat de valeur %s\n", $2);
			$$= $2;
		}
	;
	
Condition:
	Valeur
	;

Valeur:	
	MOT
	| ENTIER
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

	/*
	| REGLE Expression { 	
		printf("Val longue Expression : %s\n", $$);
	 }*/
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
