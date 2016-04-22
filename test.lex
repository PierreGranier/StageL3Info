%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "test.tab.h"
%}

separateurs [ \t]
mot [A-z]+
op_comparaison [<>][=]?

%%

"\n"	{ return (FIN); 	  }
"fini"	{ return (FINFINALE); }

{separateurs} 	{ /* ignoré */ }

"AFF" 			{ return(AFF);  			 }
"SEQ" 			{ return(SEQ); 				 }
":=" 			{ return(AFFECTATION); 		 }
"PREMISSE" 		{ return(PREMISSE); 		 }
"CONSEQUENCE" 	{ return(CONSEQUENCE); 		 }
"<="			{ return(INF_EGAL);			 }
">="			{ return(SUP_EGAL); 		 }
"<"				{ return(INF); 				 }
">"				{ return(SUP); 				 }
"{"				{ return(ACCOLADE_OUVRANTE); }
"}"				{ return(ACCOLADE_FERMANTE); }
		

{mot} 	{
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

