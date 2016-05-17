#include "widgetracine.h"

using namespace std;

WidgetRacine::WidgetRacine(QWidget *parent) : QWidget(parent)
{
	m_grid = new QGridLayout(this);
	
	m_conclusion = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 0);
	m_grid->addWidget(m_conclusion, 1, 0);
}

WidgetRacine::~WidgetRacine()
{
}

string WidgetRacine::toString()
{
	// return m_conclusion.toString() + " " + m_premisse.toString();
	return "";
}