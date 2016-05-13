#include "widgetregleconseq.h"

using namespace std;

WidgetRegleConseq::WidgetRegleConseq(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("CONSEQ");
	
	m_ajouter = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouter, 0, 1, 1, 2);
}

WidgetRegleConseq::~WidgetRegleConseq()
{
    // delete m_top;
}

string WidgetRegleConseq::toString()
{
 	return " " + m_conclusion + " " + m_premisse;
}