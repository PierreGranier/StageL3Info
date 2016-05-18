#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{	
	m_grid = new QGridLayout(this);
    
	m_nomRegle = new WidgetNomRegle(nomRegle, this);
	
	m_grid->addWidget(m_nomRegle, 2, 0, 1, 2, Qt::AlignHCenter);
}

WidgetRegle::~WidgetRegle()
{
	
}

string WidgetRegle::toString()
{
	return "";
}