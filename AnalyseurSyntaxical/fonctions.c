bool operateur(char const & caractere) {
	return caractere == '<' || caractere == '>' || caractere == '=';
}

bool separateur(char const & caractere) {
	return caractere == '\0' || caractere == '^';
}

int position(string const & chaine, string const & souschaine) {
	// Objectif : éviter les remplacements de sous chaines dans des mots. Exemple : les chaines "false", "ab>5", etc... ne doivent pas être affectées par le remplacement de la sous chaine "a"
	// Retourne la position de la sous chaine ssi elle est en début ou fin de chaine ou adjascente à un symbole
	int pos = chaine.find(souschaine);
	if(pos > -1) {
		if(( separateur(chaine[pos-1]) && operateur(chaine[pos+souschaine.length()]) ) // sous chaine entre séparateur et opérateur
		|| ( operateur(chaine[pos-1]) && separateur(chaine[pos+souschaine.length()]) ))// sous chaine entre opérateur et séparateur
		{
			return pos; // remplacement autorisé
		}
	}
	return -1; // remplacement interdit
}

bool contient(string const & chaine, string const & souschaine) {
	return position(chaine, souschaine) >= 0 && chaine.find(souschaine) < chaine.length();
}

int occurences(string const & chaine, string const & souschaine) {
	if(contient(chaine, souschaine)) {
		int pos = position(chaine, souschaine);
		return 1 + occurences(chaine.substr(pos+1), souschaine);
	}
	return 0;
}

void remplacer(string & chaine, string const & souschaine1, string const & souschaine2) {
	int occ = occurences(chaine, souschaine1);
	int pos = position(chaine, souschaine1);
	for(int i=0; i<occ; i++) {
		chaine.replace(pos, souschaine1.length(), souschaine2);
		pos = position(chaine, souschaine1);
	}
}

// Enlève et retourne la première variable affectée de la chaine
// Avant : a:=b   Après : b   Retourné : a
string variable(string & chaine) {
	string var = "";
	int i = 0;
	while(chaine[i] != ':' && chaine[i+1] != '=') {
        var += chaine[i];
        i++;
    }
    chaine.erase(0, i+2);
	return var;
}