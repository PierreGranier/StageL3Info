#include "QtWidgets/QtWidgets"
#include "mainwindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	/*MainWindow *fenetre = new MainWindow();
	fenetre->show();*/
	
	Container *c = new Container(0);
	c->show();
	
	// TODO
	/*
	Au changement d'un item d'un WidgetAjouter :
	- L'objet créé une instance de WidgetRegle (à faire dans WidgetAjouter pour éviter les includes de tous les sous classes de WidgetRegle dans les WidgetRegle)
		slot (dans la section public) : WidgetRegle *genererWidgetRegle(const QString &nomRegle) NB : nomRegle.toStdString();
		connexion (dans le constructeur de WidgetAjouter) : connect(this, &WidgetAjouter::currentTextChanged, this, &WidgetAjouter::genererWidgetRegle);
	- Remplacement du WidgetAjouter par le WidgetRegle dans le WidgetRegle
		slot (dans chaque règle) : ClassName::ajouterSousPreuve(WidgetRegle *sousPreuve);
		connexion (dans le constructeur de chaque règle) : connect(m_ajouter, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetAjouter::ajouterSousPreuve);
	*/
	
	return app.exec();
}
