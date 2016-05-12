#include "widgetreglewhilet.h"

using namespace std;

WidgetRegleWhileT::WidgetRegleWhileT(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILET");
	
	m_premisseG = new QLineEdit(m_top); 
	m_premisseD = new QLineEdit(m_top);
	
	m_grid->addWidget(m_premisseG, 0, 1);
	m_grid->addWidget(m_premisseD, 0, 2);    
    
}


WidgetRegleWhileT::~WidgetRegleWhileT()
{
    // delete(m_top);
}

string WidgetRegleWhileT::toString()
{
 	return "";
	// return le tostring des LineEdit
}