#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(QWidget *parent) : QWidget(parent)
{
	m_top = new QWidget(this);
	
	m_grid = new QGridLayout(m_top);
    
	m_nom = new QLabel("NomRegle", m_top);
	
    m_conclusion = new QLineEdit(m_top);
	// m_conclusion->setFixedWidth(80);
	
	m_grid->addWidget(m_nom, 0, 0, 1, 1);
	m_grid->addWidget(m_conclusion, 1, 1, 1, 2);
}

WidgetRegle::~WidgetRegle()
{
	// delete m_top;
}

string WidgetRegle::toString()
{
	return "HIHIIHIHHIIHIHIHIIHHI";
	// return le tostring du parent et des enfants
}