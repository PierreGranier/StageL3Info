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
	fiche de voeux de M1
	écrire le résultat du bouton valider dans un fichier et le passer à l'analyseur syntaxical
	faire un onglet aide dans le menu pour connaître la structure d'un triplet et tout ça
	corriger le QSplitter (c'est à Thibaut de le faire paske c lui ka komenC, C son ID)
*/
