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
mot [a-zA-Z]+
op_comparaison [<>][=]?
finfinale "fini"|"fin"|"j'ai tout fini"|"aye"

%%

{separateurs} 	{ /* ignoré */ 				 }
"\n"			{ return(FIN);		  	 	 }
{finfinale}		{ return(FINFINALE); 		 }
"AFF" 			{ return(AFF);  			 }
"SEQ" 			{ return(SEQ); 				 }
"COND" 			{ return(COND); 			 }
"CONSEQ" 		{ return(CONSEQ); 			 }
"WHILE" 		{ return(WHILE); 			 }
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
			yylval.expression.chaine = strdup(yytext);
			yylval.expression.valeur = atoi(yytext);
			return(ENTIER);
		 }

{mot} 	{
			yylval.expression.chaine = strdup(yytext);
			return(MOT);
		}

%%