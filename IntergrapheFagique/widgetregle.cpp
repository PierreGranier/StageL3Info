#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	// this->setMaximumWidth(700);
	
	m_grid = new QGridLayout(this);
    
	m_nom = new QLabel(QString::fromStdString(nomRegle), this);
	
	m_grid->addWidget(m_nom, 2, 0, 1, 2, Qt::AlignHCenter);
}

WidgetRegle::~WidgetRegle()
{
	
}

string WidgetRegle::toString()
{
	return "";
}