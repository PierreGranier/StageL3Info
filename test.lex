%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "test.h"


%}

regle AFF|SEQ

separateurs [ \t]

Mot [A-z]+

Op_Comparaison [<>][=]?



%%

"fini"	{return (FINFINALE); }

{separateurs} 	{/*ignoré*/}

{regle} {
			printf("\nLex : vous avez mis une règle (%s)\n", yytext);
			yylval.chaine = yytext;
			return(REGLE); // ce type REGLE est défini dans .y
		}
		
"<="	{
				return(INF_EGALE);
			}

">="	{
				return(SUP_EGALE);
			}
		
{Op_Comparaison} {
				printf("\nLex : Comp (%s)\n", yytext);
				yylval.chaine = yytext;
				return(OP_COMPARAISON);
			}
{Mot} {
			printf("\nLex : Mot (%s)\n", yytext);
			yylval.chaine = yytext;
			return(MOT);
			}

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

