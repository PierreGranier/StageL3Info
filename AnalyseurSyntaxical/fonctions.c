boolean sont_egales(char* chaine1, char* chaine2)
{
	return !strcmp(chaine1, chaine2);
}

strcmp !!

boolean contient(const char* & chaine, const char* & souschaine) {
	return ??(chaine, souschaine) >= 0 && ??(chaine, souschaine) < strlen(chaine);
}

int occurences(const & chaine, string const & souschaine) {
	if(contient(chaine, souschaine)) {
		int pos = chaine.find(souschaine);
		return 1 + occurences(chaine.substr(pos+1), souschaine);
	}
	return 0;
}

void remplacer(string & chaine, string const & souschaine1, string const & souschaine2) {
	int occ = occurences(chaine, souschaine1);
	int pos = chaine.find(souschaine1);
	for(int i=0; i<occ; i++) {
		chaine.replace(pos, souschaine1.length(), souschaine2);
		pos = chaine.find(souschaine1);
	}
}