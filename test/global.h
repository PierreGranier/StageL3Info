typedef char boolean;

typedef struct s_typespe {
	char * chaine;
	int valEntiere;
	boolean valBool;
} typespe;

#define YYSTYPE typespe
extern YYSTYPE yylval;
