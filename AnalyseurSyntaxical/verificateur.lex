%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "verificateur.tab.h"

extern "C" int yylex(void);

%}

separateurs [ \t]
entier [0-9]+
mot [A-z]+
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
			yylval.entier.chaine = strdup(yytext);
			yylval.entier.valeur = atoi(yytext);
			return(ENTIER);
		 }

{mot} 	{
			yylval.chaine = strdup(yytext);
			return(MOT);
		}

%%