%{
#include "global.h"
#include "fonctions.c"

// Permettre l'utilisation du C++
extern "C" int yylex(void);
extern "C" int yyparse(void);
extern "C" void yyerror(const std::string&);
extern FILE* yyin;
%}

// Importation des types définis en C++ (pour les utiliser en Yacc)
%union {
	string chaine;
	t_entier entier;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;
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
	| FIN						{ cout << "Fin du programme" << endl; return 0; }
	| FINFINALE					{ cout << "Fin du programme" << endl; return 0; }
	| Regle FIN Entree			{ cout << "Preuve lue en entier" << endl; }
	| Predicat FIN Entree
	| ExpressionMot FIN Entree
	| ExpressionEntier FIN Entree
	;
	
Regle:
	AFF Triplet
		{
			string gener;
			gener = $2.postcondition;
			remplacer(gener, $2.programme.instruction.variable, $2.programme.instruction.valeur);
			cout << "BOB = " << $2.postcondition << " ET GENNERE " << gener << endl;
			if(gener.compare($2.precondition) != 0)
			{
					cout << "[ERREUR] Mauvaise Précondition ou Postcondition  : " << $$ << endl;
			}
		}
	| AFF Triplet AFF Triplet
		{
			if($2.postcondition.compare($4.precondition) != 0) {
				cout << "[ERREUR] Prédicats de la règle AFF pas égaux : " << $$ << endl;
			}
		}
	| SEQ Triplet AFF Triplet AFF Triplet
		{
			if($2.precondition.compare($4.precondition) != 0) 
			{
				cout << "[ERREUR] Précondition de SEQ != de Précondition de AFF(1)" << endl; 
			}
			if($2.postcondition.compare($6.postcondition) !=0)
			{
				cout << "[ERREUR] Postcondition de SEQ != de Postcondition de AFF(2)" << endl;
			}
			if($4.postcondition.compare($6.precondition) != 0)
			{
				cout << "[ERREUR] Postcondition de AFF(1) != de Précondition de AFF(2)" << endl;
			}
			
			if($2.programme.contenu.compare($4.programme.contenu + ";" + $6.programme.contenu) != 0) {
				cout << "[ERREUR] Programmes de la règle SEQ incorrects : " << $2.programme.contenu << " différent de " << $4.programme.contenu + ";" + $6.programme.contenu  << endl;
			}
		}
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
			$$ = $1 + "^" + $3;
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
				cout << "[ERREUR] Comparaison INF non logique : " << $1.valeur << "<" << $3.valeur << endl;
			}
			$$ = $1.chaine + "<" + $3.chaine;
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			if($1.valeur <= $3.valeur) {
				cout << "[ERREUR] Comparaison SUP non logique : " << $1.valeur << ">" << $3.valeur << endl;
			}
			$$ = $1.chaine + ">" + $3.chaine;
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			if($3.valeur > $3.valeur) {
				cout << "[ERREUR] Comparaison INF_EGAL non logique : " << $1.valeur << "<=" << $3.valeur << endl;
			}
			$$ = $1.chaine + "<=" + $3.chaine;
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			if($1.valeur < $3.valeur) {
				cout << "[ERREUR] Comparaison SUP_EGAL non logique : " << $1.valeur << ">=" << $3.valeur << endl;
			}
			$$ = $1.chaine + ">=" + $3.chaine;
		}
	| ExpressionEntier EGAL ExpressionEntier
		{
			if($1.valeur != $3.valeur) {
				cout << "[ERREUR] Comparaison EGAL non logique : " << $1.valeur << "=" << $3.valeur << endl;
			}
			$$ = $1.chaine + "=" + $3.chaine;
		}
	| ExpressionMot		INF			ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		SUP			ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		INF_EGAL	ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		SUP_EGAL	ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		EGAL		ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		INF			ExpressionEntier	{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		SUP			ExpressionEntier	{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		INF_EGAL	ExpressionEntier	{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		SUP_EGAL	ExpressionEntier	{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionMot		EGAL		ExpressionEntier	{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionEntier	INF			ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionEntier	SUP			ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	| ExpressionEntier	EGAL		ExpressionMot		{ cout << "peut pas comparer sémantiquement des MOTS\n" << endl; }
	;
	
ExpressionEntier:
	ENTIER PLUS ExpressionEntier
		{
			$$.valeur = $1.valeur + $3.valeur;
			$$.chaine = to_string($$.valeur);
			cout << $1.valeur << "+" << $3.valeur << "=" << $$.valeur << endl;
			cout << $$.valeur << " ?=" << $$.chaine << "| " << endl;
		}
	| ENTIER MOINS ExpressionEntier
		{
			$$.valeur = $1.valeur - $3.valeur;
			$$.chaine = to_string($$.valeur);
			cout << $1.valeur << "-" << $3.valeur << "=" << $$.valeur << endl;
			cout << $$.valeur << " ?= " << $$.chaine << endl;
		}
	| ENTIER FOIS ExpressionEntier
		{
			$$.valeur = $1.valeur * $3.valeur;
			$$.chaine = to_string($$.valeur);
			cout << $1.valeur << "*" << $3.valeur << "=" << $$.valeur << endl;
			cout << $$.valeur << " ?= " << $$.chaine << endl;
		}
	| ENTIER
		{
			$$.valeur = $1.valeur;
			$$.chaine = $1.chaine;
			// cout << $$.valeur << " ?= " << $$.chaine << endl;
		}
	;
	
ExpressionMot:
	MOT PLUS ExpressionMot
		{
			$$ = $1 + "+" + $3;
			cout << $1 << "+" << $3 << "=" << $$ << endl;
		}
	| MOT MOINS ExpressionMot
		{
			$$ = $1 + "-" + $3;
		}
	| MOT FOIS ExpressionMot
		{
			$$ = $1 + "*" + $3;
		}
	| MOT		PLUS		ExpressionEntier	{ $$ = $1 + "+" + $3.chaine; cout << $1 << "+" << $3.chaine << "=" << $$ << endl; }
	| MOT		MOINS		ExpressionEntier	{ $$ = $1 + "-" + $3.chaine; }
	| MOT		FOIS		ExpressionEntier	{ $$ = $1 + "*" + $3.chaine; }
	| ENTIER 	PLUS 		MOT		{ $$ = $1.chaine + "+" + $3; cout << $1.chaine << "+" << $3 << "=" << $$ << endl; }
	| ENTIER 	MOINS 		MOT		{ $$ = $1.chaine + "-" + $3; }
	| ENTIER 	FOIS 		MOT		{ $$ = $1.chaine + "*" + $3; }
	| MOT
		{
			$$ = $1;
		}
	;
	
Programme:
	Instruction POINTVIRGULE Programme
		{
			$$.contenu = $1.variable + ":=" + $1.valeur + ";" + $3.contenu;
			$$.instruction = $1;
		}
	| Instruction
		{
			$$.contenu = $1.variable + ":=" + $1.valeur;
			$$.instruction = $1;
		}
	;
	
Instruction:
	MOT AFFECTATION ExpressionEntier
		{
			$$.variable = $1;
			$$.valeur = $3.chaine;		
		}
	| MOT AFFECTATION ExpressionMot
		{
			$$.variable = $1;
			$$.valeur = $3;
		}
	;
	
%%

void yyerror(const string& mess) {
  cerr << "ERROR : "<< mess<< endl;
}

int main(int argc, char **argv) {
	if(argc == 2){
		yyin = fopen(argv[1], "r");
		cout << "Fichier utilisé\n" << endl;
	}
	yyparse();
	//yylex();

	/*if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;*/

	return EXIT_SUCCESS;
}
