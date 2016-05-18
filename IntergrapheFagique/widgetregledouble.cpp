#include "widgetregledouble.h"

using namespace std;

WidgetRegleDouble::WidgetRegleDouble(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisseG = new WidgetTriplet(this);
	m_premisseD = new WidgetTriplet(this);
	
	m_ajouterG = new WidgetAjouter(this);
	m_ajouterD = new WidgetAjouter(this);
	
	m_grid->addWidget(m_ajouterG, 0, 0, Qt::AlignBottom);
	m_grid->addWidget(m_ajouterD, 0, 1, Qt::AlignBottom);
	m_grid->addWidget(m_premisseG, 1, 0, Qt::AlignBottom);
	m_grid->addWidget(m_premisseD, 1, 1, Qt::AlignBottom);
	
	QObject::connect(m_ajouterG, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleDouble::ajouterSousPreuveG);
	QObject::connect(m_ajouterD, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleDouble::ajouterSousPreuveD);
}

WidgetRegleDouble::~WidgetRegleDouble()
{
	
}

void WidgetRegleDouble::ajouterSousPreuveG(WidgetRegle *sousPreuve)
{
    m_sousPreuveG = sousPreuve;
    m_grid->replaceWidget(m_ajouterG, m_sousPreuveG);
    delete m_ajouterG;
}

void WidgetRegleDouble::ajouterSousPreuveD(WidgetRegle *sousPreuve)
{
    m_sousPreuveD = sousPreuve;
    m_grid->replaceWidget(m_ajouterD, m_sousPreuveD);
    delete m_ajouterD;
}

string WidgetRegleDouble::toString()
{
 	return " " + m_premisseG->toString() + " " + m_premisseD->toString() + " " + m_sousPreuveG->toString() + " " + m_sousPreuveD->toString();
}