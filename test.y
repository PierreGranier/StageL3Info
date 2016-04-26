%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"
#define false	0
#define true 	1
typedef char boolean;

boolean compare(char* c1, char* c2);

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
%token POINTVIRGULE
%token<chaine> MOT
%token<chaine> ENTIER

%type<chaine> ExpressionMot
%type<valEntiere> ExpressionEntier
%type<chaine> Regle
%type<valBool> Predicat
%type<chaine> Programme
%type<chaine> Instruction
%type<valBool> Conditions
%type<valBool> Condition
%type<valBool> Comparaison

%start Entree

%%

Entree:
	/* Vide */
	| FIN								{ printf("Fin du programme\n"); return 0; }
	| FINFINALE							{ printf("Fin du programme\n"); return 0; }
	| Regle FIN Entree					{ printf("Preuve lue en entier\n"); }
	| Comparaison FIN Entree
	| ExpressionMot FIN Entree
	| ExpressionEntier FIN Entree
	;

/*
Conclusion:
	Predicat Programme Predicat
	;
	
DebRegleAFF:
	AFF CONCLUSION Predicat Programme Predicat
	;
*/

Regle:
	AFF CONCLUSION Predicat Programme Predicat PREMISSE Regle
		{
			printf("Erreur : prémisse présente dans la règle AFF : %s\n", $$);
		}
	| AFF CONCLUSION Predicat Programme Predicat
		{
			// remplacer les prédicats selon la règle
		}
	| AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			/*if($5 != $8)
				printf("Erreur : prédicats de la règle AFF pas égaux : %s\n", $$);*/
		}
	| SEQ CONCLUSION Predicat Programme Predicat PREMISSE AFF CONCLUSION Predicat Programme Predicat AFF CONCLUSION Predicat Programme Predicat
		{
			printf("Ersefsefsfe");
			/*char* ProgrammeTotal= $10;
			strcat(ProgrammeTotal, ";");
			strcat(ProgrammeTotal, $15);
			printf("fefe -> %s TRUC %s\n", $10, $15);
			if(compare(ProgrammeTotal, $4) == false) {
				printf("Erreur : programmes de la règle SEQ incorrects : |%s| != |%s|\n", ProgrammeTotal, $4);
			}
			else {				
				printf("Programmes de la règle SEQ identiques : |%s|\n", ProgrammeTotal);
			}*/
		}
	;

Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			$$ = $2;
		}
	| ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			printf("bob\n");
		}
	;
	
Conditions:
	Condition ET Conditions
		{
			$$ = ($1 && $3);
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
			if(atoi($1) > atoi($3)) {
				printf("Erreur : comparaison INF non logique : %s < %s\n", $1, $3);
			}
			else {
				$$ = $1;
				// char *d1 = $1;
				// char *d3 = $3;
				strcat($$, "<");
				strcat($$, $3);
			}
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			if(atoi($1) < atoi($3)) {
				printf("Erreur : comparaison SUP non logique : %s > %s\n", $1, $3);
			}
			else {
				$$ = $1;
				// char *d1 = $1;
				// char *d3 = $3;
				strcat($$, ">");
				strcat($$, $3);
			}
			else $$ = true;
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			if(atoi($1) > atoi($3)) {
				printf("Erreur : comparaison INF_EGAL non logique : %s <= %s\n", $1, $3);
			}
			else {
				$$ = $1;
				// char *d1 = $1;
				// char *d3 = $3;
				strcat($$, "<=");
				strcat($$, $3);
			}
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			if(atoi($1) < atoi($3)) {
				/*char *t1 = "1";
				char *t2 = "-98";
				if(t1 < t2) printf("  1<-98  ");
				else 		printf("  1>-98  ");*/
				printf("Erreur : comparaison SUP_EGAL non logique : %s >= %s\n", $1, $3);
			}
			else {
				$$ = $1;
				// char *d1 = $1;
				// char *d3 = $3;
				strcat($$, ">=");
				strcat($$, $3);
			}
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
	Instruction POINTVIRGULE Programme
		{
			/*$$= $1;
			strcat($$, ";");
			strcat($$, $3);
			printf("Prgm long : %s\n", $$);*/
		}
	| Instruction
		{
			/*$$= $1;
			printf("Prgm\n");*/
		}
	;
	
Instruction:
	MOT AFFECTATION ExpressionEntier
		{
			/*$$= $1;
			strcat($$, ":=");
			//strcat($$, $3);
			printf("Inst longue : %s\n", $$);*/
			
		}
	| MOT AFFECTATION ExpressionMot
		{
			/*$$= $1;
			strcat($$, ":=");
			strcat($$, $3);
			printf("Inst\n");*/
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
			printf("ok1 - ");
			// $$ = atoi($1) + $3;
		}
	| ENTIER MOINS ExpressionEntier
		{
			printf("ok2 - ");
			// $$ = atoi($1) - $3;
		}
	| ENTIER FOIS ExpressionEntier
		{
			printf("ok3 - ");
			// $$ = atoi($1) * $3;
		}
	| ENTIER
		{
			printf("ok4 - ");
			// $$ = atoi($1);
		}
	;

%%

boolean compare(char* c1, char* c2) {
	if(strlen(c1) != strlen(c2))
		return false;
	unsigned int i = 0;
	for(i=0; i<strlen(c1); i++)
		if(c1[i] != c2[i])
			return false;
	return true;
} 

int yyerror(char *s) {
  printf("%s\n",s);
}

int compare(char* chaine1, char* chaine2)
{   unsigned int i=0;
    if( strlen(chaine1) != strlen(chaine2) )
        return 0;
    for(i=0;i<strlen(chaine1);i++)
        if( chaine1[i] != chaine2[i])
            return 0;
    return 1;
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
