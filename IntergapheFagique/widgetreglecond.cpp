#include "widgetreglecond.h"

using namespace std;

WidgetRegleCond::WidgetRegleCond(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("COND");
	
	m_premisseG = new QLineEdit(m_top);
	m_premisseD = new QLineEdit(m_top);
	
	m_grid->addWidget(m_premisseG, 0, 1);
	m_grid->addWidget(m_premisseD, 0, 2);
}

WidgetRegleCond::~WidgetRegleCond()
{
	// delete m_top;
}

string WidgetRegleCond::toString()
{
	return "";
	// return le tostring des LineEdit
}