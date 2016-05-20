#include "widgetsupprimer.h"

WidgetSupprimer::WidgetSupprimer(QWidget *parent) : QPushButton("X", parent)
{
	this->setMaximumWidth(30);
}

WidgetSupprimer::~WidgetSupprimer()
{
	
}