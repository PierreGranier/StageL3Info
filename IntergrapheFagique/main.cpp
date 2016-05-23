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
		fiche de voeux de M1
		Améliorer le texte des onglets aide et tout
		l'affichage des imagines z est dfaubée il fau la réparzerée (fin de semina, jean é mar)
		
*/
