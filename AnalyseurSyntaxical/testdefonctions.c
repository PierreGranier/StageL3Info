#include "fonsouschaineions.c"
#include <string.h>
#include <stdio.h>

#define false	0
#define true 	1
typedef char boolean;

int main()
{
    char ch[] = "Bonjour les potes";
    remplacer(ch, "Bonjour", "Salut");
    printf("%s\n", ch);
    return 0;
}


/*
int position(const char *chaine, const char *souschaine)
{
    int index = -1;
    char *premiere_occurrence = NULL;
    premiere_occurrence = strstr (chaine, souschaine);
    
    if (premiere_occurrence != NULL)
    {
        index = premiere_occurrence - chaine;
    }

    return index;
}

char* remplacer(char* chaine, const char* souschaine1, const char* souschaine2)
{
    int x = position(chaine, souschaine1);
    char * res = NULL;
    res = malloc(sizeof(*res) * (strlen(chaine)*strlen(souschaine2)));
    char * tmp = NULL;
    
    while(x > -1) {
        tmp = malloc(sizeof(*res) * (strlen(chaine)*strlen(souschaine2)));
        // copier dans tmp la partie de chaine qui va de 0 à la première occurrence de souschaine1
        strncpy(tmp, chaine, x);
        // copier dans tmp la souschaine de remplacement
        strcpy(tmp, souschaine2);
        x = position(chaine, souschaine1);
        // remplacer ?
    }
    return tmp;
}
*/