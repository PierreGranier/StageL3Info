#include "widgetreglewhile.h"

using namespace std;

WidgetRegleWhile::WidgetRegleWhile(QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText("WHILE");
	
	m_premisseG = new QLineEdit(m_top); 
	m_premisseD = new QLineEdit(m_top);
	
	m_grid->addWidget(m_premisseG, 0, 1);
	m_grid->addWidget(m_premisseD, 0, 2);    
    
}


WidgetRegleWhile::~WidgetRegleWhile()
{
    // delete(m_top);
}

string WidgetRegleWhile::toString()
{
 	return "";
	// return le tostring des LineEdit
}