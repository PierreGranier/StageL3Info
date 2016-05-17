#include "widgetregleaxiome.h"

using namespace std;

WidgetRegleAxiome::WidgetRegleAxiome(QWidget *parent) : WidgetRegle(parent)
{
	m_nom->setText("AFF");
	
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