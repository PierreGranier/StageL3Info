#include "widgetreglesimple.h"

using namespace std;

WidgetRegleSimple::WidgetRegleSimple(const string &nomRegle, QWidget *parent) : WidgetRegle(parent)
{
    m_nom->setText(QString::fromStdString(nomRegle));
	
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 1);
	m_grid->addWidget(m_premisse, 1, 1);
	
	connect(m_ajouter, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetAjouter::ajouterSousPreuve);
}

WidgetRegleSimple::~WidgetRegleSimple()
{
	
}

void WidgetRegleSimple::ajouterSousPreuve(WidgetRegle *sousPreuve)
{
    m_sousPreuve = sousPreuve;
    m_grid->replaceWidget(m_ajouter, m_sousPreuve);
    delete m_ajouter;
}

string WidgetRegleSimple::toString()
{
 	// return " " + m_premisse.toString() + " " + m_souspreuve.toString();
	return "";
}