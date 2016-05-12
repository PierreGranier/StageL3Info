#include "widgetregleconseq.h"

using namespace std;

WidgetRegleConseq::WidgetRegleConseq(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("CONSEQ");
	
	m_premisse = new QLineEdit(m_top);
	
	m_grid->addWidget(m_premisse, 0, 1, 1, 2);
}

WidgetRegleConseq::~WidgetRegleConseq()
{
    // delete m_top;
}

string WidgetRegleConseq::toString()
{
	return "";
	// return le tostring des LineEdit
}