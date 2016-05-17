#include "widgetreglesimple.h"

using namespace std;

WidgetRegleSimple::WidgetRegleSimple(const string &nomRegle, QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText(QString::fromStdString(nomRegle));
	
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 1);
	m_grid->addWidget(m_premisse, 1, 1);
}

WidgetRegleSimple::~WidgetRegleSimple()
{
	
}

string WidgetRegleSimple::toString()
{
 	// return " " + m_premisse.toString() + " " + m_souspreuve.toString();
	return "";
}