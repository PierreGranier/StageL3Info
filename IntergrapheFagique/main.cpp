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
		changer les images d'aide
		Refaire le logo (en vrai il est pas mal. Il est smooth toussa toussa)
*/
