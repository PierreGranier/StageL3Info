%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"
#define false	0 	
#define true 	1
typedef char boolean;

extern FILE* yyin;

%}

%union{
	char* chaine;
	int valEntiere;
	boolean valBool;
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

%type<chaine> ExpressionMot
%type<valEntiere> ExpressionEntier
%type<chaine> Regle
%type<valBool> Predicat
%type<chaine> Programme
%type<valBool> Conditions
%type<valBool> Condition
%type<valBool> Comparaison

%start Entree

%%

Entree:
	/* Vide */
	| FIN { printf("Fin du programme"); return 0; }
	| Regle FIN Entree
	| FINFINALE { printf("Fin du programme"); return 0; }
	| Comparaison FIN Entree
	| ExpressionMot FIN Entree
	| ExpressionEntier FIN Entree
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
			if($5 != $8)
				printf("3- Erreur : prédicats de la règle AFF pas égaux\n%s\n", $$);
		}
	| SEQ CONCLUSION Predicat Programme Predicat PREMISSE AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			strcat($10, ";");
			strcat($10, $15);
			if($10 != $4)
				printf("4- Erreur : programmes de la règle SEQ incorrects\n%s\n", $$);
		}
	;
	
Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
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
	ExpressionEntier INF ExpressionEntier
		{
			if($1 >= $3) {
				$$ = false;
				printf("Erreur : comparaison INF non logique : %d < %d\n", $1, $3);
			}
			else $$ = true;
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			if($1 <= $3) {
				$$ = false;
				printf("Erreur : comparaison SUP non logique : %d > %d\n", $1, $3);
			}
			else $$ = true;
			
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			if($1 > $3) {
				$$= 0;
				$$ = false;
				printf("Erreur : comparaison INF_EGAL non logique : %d <= %d\n", $1, $3);
			}
			else $$ = true;
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			if($1 < $3) {
				$$ = false;
				printf("Erreur : comparaison SUP_EGAL non logique : %d >= %d\n", $1, $3);
			}
			else $$ = true;
		}
	| ExpressionMot		INF			ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		SUP			ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		INF_EGAL	ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		SUP_EGAL	ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		INF			ExpressionEntier	{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		SUP			ExpressionEntier	{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		INF_EGAL	ExpressionEntier	{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionMot		SUP_EGAL	ExpressionEntier	{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionEntier	INF			ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionEntier	SUP			ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ printf("peut pas comparer des MOTS\n"); }
	;
	
Programme:
	MOT AFFECTATION ExpressionEntier
		{
			// TODO Faire affectation de MOT
		}
	;
	
ExpressionMot:
	MOT PLUS ExpressionMot
		{
			$$ = $1;
			strcat($$, " + ");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT MOINS ExpressionMot
		{
			$$ = $1;
			strcat($$, " - ");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT FOIS ExpressionMot
		{
			$$ = $1;
			strcat($$, " * ");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT
		{
			$$ = $1;
		}
	;
	
ExpressionEntier:
	ENTIER PLUS ExpressionEntier
		{
			$$ = atoi($1) + $3;
		}
	| ENTIER MOINS ExpressionEntier
		{
			$$ = atoi($1) - $3;
		}
	| ENTIER FOIS ExpressionEntier
		{
			$$ = atoi($1) * $3;
		}
	| ENTIER
		{
			$$ = atoi($1);
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
