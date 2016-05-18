#include "QtWidgets/QtWidgets"
#include "mainwindow.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	MainWindow *fenetre = new MainWindow();
	fenetre->show();
	
	return app.exec();
}

/*

	TODO tout courre
	Bouton supprimer
	ajuster les espaces/alignements des widgets ajoutés
	fiche de voeux de M1
	terminer le bouton validation (vérifier que les toString fonctionnent)
	faire un onglet aide dans le menu pour connaître la structure d'un triplet et tout ça
*/
