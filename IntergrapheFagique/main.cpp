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
	Bouton supprimer (à voir/être (mdr))
	fiche de voeux de M1
	Améliorer le texte des onglets aide et tout
	Look at for last errors
*/
