#include "widgetregleaxiome.h"

using namespace std;

WidgetRegleAxiome::WidgetRegleAxiome(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisse = new QLabel("Axiome", this);
	
	m_supprimer = new WidgetSupprimer(this);
	
	m_grid->addWidget(m_premisse, 0, 0, 2, 3, Qt::AlignHCenter);
	m_grid->addWidget(m_supprimer, 0, 3);
}

WidgetRegleAxiome::~WidgetRegleAxiome()
{
	
}

void WidgetRegleAxiome::modifierTriplet(const std::string &triplet)
{
	
}

bool WidgetRegleAxiome::estPlein() const
{
	return true;
}

void WidgetRegleAxiome::ajouterSousPreuve(WidgetRegle *sousPreuve)
{
	
}

string WidgetRegleAxiome::toString()
{
	return "";
}