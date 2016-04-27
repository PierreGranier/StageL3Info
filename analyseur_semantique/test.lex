%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "test.tab.h"
%}

separateurs [ \t]
mot [A-z]+
entier [0-9]+
op_comparaison [<>][=]?
fin	"fini"|"fin"|"j'ai tout fini"

%%

{separateurs} 	{ /* ignoré */ 				 }
"\n"			{ return(FIN);		  	 	 }
{fin}			{ return(FINFINALE); 		 }
"AFF" 			{ return(AFF);  			 }
"SEQ" 			{ return(SEQ); 				 }
"{"				{ return(ACCOLADE_OUVRANTE); }
"}"				{ return(ACCOLADE_FERMANTE); }
":=" 			{ return(AFFECTATION); 		 }
";"				{ return(POINTVIRGULE);		 }
"<="			{ return(INF_EGAL);			 }
">="			{ return(SUP_EGAL); 		 }
"<"				{ return(INF); 				 }
">"				{ return(SUP); 				 }
"^"				{ return(ET);				 }
"="				{ return(EGAL);				 }
"+"				{ return(PLUS);				 }
"-"				{ return(MOINS);			 }
"*"				{ return(FOIS);				 }

{entier} {
			yylval.chaine = strdup(yytext);
			return(ENTIER);
		 }

{mot} 	{
			yylval.chaine = strdup(yytext);
			return(MOT);
		}

%{
int main(int argc, char **argv) {
	yylex();
	
	if(argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
}
%}

