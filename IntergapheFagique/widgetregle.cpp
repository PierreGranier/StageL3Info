#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(QWidget *parent) : QWidget(parent)
{
	// this->setMaximumWidth(700);
	
	m_grid = new QGridLayout(this);
    
	m_nom = new QLabel("NomRegle", this);
	
	m_grid->addWidget(m_nom, 1, 0, 2, 1);
}

WidgetRegle::~WidgetRegle()
{
	
}

string WidgetRegle::toString()
{
	return "";
}