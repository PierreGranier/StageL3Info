%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"

extern FILE* yyin;

int compare(char* c1, char* c2);

%}

%union {
	char* chaine;
	t_entier entier;
	t_triplet triplet;
}

%token FIN
%token FINFINALE

%token<chaine> MOT
%token<entier> ENTIER

%token AFF SEQ
%token ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token AFFECTATION
%token POINTVIRGULE

%token INF_EGAL SUP_EGAL SUP INF EGAL
%token ET

%token PLUS MOINS FOIS

%type<chaine> ExpressionMot
%type<entier> ExpressionEntier
%type<chaine> Regle
%type<chaine> Predicat
%type<chaine> Programme
%type<chaine> Instruction
%type<chaine> Conditions
%type<chaine> Condition
%type<chaine> Comparaison
%type<triplet> Triplet

%start Entree

%%

Entree:
	/* Vide */
	| FIN								{ printf("Fin du programme\n"); return 0; }
	| FINFINALE							{ printf("Fin du programme\n"); return 0; }
	| Regle FIN Entree					{ printf("Preuve lue en entier\n"); }
	;
	
Regle:
	AFF Triplet
		{
			// remplacer les prédicats selon la règle
		}
	| AFF Triplet AFF Triplet
		{
			if(compare($2.postcondition, $4.precondition)==0) {
				printf("[ERREUR] Prédicats de la règle AFF pas égaux : %s\n", $$);
			}
		}
	| SEQ Triplet AFF Triplet AFF Triplet
		{
			/*char* ProgrammeTotal= $10;
			strcat(ProgrammeTotal, ";");
			strcat(ProgrammeTotal, $15);
			printf("fefe -> %s TRUC %s\n", $10, $15);
			if(compare(ProgrammeTotal, $4) == false) {
				printf("[ERREUR] Programmes de la règle SEQ incorrects : |%s| != |%s|\n", ProgrammeTotal, $4);
			}
			else {				
				printf("Programmes de la règle SEQ identiques : |%s|\n", ProgrammeTotal);
			}*/
		}
	/*| .
		{
			printf("[ERREUR] Règle non reconnue");
		}*/
	;
	
Triplet:
	Predicat Programme Predicat
		{
			$$.precondition = $1;
			$$.programme = $2;
			$$.postcondition = $3;
		}
	;
	
Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			$$ = $2;
		}
	;
	
Conditions:
	/* vide */
		{}
	| Condition ET Conditions
		{
			$$ = $1;
			strcat($$, $1);
			strcat($$, "^");
			strcat($$, $3);
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
			if($1.valeur >= $3.valeur) {
				printf("[ERREUR] Comparaison INF non logique : %d < %d\n", $1.valeur, $3.valeur);
			}
			$$ = $1.chaine;
			strcat($$, "<");
			strcat($$, $3.chaine);
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			if($1.valeur <= $3.valeur) {
				printf("[ERREUR] Comparaison SUP non logique : %d > %d\n", $1.valeur, $3.valeur);
			}
			$$ = $1.chaine;
			strcat($$, ">");
			strcat($$, $3.chaine);
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			if($3.valeur > $3.valeur) {
				printf("[ERREUR] Comparaison INF_EGAL non logique : %d <= %d\n", $1.valeur, $3.valeur);
			}
			$$ = $1.chaine;
			strcat($$, "<=");
			strcat($$, $3.chaine);
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			if($1.valeur < $3.valeur) {
				printf("[ERREUR] Comparaison SUP_EGAL non logique : %d >= %d\n", $1.valeur, $3.valeur);
			}
			$$ = $1.chaine;
			strcat($$, ">=");
			strcat($$, $3.chaine);
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
	
ExpressionEntier:
	ENTIER PLUS ExpressionEntier
		{
			$$.valeur = $1.valeur + $3.valeur;
			printf("%d + %d = %d\n", $1.valeur, $3.valeur, $$.valeur);
		}
	| ENTIER MOINS ExpressionEntier
		{
			$$.valeur = $1.valeur - $3.valeur;
			printf("%d - %d = %d\n", $1.valeur, $3.valeur, $$.valeur);
		}
	| ENTIER FOIS ExpressionEntier
		{
			$$.valeur = $1.valeur * $3.valeur;
			printf("%d * %d = %d\n", $1.valeur, $3.valeur, $$.valeur);
		}
	| ENTIER
		{
			$$.chaine = $1.chaine;
			$$.valeur = $1.valeur;
		}
	;
	
ExpressionMot:
	MOT PLUS ExpressionMot
		{
			$$ = $1;
			strcat($$, "+");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT MOINS ExpressionMot
		{
			$$ = $1;
			strcat($$, "-");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT FOIS ExpressionMot
		{
			$$ = $1;
			strcat($$, "*");
			strcat($$, $3);
			printf("%s", $$);
		}
	| MOT
		{
			$$ = $1;
		}
	;
	
Programme:
	Instruction POINTVIRGULE Programme
		{
			$$ = $1;
			strcat($$, ";");
			strcat($$, $3);
		}
	| Instruction
		{
			$$= $1;
		}
	;
	
Instruction:
	MOT AFFECTATION ExpressionEntier
		{
			$$ = $1;
			strcat($$, ":=");
			strcat($$, $3.chaine);			
		}
	| MOT AFFECTATION ExpressionMot
		{
			$$ = $1;
			strcat($$, ":=");
			strcat($$, $3);
		}
	;
	
%%

/*boolean compare(char* c1, char* c2) {
	if(strlen(c1) != strlen(c2))
		return false;
	unsigned int i = 0;
	for(i=0; i<strlen(c1); i++)
		if(c1[i] != c2[i])
			return false;
	return true;
}*/

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
