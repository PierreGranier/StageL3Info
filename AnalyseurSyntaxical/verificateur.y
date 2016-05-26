%{
#include "global.h"
#include "fonctions.cpp"

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

%token AFF SEQ COND CONSEQ WHILE WHILET
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
%type<programme> ProgrammeCompose
%type<instruction> Instruction
%type<expression> Expression
%type<expression> ExpressionMot
%type<expression> ExpressionEntier

%start Entree

%%

Entree:
	/* vide */
	| FIN						{ /*cout << "Fin du programme" << endl; */ return 0; }
	| FINFINALE					{ /*cout << "Fin du programme" << endl; */ return 0; }
	| Regle FIN Entree			{ /*cout << "Fin du programme" << endl; */ return 0; }
	| Conditions FIN Entree
	;
	
Regle:
	AFF Triplet
		{
			string gener;
			gener = $2.postcondition.affirmation;
			remplacer(gener, $2.programme.instruction.variable, $2.programme.instruction.valeur);
			// Vérification syntaxique du triplet (les prédicats sont vérifiés syntaxiquement)
			if(gener.compare($2.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de AFF " << $2.precondition.affirmation << " est différente de " << gener << endl;
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
				cout << "[ERREUR][SYNTAXIQUE] Les programmes de SEQ sont incorrects : " << $2.programme.contenu << " est différent de " << $3.programme.contenu + ";" + $4.programme.contenu  << endl;
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
				// Valeur booléenne de la précondition de la conclusion comparée à la valeur booléenne de la précondition de la prémisse
				if($2.precondition.valeur != $3.precondition.valeur)
				{
					cout << "[ATTENTION][SEMANTIQUE] La précondition de la conclusion " << $2.precondition.affirmation << " n'implique peut-être pas la précondition de la prémisse " << $3.precondition.affirmation << endl;
				}
			}
			// Si les postcondition sont différentes alors on check si elles sont conséquences
			if($2.postcondition.affirmation.compare($3.postcondition.affirmation) != 0)
			{				
				// Valeur booléenne du programme et de la postcondition de la prémisse comparée à la valeur booléenne de la postcondition de la conclusion
				if($3.postcondition.valeur != $2.postcondition.valeur)
				{
					cout << "[ATTENTION][SEMANTIQUE] La postcondition de la prémisse " << $3.postcondition.affirmation << " n'implique peut-être pas la postcondition de la conclusion " << $2.postcondition.affirmation << endl;
				}
			}
			$$ = $2; // copie les prédicats et les programmes
			/*
			[ATTENTION] Limite de l'analyse : on ne peut pas automatiquement savoir si une formule en implique une autre.
			Comparer l'égalité de la valeur booléenne de chaque formule implique d'avoir repéré tous les cas où une formule est fausse (rendue fausse par deux conditions).
			Or, certaines conditions ne peuvent êtres vérifiées si elles ne sont pas composées que d'entiers :
			x>=y^x<=z => false si y>z (y et z entiers)
			x>y^x<z => false si y>=z (y et z entiers)
			x=y^x=z => false si y!=z
			Nous n'avons automatisé que les cas où une formule contient une condition et sa négation et où une formule contient le token faux.
			*/
		}
	| WHILE Triplet Regle
		{
			//  Postcondition de la conclusion comparée avec NON B et I de la conclusion 
			if($2.postcondition.affirmation.compare($2.programme.tantque.negation + "^" + $2.precondition.affirmation))
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la conclusion de WHILE " << $2.postcondition.affirmation << " est différente de " << $2.programme.tantque.negation << "^" << $2.precondition.affirmation << endl;
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
			$$ = $2; // copie les prédicats et les programmes
		}
	| WHILET Triplet Regle
		{
			// Postcondition de la conclusion comparée avec NON B et I de la conclusion 
			if($2.postcondition.affirmation.compare($2.programme.tantque.negation + "^" + $2.precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de WHILET " << $2.postcondition.affirmation << " est différente de " << $2.programme.tantque.negation << "^" << $2.precondition.affirmation << endl;
			}
			// Précondition de la prémisse contient avec I et B de la conclusion
			if($3.precondition.affirmation.find($2.precondition.affirmation) == -1 && $3.precondition.affirmation.find($2.programme.tantque.affirmation) == -1)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILET " << $3.precondition.affirmation << " ne contient pas la précondition de la conclusion " << $2.precondition.affirmation << " ou la condition de la conclusion " << $2.programme.tantque.affirmation << endl;
			}
			string premPrec = $3.precondition.affirmation;
			premPrec.erase(0, $2.precondition.affirmation.length()+1+$2.programme.tantque.affirmation.length()+1);
			string variantVariable = "";
			string variantValeur = "";
			if(premPrec == "")
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILET " << $3.precondition.affirmation << " ne contiennent pas de variant de boucle" << endl;
			}
			else
			{
				variantVariable = variable(premPrec);
				variantValeur = premPrec;
			}
			if(variantVariable.compare("") == 0 || variantValeur.compare("") == 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le variant de boucle de WHILET " << variantVariable << "=" << variantValeur << " n'est pas correct" << endl;
			}
			// Postcondition de la prémisse contient la précondition de la conclusion
			if($3.postcondition.affirmation.compare($2.precondition.affirmation + "^" + variantVariable + "<" + variantValeur) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la prémisse de WHILET " << $3.precondition.affirmation << " est différent de " << $2.precondition.affirmation << "^" << variantVariable << "<" << variantValeur << endl;
			}
			// Programme FAIRE de la conclusion comparé avec le programme de la prémisse
			if($2.programme.faire.compare($3.programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de WHILET " << $2.programme.faire << " est différent du programme de la prémisse " << $3.programme.contenu << endl;
			}
			$$ = $2; // copie les prédicats et les programmes
		}
	;
	
Triplet:
	Predicat Programme Predicat
		{
			$$.precondition = $1;
			$$.programme = $2;
			$$.postcondition = $3;
			// Le seul triplet invalide est de la forme {vrai} ... {faux}
			if($$.precondition.valeur == true && $$.postcondition.valeur == false)
			{
				cout << "[ATTENTION][SEMANTIQUE] Le triplet {" << $$.precondition.affirmation << "} prog {" << $$.postcondition.affirmation << "} n'est peut-être pas valide : ";
				cout << $$.precondition.affirmation << "->" << $$.postcondition.affirmation << "=faux : " << endl;
			}
			
			// Correction partielle :
			// Si la précondition est vraie pour tout état initial vérifiant la précondition et si l'exécution du programme se termine
			// Alors la précondition est vraie après l'exécution du programme
			// Correction totale :
			// Si la précondition est vraie pour tout état initial vérifiant la précondition
			// Alors l'exécution du programme se termine et la précondition est vraie après l'exécution du programme
			
			/*
			[ATTENTION] Limite de l'analyse : on ne peut pas automatiquement savoir si un triplet est valide.
			Nous ne pouvons pas vérifier la correction partielle et la correction totale d'un triplet (l'axiome AFF permet de vérifier syntaxiquement à défaut de pouvoir vérifier sémantiquement).
			*/
		}
	| Predicat ProgrammeCompose Predicat
		{
			$$.precondition = $1;
			$$.programme = $2;
			$$.postcondition = $3;
			// Le seul triplet invalide est de la forme {vrai} ... {faux}
			if($$.precondition.valeur == true && $$.postcondition.valeur == false)
			{
				cout << "[ATTENTION][SEMANTIQUE] Le triplet {" << $$.precondition.affirmation << "} prog {" << $$.postcondition.affirmation << "} n'est peut-être pas valide : ";
				cout << $$.precondition.affirmation << "->" << $$.postcondition.affirmation << "=faux : " << endl;
			}
		}
	;
	
Predicat:
	ACCOLADE_OUVRANTE Conditions ACCOLADE_FERMANTE
		{
			$$ = $2;
		}
	| ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
		{
			$$.valeur = true;
		}
	;
	
Conditions:
	Condition ET Conditions
		{
			$$.affirmation = $1.affirmation + "^" + $3.affirmation;
			$$.negation = $1.negation + "^" + $3.negation;
			$$.valeur = $1.valeur && $3.valeur;
			
			// Une formule qui contient une condition et sa négation est fausse
			int pos = ($$.affirmation.find($1.negation));
			if(pos > -1) {
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
	| VRAI
		{
			$$.affirmation = "vrai";
			$$.negation = "faux";
			$$.valeur = true;
		}
	| FAUX
		{
			$$.affirmation = "faux";
			$$.negation = "vrai";
			$$.valeur = false;
		}
	;
	
 Comparaison:
	ExpressionEntier INF ExpressionEntier
		{
			$$.affirmation = $1.chaine + "<" + $3.chaine;
			$$.negation = $1.chaine + ">=" + $3.chaine;
			$$.valeur = $1.valeur < $3.valeur;
		}
	| ExpressionEntier SUP ExpressionEntier
		{
			$$.affirmation = $1.chaine + ">" + $3.chaine;
			$$.negation = $1.chaine + "<=" + $3.chaine;
			$$.valeur = $1.valeur > $3.valeur;
		}
	| ExpressionEntier INF_EGAL ExpressionEntier
		{
			$$.affirmation = $1.chaine + "<=" + $3.chaine;
			$$.negation = $1.chaine + ">" + $3.chaine;
			$$.valeur = $1.valeur <= $3.valeur;
		}
	| ExpressionEntier SUP_EGAL ExpressionEntier
		{
			$$.affirmation = $1.chaine + ">=" + $3.chaine;
			$$.negation = $1.chaine + "<" + $3.chaine;
			$$.valeur = $1.valeur >= $3.valeur;
		}
	| ExpressionEntier EGAL ExpressionEntier
		{
			$$.affirmation = $1.chaine + "=" + $3.chaine;
			$$.negation = $1.chaine + "!=" + $3.chaine;
			$$.valeur = $1.valeur == $3.valeur;
		}
	| ExpressionMot		INF			Expression			{ $$.affirmation = $1.chaine + "<" + $3.chaine; 		$$.negation = $1.chaine + ">=" + $3.chaine;		$$.valeur = true; }
	| ExpressionMot		SUP			Expression			{ $$.affirmation = $1.chaine + ">" + $3.chaine;			$$.negation = $1.chaine + "<=" + $3.chaine;		$$.valeur = true; }
	| ExpressionMot		INF_EGAL	Expression			{ $$.affirmation = $1.chaine + "<=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine; 		$$.valeur = true; }
	| ExpressionMot		SUP_EGAL	Expression			{ $$.affirmation = $1.chaine + ">=" + $3.chaine;		$$.negation = $1.chaine + "<" + $3.chaine; 		$$.valeur = true; }    
	| ExpressionMot		EGAL		Expression			{ $$.affirmation = $1.chaine + "=" + $3.chaine;			$$.negation = $1.chaine + "!=" + $3.chaine;		$$.valeur = true; }
	| ExpressionEntier	INF			ExpressionMot		{ $$.affirmation = $1.chaine + "<" + $3.chaine; 		$$.negation = $1.chaine + ">=" + $3.chaine;		$$.valeur = true; }
	| ExpressionEntier	SUP			ExpressionMot		{ $$.affirmation = $1.chaine + ">" + $3.chaine; 		$$.negation = $1.chaine + "<=" + $3.chaine;		$$.valeur = true; }
	| ExpressionEntier	INF_EGAL	ExpressionMot		{ $$.affirmation = $1.chaine + "<=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine; 		$$.valeur = true; }
	| ExpressionEntier	SUP_EGAL	ExpressionMot		{ $$.affirmation = $1.chaine + ">=" + $3.chaine;		$$.negation = $1.chaine + ">" + $3.chaine; 		$$.valeur = true; }
	| ExpressionEntier	EGAL		ExpressionMot		{ $$.affirmation = $1.chaine + "=" + $3.chaine; 		$$.negation = $1.chaine + "!=" + $3.chaine;		$$.valeur = true; }
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
	| ENTIER MOINS ExpressionMot
		{
			$$.chaine = $1.chaine + "-" + $3.chaine;
		}
	| ENTIER FOIS ExpressionMot
		{
			$$.chaine = $1.chaine + "*" + $3.chaine;
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
	;
	
ProgrammeCompose:
	Conditions Programme Programme
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
	MOT AFFECTATION Expression
		{
			$$.variable = $1.chaine;
			$$.valeur = $3.chaine;
		}
	;
	
%%

void yyerror(const string& mess) {
  cerr << "[ERREUR][YYERROR] " << mess << endl;
  cout << "[ERREUR] Erreur de syntaxe" << endl;
}

int main(int argc, char **argv) {
	// Lecture du fichier si envoyé
	if(argc == 2) {
		yyin = fopen(argv[1], "r");
		// cout << "\nFichier utilisé\nLecture de la preuve" << endl;
	}
		
	// Verification de la preuve
	yyparse();
		
	// Fin de la vérification de la preuve
	// cout << "Preuve lue en entier\nPreuve vérifiée si pas de message d'erreur" << endl;

	return EXIT_SUCCESS;
}