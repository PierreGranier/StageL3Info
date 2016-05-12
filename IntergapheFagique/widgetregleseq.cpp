#include "widgetregleseq.h"

using namespace std;

WidgetRegleSeq::WidgetRegleSeq(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("SEQ");
	
	m_premisseG = new QLineEdit(m_top);
	m_premisseD = new QLineEdit(m_top);
	
	m_grid->addWidget(m_premisseG, 0, 1);
	m_grid->addWidget(m_premisseD, 0, 2);
}

WidgetRegleSeq::~WidgetRegleSeq()
{
	// delete m_top;
}

string WidgetRegleSeq::toString()
{
	return "";
	// return le tostring des LineEdit
}