#include "widgetregleaxiome.h"

using namespace std;

WidgetRegleAxiome::WidgetRegleAxiome(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisse = new QLabel("Axiome", this);
	
	m_grid->addWidget(m_premisse, 0, 1);
}

WidgetRegleAxiome::~WidgetRegleAxiome()
{
	
}

string WidgetRegleAxiome::toString()
{
	return "";
}