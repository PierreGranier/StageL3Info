#include "widgetreglewhilet.h"

using namespace std;

WidgetRegleWhileT::WidgetRegleWhileT(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILET");
	
	m_ajouter = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouter, 0, 1, 1, 2);
}


WidgetRegleWhileT::~WidgetRegleWhileT()
{
    // delete(m_top);
}

string WidgetRegleWhileT::toString()
{
 	// return " " + m_conclusion + " " + m_premisse;
	return "";
}