typedef struct s_entier {
	char *chaine;
	int valeur;
} t_entier;

typedef struct s_typespe {
	char* chaine;
	t_entier entier;
} typespe;	

#define YYSTYPE typespe
extern YYSTYPE yylval;
