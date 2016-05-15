#include "widgetregleaff.h"

using namespace std;

WidgetRegleAff::WidgetRegleAff(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("AFF");
	
	m_premisse = new QLabel("Axiome", this);
	
	m_grid->addWidget(m_premisse, 0, 1);
}

WidgetRegleAff::~WidgetRegleAff()
{
	
}

string WidgetRegleAff::toString()
{
	return "";
}