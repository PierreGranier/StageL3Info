#include "widgetregleaxiome.h"

using namespace std;

WidgetRegleAxiome::WidgetRegleAxiome(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisse = new QLabel("Axiome", this);
	
	// BOUTON SUPPRIMER
	
	m_grid->addWidget(m_premisse, 0, 0, 2, 4, Qt::AlignHCenter);
}

WidgetRegleAxiome::~WidgetRegleAxiome()
{
	
}

void WidgetRegleAxiome::modifierTriplet(const std::string &triplet)
{
	
}

void WidgetRegleAxiome::ajouterSousPreuve(WidgetRegle *sousPreuve)
{
	
}

string WidgetRegleAxiome::toString()
{
	return "";
}