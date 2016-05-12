#include "mainwindow.h"
#include "widgetregleaff.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	/*MainWindow *fenetre = new MainWindow();
	fenetre->show();*/
	
	WidgetRegleAff *test;
	test = new WidgetRegleAff(0);
	test->show();
	
	return app.exec();
}
