#include "widgetregleaff.h"

using namespace std;

WidgetRegleAff::WidgetRegleAff(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("AFF");
	
	m_premisse = new QLineEdit(m_top);
	m_premisse->setReadOnly(true);
	
	m_grid->addWidget(m_premisse, 0, 1);
}

WidgetRegleAff::~WidgetRegleAff()
{
	// delete m_top;
}

string WidgetRegleAff::toString()
{
	return "";
	// return le tostring des LineEdit
}