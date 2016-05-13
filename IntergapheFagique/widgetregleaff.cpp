#include "widgetregleaff.h"

using namespace std;

WidgetRegleAff::WidgetRegleAff(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("AFF");
	
	m_premisse = new QLabel("Axiome", m_top);
	
	m_grid->addWidget(m_premisse, 0, 1, 1, 2);
}

WidgetRegleAff::~WidgetRegleAff()
{
	// delete m_top;
}

string WidgetRegleAff::toString()
{
 	return " " + m_conclusion;
}