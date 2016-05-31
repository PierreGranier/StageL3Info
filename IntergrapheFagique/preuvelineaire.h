#ifndef preuvelineaire_h
#define preuvelineaire_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
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
		bool erreur() { return m_contenu.find('{') == std::string::npos || m_contenu.find('}') == std::string::npos || m_contenu.find(':') == std::string::npos || m_contenu.find('=') == std::string::npos; };
		bool commencePar(std::string const &chaine) const { return m_contenu.find(chaine+" ") == 0 || m_contenu.find(" "+chaine+" ") == 0 || m_contenu.find("  "+chaine+" ") == 0; };
		std::string triplet() {
			if(!erreur()) {
				std::string tmp = m_contenu;
				std::string res1, res2;
				res1 = tmp.substr(tmp.find('{'), tmp.find(':')-tmp.find('{')+1); tmp.erase(tmp.find('{'), tmp.find(':')-tmp.find('{')+1);
				res2 = tmp.substr(tmp.find('='), tmp.find('}')-tmp.find('=')+1); tmp.erase(tmp.find('='), tmp.find('}')-tmp.find('=')+1);
				return res1+res2;
			}
			erreurLecturePreuve();
			return "";
		};
		void tronquerRegle() {
			if(!erreur()) {
				m_contenu.erase(0, m_contenu.find('{'));
			}
		};
		void tronquerTriplet() {
			if(!erreur()) {
				m_contenu.erase(m_contenu.find('{'), m_contenu.find(':')-m_contenu.find('{')+1);
				m_contenu.erase(m_contenu.find('='), m_contenu.find('}')-m_contenu.find('=')+1);
			}
		};
		void erreurLecturePreuve() {
			QMessageBox *popup = new QMessageBox(0);
			popup->setIcon(QMessageBox::Critical);
			popup->setText("La preuve ne peut être lue. Erreur de syntaxe.\n\n" + QString::fromStdString(m_contenu));
			popup->exec();
			m_contenu = "";
		};
		std::string toString() { return m_contenu; };
};

#endif