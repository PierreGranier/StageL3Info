%{

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "global.h"

#define false	0
#define true 	1
typedef char boolean;

boolean compare(char* c1, char* c2);

extern "C" int yylex(void);
extern "C" int yyparse(void);
extern "C" void yyerror(const std::string&);
extern FILE* yyin;

%}

%union {
	char* chaine;
	t_entier entier;
	t_triplet triplet;
	t_instruction instruction;	
	t_programme programme;
	boolean valBool;
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
%type<programme> Programme
%type<instruction> Instruction
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
			char *gen;
			gen = $2.postcondition;
			// remplacer(gen, $2.programme.instruction.variable, $2.programme.instruction.valeur);
			if(compare(gen, $2.precondition) == false)
			{
					printf("[ERREUR] Mauvaise Précondition ou Postcondition  : %s\n", $$);
			}
		}
	| AFF Triplet AFF Triplet
		{
			if(compare($2.postcondition, $4.precondition) == false) {
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
	| ExpressionEntier EGAL ExpressionEntier
		{
			if($1.valeur != $3.valeur) {
				printf("[ERREUR] Comparaison EGAL non logique : %d = %d\n", $1.valeur, $3.valeur);
			}
			$$ = $1.chaine;
			strcat($$, "=");
			strcat($$, $3.chaine);
		}
	| ExpressionMot		INF			ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		SUP			ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		INF_EGAL	ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		SUP_EGAL	ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		EGAL		ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		INF			ExpressionEntier	{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		SUP			ExpressionEntier	{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		INF_EGAL	ExpressionEntier	{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		SUP_EGAL	ExpressionEntier	{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionMot		EGAL		ExpressionEntier	{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionEntier	INF			ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionEntier	SUP			ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
	| ExpressionEntier	EGAL		ExpressionMot		{ printf("peut pas comparer sémantiquement des MOTS\n"); }
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
			$$.contenu = $1.variable;
			strcat(strcat($$.contenu, ":="), $1.valeur);
			strcat($$.contenu, ";");
			strcat($$.contenu, $3.contenu);
			$$.instruction = $1;
		}
	| Instruction
		{
			$$.contenu = $1.variable;
			strcat($$.contenu, ":=");
			strcat($$.contenu, $1.valeur);
			$$.instruction = $1;
		}
	;
	
Instruction:
	MOT AFFECTATION ExpressionEntier
		{
			$$.variable = $1;
			$$.valeur = $3.chaine;
			/*strcat($$, ":=");
			strcat($$, $3.chaine);*/			
		}
	| MOT AFFECTATION ExpressionMot
		{
			$$.variable = $1;
			$$.valeur = $3;
			/*strcat($$, ":=");
			strcat($$, $3);*/
		}
	;
	
%%

void yyerror(const std::string& mess) {
  std::cerr << "ERROR : "<< mess<< std::endl;
}

boolean compare(char* chaine1, char* chaine2)
{
	unsigned int i=0;
    if(strlen(chaine1) != strlen(chaine2))
        return false;
    for(i=0;i<strlen(chaine1);i++)
        if( chaine1[i] != chaine2[i])
            return false;
    return true;
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
