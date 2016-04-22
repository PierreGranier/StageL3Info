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

%type<chaine> Expression
%type<chaine> Regle
%type<chaine> Predicat
%type<chaine> Condition

%start Entree

%%

Entree:
	/* Vide */
	| Regle Entree
	| FINFINALE { return 0; }
	;
	
Regle:
	AFF PREMISSE Regle CONSEQUENCE Predicat Programme Predicat
		{
			//$$ = $5;
			printf("la preuve est fausse (premisse présente) : %s\n", $$);
		}
	| AFF PREMISSE CONSEQUENCE Predicat Programme Predicat
		{
			// Calcul à faire
			printf("bravo");
		}
	;

Predicat:
	ACCOLADE_OUVRANTE Condition ACCOLADE_FERMANTE
	;
	
Condition:
	MOT INF MOT
		{ 
			strcat($$, $1);
			strcat($$,"<");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| MOT SUP MOT
		{ 
			strcat($$, $1);
			strcat($$,">");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| MOT SUP_EGAL MOT
		{ 
			strcat($$, $1);
			strcat($$,">=");
			strcat($$, $3);
			printf("predicat -%s-", $$);
		}
	| MOT INF_EGAL MOT
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
		printf("Fichier utilisé");
	}
	yyparse();
	//yylex();

	/*if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;*/
	
	return EXIT_SUCCESS;
}
