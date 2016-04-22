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

%token<chaine> REGLE
%token<chaine> PRECONDITION
%token FINFINALE

%type<chaine> Expression

%start Entree

%%

Entree:
    /* Vide */
  | Entree Expression
  | Precondition dskfnbhior Postcondition
  | FINFINALE { return 0;}
  ;
  
  
Op_comparaison:
	INF_EGAL
	| SUP_EGAL
	;		
  
Precondition:
	MOT SUP_EGAL MOT 		{}
	| MOT INF_EGAL MOT	{}
	;
  
Expression:
	REGLE	{ 
				$$ = $1;
				printf("Val Expression : %s\n", $$);
			}
	/*
	| REGLE Expression { 	
		printf("Val longue Expression : %s\n", $$);
	 }*/
	|PRECONDITION {
				$$ = $1;
				printf("Val Expression : %s\n", $$);
			}	
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

