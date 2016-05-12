#include "QtWidgets/QtWidgets"
#include "mainwindow.h"
#include "widgetajouter.h"
#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	MainWindow *fenetre = new MainWindow();
	fenetre->show();
	
	return app.exec();
}
