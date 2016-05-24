#include "widgetreglesimple.h"

using namespace std;

WidgetRegleSimple::WidgetRegleSimple(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisse = new WidgetTriplet(this);
	
	m_ajouter = new WidgetAjouter(this);
	m_supprimer = new WidgetSupprimer(this);
	
	m_grid->addWidget(m_ajouter, 0, 0, 1, 3, Qt::AlignBottom);
	m_grid->addWidget(m_supprimer, 0, 3, Qt::AlignBottom);
	m_grid->addWidget(m_premisse, 1, 0, 1, 4, Qt::AlignBottom);
	
	QObject::connect(m_ajouter, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleSimple::ajouterSousPreuve);
	QObject::connect(m_supprimer, &QPushButton::clicked, this, &WidgetRegle::supprimerSousPreuve);
	
	if(nomRegle.compare("") == 0)
	{
		m_supprimer->setEnabled(false);
	}
}

WidgetRegleSimple::~WidgetRegleSimple()
{
	
}

void WidgetRegleSimple::modifierTriplet(const string &triplet)
{
	m_premisse->modifierTexte(triplet);
}

bool WidgetRegleSimple::estPlein() const
{
	return m_sousPreuve != NULL;
}

void WidgetRegleSimple::ajouterSousPreuve(WidgetRegle *sousPreuve)
{
	// m_ajouter->setCurrentIndex(0);
	
	m_sousPreuve = sousPreuve;
	
	/*m_grid->removeWidget(m_ajouter);
	m_grid->removeWidget(m_supprimer);*/
	
	/*m_ajouter->setVisible(false);
	m_supprimer->setVisible(false);*/
	
	m_grid->addWidget(m_sousPreuve, 0, 0, 1, 4, Qt::AlignBottom);
}

string WidgetRegleSimple::toString()
{
	if(m_sousPreuve == NULL)
	{
		WidgetRegle::erreurFermeturePreuve();
		return "";
	}
	return m_sousPreuve->nomRegle() + " " + m_premisse->toString() + " " + m_sousPreuve->toString();
}