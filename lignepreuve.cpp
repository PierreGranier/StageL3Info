#include "lignepreuve.h"

using namespace std;

LignePreuve::LignePreuve(string const & ligne) : m_contenu(ligne)
{
	this->formater();
}

LignePreuve::~LignePreuve()
{}

bool LignePreuve::contient(string const & souschaine) const
{
	return m_contenu.find(souschaine) >= 0 && m_contenu.find(souschaine) < m_contenu.length();
}

int LignePreuve::occurences(string const & souschaine) const
{
	string tmp = m_contenu;
	int occ = 0;
	
	while(tmp.find(souschaine) >= 0 && tmp.find(souschaine) < tmp.length()) {
		int pos = tmp.find(souschaine);
		tmp = tmp.substr(pos+1);
		occ++;
	}
	
	return occ;
}

void LignePreuve::remplacer(string const & souschaine1, string const & souschaine2) {
	int occ = this->occurences(souschaine1);
	int pos = m_contenu.find(souschaine1);
	for(int i=0; i<occ; i++) {
		m_contenu.replace(pos, souschaine1.length(), souschaine2);
		pos = m_contenu.find(souschaine1);
	}
}

void LignePreuve::formater() {
	this->remplacer(" ", "");
}
