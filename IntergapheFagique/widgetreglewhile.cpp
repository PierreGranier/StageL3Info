#include "widgetreglewhile.h"

using namespace std;

WidgetRegleWhile::WidgetRegleWhile(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILE");
	
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 1);
	m_grid->addWidget(m_premisse, 1, 1);
}

WidgetRegleWhile::~WidgetRegleWhile()
{
	
}

string WidgetRegleWhile::toString()
{
 	// return " " + m_premisse.toString() + " " + m_souspreuve.toString();
	return "";
}