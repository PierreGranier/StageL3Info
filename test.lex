%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "test.h"


%}

%%regle AFF|SEQ|CONSEQ|WHILE|WHILET

separateurs [ \t]
Mot [A-z]+
Op_Comparaison [<>][=]?

%%

"fini"	{ return (FINFINALE); }

{separateurs} 	{ /*ignoré*/ }

"AFF" {	return(AFF); }
"SEQ" {	return(SEQ); }
":=" { return(AFFECTATION); }
"PRECONDITION" { return(PRECONDITION); }
"POSTCONDITION" { return(POSTCONDITION); }
"PREMISSE" { return(PREMISSE); }
"CONSEQUENCE" { return(CONSEQUENCE); }
"PROGRAMME" { return(PROGRAMME); }
		
"<="	{
				return(INF_EGALE);
			}

">="	{
				return(SUP_EGALE);
			}
"<"		{
				return(INF);
			}

">"		{
				return(SUP);
			}
		

{Mot} {
			printf("\nLex : Mot (%s)\n", yytext);
			yylval.chaine = yytext;
			return(MOT);
			}

%%

%{

int main(int argc, char **argv) {
	yylex();
	
	printf("\nBIENVENUE\n");
	if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
}
%}

