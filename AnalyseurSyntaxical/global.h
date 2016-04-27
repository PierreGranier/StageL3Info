typedef struct s_entier {
	char *chaine;
	int valeur;
} t_entier;

typedef struct s_triplet {
	char * precondition;
	char * programme;
	char * postcondition;
} t_triplet;

typedef struct s_typespe {
	char* chaine;
	t_entier entier;
	t_triplet triplet;
} typespe;	

#define YYSTYPE typespe
extern YYSTYPE yylval;
