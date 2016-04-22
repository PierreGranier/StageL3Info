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

%%

{separateurs} 	{ /* ignoré */ }

"\n"			{ return (FIN);		  	 	 }
"fini"			{ return (FINFINALE); 		 }
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
<<<<<<< HEAD
"}"				{ return(ACCOLADE_FERMANTE); }
=======
"}"				{ return(ACCOLADE_FERMANTE); }	

>>>>>>> df2c4d23aa63e80abaec8a46d73e2dff1adbe8a6
{entier} { 
			printf("\nLex : Mot (%s)\n", atoi(yytext));
			yylval.chaine = yytext;
			return (ENTIER) 	
<<<<<<< HEAD
		 }		
=======
		}
>>>>>>> df2c4d23aa63e80abaec8a46d73e2dff1adbe8a6

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

