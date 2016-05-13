#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(QWidget *parent) : QWidget(parent)
{
	m_top = new QWidget(this);
	m_top->setFixedWidth(300);
	
	m_grid = new QGridLayout(m_top);
    
	m_nom = new QLabel("NomRegle", m_top);
	
    m_conclusion = new QLineEdit(m_top);
	
	m_grid->addWidget(m_nom, 1, 0, 1, 1);
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