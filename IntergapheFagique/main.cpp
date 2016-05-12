#include "mainwindow.h"
#include "widgetajouter.h"
#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	
	/*MainWindow *fenetre = new MainWindow();
	fenetre->show();*/
	
	QWidget *top = new QWidget(0);
	WidgetAjouter *afficher = new WidgetAjouter(top);
	afficher->show();
	
	WidgetRegleAff *aff = new WidgetRegleAff(top);
	aff->show();
	
	WidgetRegleSeq *seq = new WidgetRegleSeq(top);
	seq->show();
	
	WidgetRegleCond *cond = new WidgetRegleCond(top);
	cond->show();
	
	return app.exec();
}
