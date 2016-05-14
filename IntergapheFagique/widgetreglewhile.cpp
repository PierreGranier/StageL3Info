#include "widgetreglewhile.h"

using namespace std;

WidgetRegleWhile::WidgetRegleWhile(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILE");
	
	m_ajouter = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouter, 0, 1, 1, 2);
}


WidgetRegleWhile::~WidgetRegleWhile()
{
    // delete(m_top);
}

string WidgetRegleWhile::toString()
{
 	// return " " + m_conclusion + " " + m_premisse;
	return "";
}