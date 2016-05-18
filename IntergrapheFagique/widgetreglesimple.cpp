#include "widgetreglesimple.h"

using namespace std;

WidgetRegleSimple::WidgetRegleSimple(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouter, 0, 0, 1, 2, Qt::AlignBottom);
	m_grid->addWidget(m_premisse, 1, 0, 1, 2, Qt::AlignBottom);
	
	QObject::connect(m_ajouter, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleSimple::ajouterSousPreuve);
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
 	return " " + m_premisse->toString() + " " + m_souspreuve->toString();
}