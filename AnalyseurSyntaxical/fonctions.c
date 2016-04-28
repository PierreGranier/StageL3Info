// Retourne vrai si les deux chaines sont équivalentes, faux sinon
boolean sont_egales(char* chaine1, char* chaine2)
{
	return !strcmp(chaine1, chaine2);
}

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

// Remplace dans la chaine donnée les occurrences d'une chaine par une autre chaine
char* remplacer(const char* chaine, const char* souschaine)
{
	return str_remplace(chaine, 0, strlen(souschaine), souschaine);
}

//virer le main + les includes

int main()
{
    char ch[] = "Bonjour les potes";
	printf("Avant replace : %s\n", ch);
    char *new = remplacer(ch, 0, 7, "Salut");
    printf("Après replace : %s\n", new);
    return 0;
}
