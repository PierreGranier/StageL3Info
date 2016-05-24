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
<<<<<<< HEAD
		FINI lol
		
=======
		Aff.cpp : rajouter un WidgetSupprimer
>>>>>>> 86fd54812f895f694551bb9dfc87d7284b8a110d
*/
