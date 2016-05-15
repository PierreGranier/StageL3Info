#include "widgetregleconseq.h"

using namespace std;

WidgetRegleConseq::WidgetRegleConseq(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("CONSEQ");
	
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 1);
	m_grid->addWidget(m_premisse, 1, 1);
}

WidgetRegleConseq::~WidgetRegleConseq()
{
	
}

string WidgetRegleConseq::toString()
{
 	// return " " + m_premisse.toString() + " " + m_souspreuve.toString();
	return "";
}