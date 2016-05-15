#include "widgetreglewhilet.h"

using namespace std;

WidgetRegleWhileT::WidgetRegleWhileT(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILET");
	
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 1);
	m_grid->addWidget(m_premisse, 1, 1);
}


WidgetRegleWhileT::~WidgetRegleWhileT()
{
	
}

string WidgetRegleWhileT::toString()
{
 	// return " " + m_premisse.toString() + " " + m_souspreuve.toString();
	return "";
}