#ifndef preuvelineaire_h
#define preuvelineaire_h

#include <iostream>
#include <string>

class PreuveLineaire
{
	private:
		std::string m_contenu;
	
	public:
		PreuveLineaire(std::string const &chaine) { m_contenu = chaine; };
		~PreuveLineaire() {};
		
		bool vide() const { return m_contenu.empty(); };
		bool commencePar(std::string const &chaine) const { return m_contenu.find(chaine+" ") == 0 || m_contenu.find(" "+chaine+" ") == 0; };
		std::string triplet() const {
			std::string tmp = m_contenu;
			std::string res = "";
			res += tmp.substr(tmp.find('{'), tmp.find(':')-tmp.find('{')+1); tmp.erase(tmp.find('{'), tmp.find(':')-tmp.find('{')+1);
			res += tmp.substr(tmp.find('='), tmp.find('}')-tmp.find('=')+1); tmp.erase(tmp.find('='), tmp.find('}')-tmp.find('=')+1);
			return res; };
		void tronquerRegle() { m_contenu.erase(0, m_contenu.find('{')); };
		void tronquerTriplet() { m_contenu.substr(m_contenu.find('{'), m_contenu.find(':')); m_contenu.substr(m_contenu.find('='), m_contenu.find('}')); };
		std::string toString() { return m_contenu; };
};

#endif