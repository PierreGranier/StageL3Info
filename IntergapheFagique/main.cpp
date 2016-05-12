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
	
	QHBoxLayout *grid = new QHBoxLayout(top);
	
	WidgetAjouter *afficher = new WidgetAjouter(top);
	WidgetRegleAff *aff = new WidgetRegleAff(top);
	WidgetRegleSeq *seq = new WidgetRegleSeq(top);
	WidgetRegleCond *cond = new WidgetRegleCond(top);
	
	grid->addWidget(afficher);
	grid->addWidget(aff);
	grid->addWidget(seq);
	grid->addWidget(cond);
	
	top->show();
	
	return app.exec();
}
