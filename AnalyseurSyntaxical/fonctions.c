// Retourne vrai si les deux chaines sont équivalentes, faux sinon
/*boolean sont_egales(char* chaine1, char* chaine2)
{
	return !strcmp(chaine1, chaine2);
}

// Retourne vrai si la chaine commence par la sous chaine, faux sinon
boolean commence_par(const char* chaine, const char* souschaine)
{
	unsigned int i = 0;
	do
	{
		if(chaine[i] != souschaine[i]) return false;
		i++;
	}
	while(souschaine[i] != '\0');
	return true;
}

// Tronque la chaine de l'indice 0 à un indice donné
char* tronquer(char* chaine, int indice_fin)
{
	char res[strlen(chaine)-indice_fin];
	unsigned int i = indice_fin;
	do
	{
	  res[i-indice_fin] = chaine[i];
		i++;
	}	while(i < strlen(chaine));
	strcpy(chaine, res);
	return chaine;
}

// Remplace dans la chaine donnée les occurrences d'une chaine par une autre chaine
char* remplacer(char* chaine, const char* souschaine1, const char* souschaine2)
{
	char res[strlen(chaine)*strlen(souschaine2)];
	unsigned int i = 0;
	do {
		if(commence_par(chaine, souschaine1)) {
			strcat(res, souschaine2);
			printf("On copie '%s'\n", souschaine2, chaine);
			tronquer(chaine, strlen(souschaine1));
			i += strlen(souschaine2);
		}
		else {
			sprintf(res, "%s%c", res, chaine[0]);
			printf("On copie '%c' de '%s'\n", chaine[0], chaine);
			tronquer(chaine, 1);
			i += 1;
		}
		//printf("chaine = %s | res = %s\n", chaine, res);
	} while(i < strlen(chaine));
	strcpy(chaine, res);
	return chaine;
}*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* str_remplace (const char *s, unsigned int start, unsigned int lenght, const char *ct)
{
   char *new_s = NULL;

   if (s != NULL && ct != NULL && start >= 0 && lenght > 0)
   {
      size_t size = strlen (s);

      new_s = malloc (sizeof (*new_s) * (size - lenght + strlen (ct) + 1));
      if (new_s != NULL)
      {
         memcpy (new_s, s, start);
         memcpy (&new_s[start], ct, strlen (ct));
         memcpy (&new_s[start + strlen (ct)], &s[start + lenght], size - lenght - start + 1);
      }
   }
   else
   {
      fprintf (stderr, "Memoire insuffisante\n");
      exit (EXIT_FAILURE);
   }
   return new_s;
}

//virer le main + les includes

int main()
{
    char ch[] = "Bonjour les potes";
	printf("Avant replace : %s\n", ch);
    char *new = str_remplace(ch, 0, 7, "Salut");
    printf("Après replace : %s\n", new);
    return 0;
}
