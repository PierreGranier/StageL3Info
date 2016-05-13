#include "widgetracine.h"

using namespace std;

WidgetRacine::WidgetRacine(QWidget *parent) : QWidget(parent)
{
	m_top = new QWidget(this);
	m_top->setFixedWidth(300);
	
	m_grid = new QGridLayout(m_top);
	
	m_conclusion = new WidgetRacine(m_top);
	m_ajouter = new WidgetAjouter(m_top);
	
	m_grid->addWidget(m_ajouter, 0, 0);
	m_grid->addWidget(m_conclusion, 1, 0);
}

WidgetRacine::~WidgetRacine()
{
	// delete m_top;
}

string WidgetRacine::toString()
{
	return m_conclusion + " " + m_premisse;
}