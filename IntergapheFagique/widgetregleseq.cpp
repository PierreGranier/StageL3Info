#include "widgetregleseq.h"

using namespace std;

WidgetRegleSeq::WidgetRegleSeq(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("SEQ");
	
	m_ajouterG = new WidgetAjouter(m_top);
	m_ajouterD = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouterG, 0, 1);
	m_grid->addWidget(m_ajouterD, 0, 2);
}

WidgetRegleSeq::~WidgetRegleSeq()
{
	// delete m_top;
}

string WidgetRegleSeq::toString()
{
 	// return " " + m_conclusion + " " + m_premisseG + " " + m_premisseD;
	return "";
}