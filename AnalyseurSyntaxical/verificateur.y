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
	t_proposition proposition;
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

%token INF_EGAL SUP_EGAL SUP INF EGAL NON_EGAL
%token ET VRAI FAUX

%token PLUS MOINS FOIS

%type<triplet> Regle
%type<triplet> Triplet
%type<proposition> Predicat
%type<proposition> Conditions
%type<proposition> Condition
%type<proposition> Comparaison
%type<programme> Programme
%type<instruction> Instruction
%type<expression> Expression
%type<expression> ExpressionMot
%type<expression> ExpressionEntier

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
	Triplet
		{
			// Le seul triplet invalide est de la forme {vrai} ... {faux}
			if($1.precondition.valeur == true && $1.postcondition.valeur == false)
			{
				cout << "[ERREUR][SEMANTIQUE] Le triplet {" << $1.precondition.affirmation << "} prog {" << $1.postcondition.affirmation << "} n'est pas valide : vrai -> faux = faux" << endl;
			}
			
			// Si la précondition est vraie pour tout état initial vérifiant la précondition et si l'exécution du programme se termine
			// Alors la précondition est vraie après l'exécution du programme
			
			// Si la précondition est vraie pour tout état initial vérifiant la précondition
			// Alors l'exécution du programme se termine et la précondition est vraie après l'exécution du programme
			
			$$ = $1;
		}
	| AFF Triplet
		{
			string gener;
			gener = $2.postcondition.affirmation;
			remplacer(gener, $2.programme.instruction.variable, $2.programme.instruction.valeur);
			// Vérification syntaxique du triplet (les prédicats sont vérifiés syntaxiquement)
			if(gener.compare($2.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition est incorrecte dans le triplet de AFF : générer " << gener << " au lieu de " << $2.precondition.affirmation << endl;
			}
			$$ = $2; // copie les prédicats et les programmes
		}
	| SEQ Triplet Regle Regle
		{
			// Précondition de la conclusion comparée avec la précondition de la prémisse (1)
			if($2.precondition.affirmation.compare($3.precondition.affirmation) != 0) 
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de SEQ " << $2.precondition.affirmation << " est différente de la précondition de la prémisse (1) " << $3.precondition.affirmation << endl; 
			}
			// Postcondition de la conclusion comparée avec la postcondition de la prémisse (2)
			if($2.postcondition.affirmation.compare($4.postcondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de SEQ " << $2.postcondition.affirmation << " est différente de la postcondition de la prémisse (2) " << $4.postcondition.affirmation << endl;
			}
			// Postcondition de la prémisse (1) comparée avec la précondition de la prémisse (2)
			if($3.postcondition.affirmation.compare($4.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de (1) " << $3.postcondition.affirmation << " est différente de la précondition de la prémisse (2) " << $4.precondition.affirmation << endl;
			}
			// Programme de la conclusion comparé avec le programmes de la prémisse (1) et (2)
			if($2.programme.contenu.compare($3.programme.contenu + ";" + $4.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Les programmes de SEQ sont incorrects : " << $2.programme.contenu << " différent de " << $3.programme.contenu + ";" + $4.programme.contenu  << endl;
			}
			$$ = $2; // copie les prédicats et les programmes
		}
	| COND Triplet Regle Regle
		{
			//  Précondition de la prémisse (1) comparée avec B et P de la conclusion
			if($3.precondition.affirmation.compare($2.programme.si.affirmation + "^" + $2.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse (1) de COND " << $3.precondition.affirmation << " est différente de " << $2.programme.si.affirmation << "^" << $2.precondition.affirmation << endl;
			}
			//  Postcondition de la conclusion comparée avec la postcondition de la prémisse (1) puis (2)
			if($2.postcondition.affirmation.compare($3.postcondition.affirmation) != 0 && $3.postcondition.affirmation.compare($4.postcondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Les postconditions de COND sont différentes : " << $2.postcondition.affirmation << " != " << $3.postcondition.affirmation << "!=" << $4.postcondition.affirmation << endl;
			}
			// Précondition de la prémisse (2) comparée avec NON B et P de la conclusion
			if($4.precondition.affirmation.compare($2.programme.si.negation + "^" + $2.precondition.affirmation) != 0) {
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse (2) de COND " << $4.precondition.affirmation << " est différente de " << $2.programme.si.negation << "^" << $2.precondition.affirmation << endl;
			}
			// Programme ALORS de la conclusion comparé avec le programme de la prémisse (1)
			if($2.programme.alors.compare($3.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de COND " << $2.programme.alors << " est différent du programme de la prémisse (1) " << $3.programme.contenu << endl;
			}
			// Programme SINON de la conclusion comparé avec le programme de la prémisse (2)
			if($2.programme.sinon.compare($4.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de COND " << $2.programme.sinon << " est différent du programme de la prémisse (2) " << $4.programme.contenu << endl;
			}
			$$ = $2; // copie les prédicats et les programmes
		}
	//| CONSEQ Triplet Expression Regle Expression
	| CONSEQ Triplet Regle
		{
			// Programme de la conclusion comparé avec le programme de la prémisse
			if($2.programme.contenu.compare($3.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de CONSEQ " << $2.programme.contenu << " est différent du programme de la prémisse " << $3.programme.contenu << endl;
			}
			// Si les préconditions sont différentes alors on check si elles sont conséquences
			if($2.precondition.affirmation.compare($3.precondition.affirmation) != 0) 
			{
				cout << "[CONSEQ] Prec " << $2.precondition.affirmation << " => " << $3.precondition.affirmation << endl;
				
				// si $3.precondition.affirmation contient "faux" entre deux séparateurs, vérifier que $2.precondition.affirmation = false
				// si $3.precondition.affirmation vaut "vrai", vérifier que $2.precondition.affirmation = true
				
				// Valeur booléenne de la précondition de la conclusion comparée à la valeur booléenne de la précondition de la prémisse
				// if($2.precondition.valeur != $3.precondition.valeur)
				// {
				// 	cout << "[ERREUR][SEMANTIQUE] La précondition de la conclusion " << $2.precondition.affirmation << " n'implique pas la précondition de la prémisse " << $3.precondition.affirmation << endl;
				// }
			}
			// Si les postcondition sont différentes alors on check si elles sont conséquences
			if($2.postcondition.affirmation.compare($3.postcondition.affirmation) != 0)
			{
				cout << "[CONSEQ] Post " << $3.postcondition.affirmation << " => " << $2.postcondition.affirmation << endl;
				
				// si $3.postcondition.affirmation contient "faux" entre deux séparateurs, vérifier que $2.programme.contenu^$2.postcondition.affirmation = false
				// si $3.postcondition.affirmation vaut "vrai", vérifier que $2.programme.contenu^$2.postcondition.affirmation = true
				
				// Valeur booléenne de la postcondition de la prémisse comparée à la valeur booléenne de la postcondition de la conclusion
				// if($3.postcondition.valeur != $2.postcondition.valeur)
				// {
				// 	cout << "[ERREUR][SEMANTIQUE] La postcondition de la prémisse " << $3.postcondition.affirmation << " n'implique pas la postcondition de la conclusion " << $2.postcondition.affirmation << endl;
				// }
			}
			$$ = $2; // copie les prédicats et les programmes
		}
	| WHILE Triplet Regle
		{
			//  Postcondition de la conclusion comparée avec NON B et I de la conclusion 
			if($2.postcondition.affirmation.compare($2.programme.tantque.affirmation + "^" + $2.precondition.affirmation))
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de WHILE " << $2.postcondition.affirmation << " est différente de " << $2.programme.tantque.affirmation << "^" << $2.precondition.affirmation << endl;
			}
			//  Précondition de la prémisse comparée avec I et B de la conclusion
			if($3.precondition.affirmation.compare($2.precondition.affirmation + "^" + $2.programme.tantque.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILE " << $3.precondition.affirmation << " est différente de " << $2.precondition.affirmation << "^" << $2.programme.tantque.affirmation << endl;
			}
			// Postcondition de la prémisse comparée avec la précondition de la conclusion
			if($3.postcondition.affirmation.compare($2.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la prémisse de WHILE " << $3.precondition.affirmation << " est différente de la précondition de la conclusion " << $2.precondition.affirmation << endl;
			}
			// Programme FAIRE de la conclusion comparé avec le programme de la prémisse
			if($2.programme.faire.compare($3.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de WHILE " << $2.programme.faire << " est différent du programme de la prémisse " << $3.programme.contenu << endl;
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
		{} // conflits à cause du vide
	| Condition ET Conditions
		{
			$$.affirmation = $1.affirmation + "^" + $3.affirmation;
			$$.negation = $1.negation + "^" + $3.negation;
			$$.valeur = $1.valeur && $3.valeur;
			
			// Une formule qui contient une condition et sa négation est fausse
			int pos = ($$.affirmation.find($1.negation));
			if(pos > -1) {
				//cout << "[ERREUR][SEMANTIQUE] Conditions donnant lieu à un prédicat faux : la formule " << $$.affirmation << " contient à la fois la condition " << $1.affirmation << " et sa négation " << $1.negation << endl;
				$$.valeur = false;
			}
			// Une formule qui contient une condition "faux" est fausse
			if($$.affirmation.find("faux")) {
				//cout << "[ERREUR][SEMANTIQUE] Condition donnant lieu à un prédicat faux : la formule " << $$.affirmation << " contient la condition \"faux\"" << endl;
				$$.valeur = false;
			}
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
	| VRAI // conflits
		{
			$$.affirmation = "vrai";
			$$.negation = "faux";
			$$.valeur = true;
		}
	| FAUX // conflits
		{
			$$.affirmation = "faux";
			$$.negation = "vrai";
			$$.valeur = false;
		}
	;
	
Comparaison:
	ExpressionEntier INF ExpressionEntier
		{
			if($1.valeur >= $3.valeur) {
				//cout << "[ERREUR][SEMANTIQUE] Comparaison INF non logique : " << $1.valeur << "<" << $3.valeur << endl;
			}
			$$.affirmation = $1.chaine + "<" + $3.chaine;
			$$.negation = $1.chaine + ">=" + $3.chaine;
			$$.valeur = $1.valeur < $3.valeur;
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			if($1.valeur <= $3.valeur) {
				//cout << "[ERREUR][SEMANTIQUE] Comparaison SUP non logique : " << $1.valeur << ">" << $3.valeur << endl;
			}
			$$.affirmation = $1.chaine + ">" + $3.chaine;
			$$.negation = $1.chaine + "<=" + $3.chaine;
			$$.valeur = $1.valeur > $3.valeur;
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			if($3.valeur > $3.valeur) {
				//cout << "[ERREUR][SEMANTIQUE] Comparaison INF_EGAL non logique : " << $1.valeur << "<=" << $3.valeur << endl;
			}
			$$.affirmation = $1.chaine + "<=" + $3.chaine;
			$$.negation = $1.chaine + ">" + $3.chaine;
			$$.valeur = $1.valeur <= $3.valeur;
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			if($1.valeur < $3.valeur) {
				//cout << "[ERREUR][SEMANTIQUE] Comparaison SUP_EGAL non logique : " << $1.valeur << ">=" << $3.valeur << endl;
			}
			$$.affirmation = $1.chaine + ">=" + $3.chaine;
			$$.negation = $1.chaine + "<" + $3.chaine;
			$$.valeur = $1.valeur >= $3.valeur;
		}
	| ExpressionEntier EGAL ExpressionEntier
		{
			if($1.valeur != $3.valeur) {
				//cout << "[ERREUR][SEMANTIQUE] Comparaison EGAL non logique : " << $1.valeur << "=" << $3.valeur << endl;
			}
			$$.affirmation = $1.chaine + "=" + $3.chaine;
			$$.negation = $1.chaine + "!=" + $3.chaine;
			$$.valeur = $1.valeur = $3.valeur;
		}
	| ExpressionMot		INF			Expression			{ $$.affirmation = $1.chaine + "<" + $3.chaine; 		$$.negation = $1.chaine + ">=" + $3.chaine; }
	| ExpressionMot		SUP			Expression			{ $$.affirmation = $1.chaine + ">" + $3.chaine;			$$.negation = $1.chaine + "<=" + $3.chaine; }
	| ExpressionMot		INF_EGAL	Expression			{ $$.affirmation = $1.chaine + "<=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine;  }
	| ExpressionMot		SUP_EGAL	Expression			{ $$.affirmation = $1.chaine + ">=" + $3.chaine;		$$.negation = $1.chaine + "<" + $3.chaine;  }    
	| ExpressionMot		EGAL		Expression			{ $$.affirmation = $1.chaine + "=" + $3.chaine;			$$.negation = $1.chaine + "!=" + $3.chaine; }
	| ExpressionEntier	INF			ExpressionMot		{ $$.affirmation = $1.chaine + "<" + $3.chaine; 		$$.negation = $1.chaine + ">=" + $3.chaine; }
	| ExpressionEntier	SUP			ExpressionMot		{ $$.affirmation = $1.chaine + ">" + $3.chaine; 		$$.negation = $1.chaine + "<=" + $3.chaine; }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ $$.affirmation = $1.chaine + "<=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine;  }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ $$.affirmation = $1.chaine + ">=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine;  }
	| ExpressionEntier	EGAL		ExpressionMot		{ $$.affirmation = $1.chaine + "=" + $3.chaine; 		$$.negation = $1.chaine + "!=" + $3.chaine; }
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
			$$.contenu = $1.affirmation + " " + $2.contenu + " " + $3.contenu;
			$$.si = $1;
			$$.alors = $2.contenu;
			$$.sinon = $3.contenu;
		}
	| Conditions Programme
		{
			$$.contenu = $1.affirmation + " " + $2.contenu;
			$$.si = $1;
			$$.alors = $2.contenu;
			$$.tantque = $1;
			$$.faire = $2.contenu;
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
  cerr << "[ERREUR][YYERROR] " << mess << endl;
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