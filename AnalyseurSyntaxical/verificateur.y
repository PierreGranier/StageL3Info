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
	t_expression expression;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;
}

%token FIN
%token FINFINALE

%token<expression> MOT
%token<expression> ENTIER

%token AFF SEQ COND CONSEQ WHILE
%token ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token AFFECTATION
%token POINTVIRGULE

%token INF_EGAL SUP_EGAL SUP INF EGAL
%token ET

%token PLUS MOINS FOIS

%type<triplet> Regle
%type<expression> Expression
%type<expression> ExpressionMot
%type<expression> ExpressionEntier
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
	| Regle FIN Entree			{ cout << "Fin du programme" << endl; return 0; }
	;
	
																								/*
																								// Preuve
																								Arbre:
																									Branche
																									;
																									
																								// Sous-preuve
																								Branche:
																									| Regle
																										{
																											
																										}
																									| Regle Regle
																										{
																											
																										}
																									;
																								*/
	
Regle:
																								/*AFF Triplet
																								| SEQ Triplet Regle Regle
																								| COND Triplet Regle Regle
																								| CONSEQ Triplet Expression Regle Expression
																								| WHILE Triplet Regle*/
	
	AFF Triplet
		{
			string gener;
			gener = $2.postcondition;
			remplacer(gener, $2.programme.instruction.variable, $2.programme.instruction.valeur);
			if(gener.compare($2.precondition) != 0)
			{
					cout << "[ERREUR] La précondition est incorrecte dans le triplet de AFF : générer " << gener << " au lieu de " << $2.precondition << endl;
			}
			$$ = $2;
		}
	| SEQ Triplet Regle Regle
		{
			// Pour la prochaine boucle s'il y a:
			$$.precondition = $2.precondition;
			$$.programme.contenu = $2.programme.contenu;
			$$.postcondition = $2.postcondition;
			
			if($2.precondition.compare($3.precondition) != 0) 
			{
				cout << "[ERREUR] La précondition de SEQ " << $2.precondition << " est différente de la précondition de (1) " << $3.precondition << endl; 
			}
			if($2.postcondition.compare($4.postcondition) != 0)
			{
				cout << "[ERREUR] La postcondition de SEQ " << $2.postcondition << " est différente de la postcondition de (2) " << $4.postcondition << endl;
			}
			if($3.postcondition.compare($4.precondition) != 0)
			{
				cout << "[ERREUR] La postcondition de (1) " << $3.postcondition << " est différente de la précondition de (2) " << $4.precondition << endl;
			}
			if($2.programme.contenu.compare($3.programme.contenu + ";" + $4.programme.contenu) != 0) {
				cout << "[ERREUR] Les programmes de la règle SEQ sont incorrects : " << $2.programme.contenu << " différent de " << $3.programme.contenu + ";" + $4.programme.contenu  << endl;
			}
		}
	| COND Triplet Regle Regle
		{
			if($3.precondition.compare($2.precondition+"^"+$2.programme.si) != 0)
			{
				cout << "[ERREUR] La précondition de COND " << $3.precondition << " est différente de " << $2.precondition << "^" << $2.programme.si << endl;
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
	| ExpressionMot		INF			Expression			{ $$ = $1.chaine + "<" + $3.chaine; }
	| ExpressionMot		SUP			Expression			{ $$ = $1.chaine + ">" + $3.chaine; }
	| ExpressionMot		INF_EGAL	Expression			{ $$ = $1.chaine + "<=" + $3.chaine; }
	| ExpressionMot		SUP_EGAL	Expression			{ $$ = $1.chaine + ">=" + $3.chaine; }
	| ExpressionMot		EGAL		Expression			{ $$ = $1.chaine + "=" + $3.chaine; }
	| ExpressionEntier	INF			ExpressionMot		{ $$ = $1.chaine + "<" + $3.chaine; }
	| ExpressionEntier	SUP			ExpressionMot		{ $$ = $1.chaine + ">" + $3.chaine; }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ $$ = $1.chaine + "<=" + $3.chaine; }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ $$ = $1.chaine + ">=" + $3.chaine; }
	| ExpressionEntier	EGAL		ExpressionMot		{ $$ = $1.chaine + "=" + $3.chaine; }
	;
	
Expression:
	ExpressionEntier
	| ExpressionMot
	;
	
ExpressionEntier:
	ENTIER PLUS ExpressionEntier
		{
			$$.valeur = $1.valeur + $3.valeur;
			$$.chaine = to_string($$.valeur);
		}
	| ENTIER MOINS ExpressionEntier
		{
			$$.valeur = $1.valeur - $3.valeur;
			$$.chaine = to_string($$.valeur);
		}
	| ENTIER FOIS ExpressionEntier
		{
			$$.valeur = $1.valeur * $3.valeur;
			$$.chaine = to_string($$.valeur);
		}
	| ENTIER
		{
			$$.valeur = $1.valeur;
			$$.chaine = $1.chaine;
		}
	| ENTIER PLUS ExpressionMot
		{
			$$.chaine = $1.chaine + "+" + $3.chaine;
		}
	;
	
ExpressionMot:
	MOT PLUS Expression
		{
			$$.chaine = $1.chaine + "+" + $3.chaine;
		}
	| MOT MOINS Expression
		{
			$$.chaine = $1.chaine + "-" + $3.chaine;
		}
	| MOT FOIS Expression
		{
			$$.chaine = $1.chaine + "*" + $3.chaine;
		}
	| MOT
		{
			$$.chaine = $1.chaine;
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
	| Conditions Programme Programme
		{
			$$.contenu = $1 + " " + $2.contenu + " " + $3.contenu;
			$$.si = $1;
			$$.alors = $2.contenu;
			$$.sinon = $3.contenu;
		}
	;
	
Instruction:
	MOT AFFECTATION ExpressionEntier
		{
			$$.variable = $1.chaine;
			$$.valeur = $3.chaine;
		}
	| MOT AFFECTATION ExpressionMot
		{
			$$.variable = $1.chaine;
			$$.valeur = $3.chaine;
		}
	;
	
%%

void yyerror(const string& mess) {
  cerr << "[ERREUR] yyerror : " << mess << endl;
}

int main(int argc, char **argv) {
	// Lecture du fichier si envoyé
	if(argc == 2) {
		yyin = fopen(argv[1], "r");
		cout << "\nFichier utilisé\nLecture de la preuve" << endl;
	}
		
	// Verification de la preuve
	yyparse();
		
	// Fin de la vérification de la preuve
	cout << "Preuve lue en entier\nPreuve vérifiée si pas de message d'erreur" << endl;

	return EXIT_SUCCESS;
}
