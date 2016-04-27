typedef struct s_entier {
	char *chaine;
	int valeur;
} t_entier;

typedef struct s_instruction {
	char * variable;
	char * valeur;
} t_instruction;

typedef struct s_programme {
	char * contenu;
	t_instruction instruction;
} t_programme;

typedef struct s_triplet {
	char * 		precondition;
	t_programme programme;
	char * 		postcondition;
} t_triplet;

typedef char boolean;

typedef struct s_typespe {
	char* chaine;
	t_entier entier;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;
	boolean valBool;
} typespe;

#define YYSTYPE typespe
extern YYSTYPE yylval;