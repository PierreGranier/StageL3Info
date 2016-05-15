#include "widgetregleseq.h"

using namespace std;

WidgetRegleSeq::WidgetRegleSeq(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("SEQ");
	
	m_premisseG = new WidgetTriplet(this);
	m_premisseD = new WidgetTriplet(this);
	
	m_ajouterG = new WidgetAjouter(this);
	m_ajouterD = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouterG, 0, 1);
	m_grid->addWidget(m_ajouterD, 0, 2);
	m_grid->addWidget(m_premisseG, 1, 1);
	m_grid->addWidget(m_premisseD, 1, 2);
}

WidgetRegleSeq::~WidgetRegleSeq()
{
	
}

string WidgetRegleSeq::toString()
{
 	// return " " + m_premisseG.toString() + " " + m_premisseD.toString() + " " + m_brancheG.toString() + " " + m_brancheD.toString();
	return "";
}