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
%token PRECONDITION
%token POSTCONDITION
%token PREMISSE
%token CONSEQUENCE
%token PROGRAMME
%token AFF
%token SEQ
%token FINFINALE
%token INF_EGAL SUP_EGAL SUP INF
%token MOT

%type<chaine> Expression
%type<chaine> Regle
%type<chaine> Predicat

%start Entree

%%

Entree:
	/* Vide */
	| Entree Regle
	| FINFINALE { return 0; }
	;

Expression:
	Expression { printf("%s", $$); }
	;
	
Predicat:
	Predicat { printf("predicat %s", $$); }
	;
	
Calcul:
	Expression AFFECTATION Expression
	;
	
Regle:
	AFF PREMISSE CONSEQUENCE PRECONDITION Predicat PROGRAMME Calcul POSTCONDITION Predicat
			{
				$$ = $5;
				printf("dubzam : %s\n", $$);
			}
	;
  
Op_comparaison:
	INF_EGAL
	| SUP_EGAL
	| SUP 
	| INF
	;		
  
Predicat:
	MOT SUP_EGAL MOT 		{}
	| MOT INF_EGAL MOT		{}
	| MOT SUP MOT 			{}
	| MOT INF MOT 			{}
	;
	/*
	| REGLE Expression { 	
		printf("Val longue Expression : %s\n", $$);
	 }*/
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



// AFF PREMISSE CONSEQUENCE PRECONDITION azad PROGRAMME a := 1 POSTCONDITION gtrg


