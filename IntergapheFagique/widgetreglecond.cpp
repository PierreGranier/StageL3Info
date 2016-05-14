#include "widgetreglecond.h"

using namespace std;

WidgetRegleCond::WidgetRegleCond(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("COND");
	
	m_ajouterG = new WidgetAjouter(m_top);
	m_ajouterD = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouterG, 0, 1);
	m_grid->addWidget(m_ajouterD, 0, 2);
}

WidgetRegleCond::~WidgetRegleCond()
{
	// delete m_top;
}

string WidgetRegleCond::toString()
{
 	// return " " + m_conclusion + " " + m_premisseG + " " + m_premisseD;
	return "";
}