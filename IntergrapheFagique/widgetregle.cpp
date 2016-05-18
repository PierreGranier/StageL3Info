#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	m_grid = new QGridLayout(this);
    
	m_nomRegle = new WidgetNomRegle(nomRegle, this);
	
	m_grid->addWidget(m_nomRegle, 2, 0, 1, 2, Qt::AlignLeft);
	
	m_grid->setSpacing(0);
	m_grid->setContentsMargins(0, 0, 0, 0);
}

WidgetRegle::~WidgetRegle()
{
	
}

string WidgetRegle::nomRegle() const
{
	return m_nomRegle->toString();
}