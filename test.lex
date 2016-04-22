%option nounput
%option yylineno

%{
#include <stdio.h>

#include "global.h"
#include "test.h"


%}

%%regle AFF|SEQ|CONSEQ|WHILE|WHILET

separateurs [ \t]

%%

"fini"	{ return (FINFINALE); }

{separateurs} 	{ /*ignoré*/ }

"AFF" {	return(AFF); }
"SEQ" {	return(SEQ); }
":=" { return(AFFECTATION); }
"PRECONDITION" { return(PRECONDITION); }
"POSTCONDITION" { return(PRECONDITION); }
"PREMISSE" { return(PREMISSE); }
"CONSEQUENCE" { return(CONSEQUENCE); }
"PROGRAMME" { return(PROGRAMME); }

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

