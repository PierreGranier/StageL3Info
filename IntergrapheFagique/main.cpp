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
		FAIS LES CAPTURES DECRAN TARBA POUR LES EXEMPLES MDR
		ok now tu faiT l'icone 3P MDR
*/
