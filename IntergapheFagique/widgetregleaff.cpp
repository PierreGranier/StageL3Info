#include "widgetregleaff.h"

using namespace std;

WidgetRegleAff::WidgetRegleAff(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("AFF");
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