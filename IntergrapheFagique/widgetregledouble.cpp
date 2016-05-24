#include "widgetregledouble.h"

using namespace std;

WidgetRegleDouble::WidgetRegleDouble(const string &nomRegle, QWidget *parent) : WidgetRegle(nomRegle, parent)
{
	m_premisseG = new WidgetTriplet(this);
	m_premisseD = new WidgetTriplet(this);
	
	m_ajouterG = new WidgetAjouter(this);
	m_ajouterD = new WidgetAjouter(this);
	m_supprimerG = new WidgetSupprimer(this);
	m_supprimerD = new WidgetSupprimer(this);
	
	m_grid->addWidget(m_ajouterG, 0, 0, Qt::AlignBottom);
	m_grid->addWidget(m_supprimerG, 0, 1, Qt::AlignBottom);
	m_grid->addWidget(m_ajouterD, 0, 2, Qt::AlignBottom);
	m_grid->addWidget(m_supprimerD, 0, 3, Qt::AlignBottom);
	m_grid->addWidget(m_premisseG, 1, 0, 1, 2, Qt::AlignBottom);
	m_grid->addWidget(m_premisseD, 1, 2, 1, 2, Qt::AlignBottom);
	
	QObject::connect(m_ajouterG, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleDouble::ajouterSousPreuveG);
	QObject::connect(m_ajouterD, &WidgetAjouter::envoyerWidgetRegle, this, &WidgetRegleDouble::ajouterSousPreuveD);
	QObject::connect(m_supprimerG, &QPushButton::clicked, this, &WidgetRegle::supprimerSousPreuve);
	QObject::connect(m_supprimerD, &QPushButton::clicked, this, &WidgetRegle::supprimerSousPreuve);
	
	//utile pour pas avoir d'erreur de segmentation :*
	m_sousPreuveD = NULL;
	m_sousPreuveG = NULL;
}

WidgetRegleDouble::~WidgetRegleDouble()
{
	
}

void WidgetRegleDouble::modifierTriplet(const std::string &triplet)
{
	// Si le gauche est pris, mettre à droite
	// estVide() return true si est vide
	if(m_premisseG->estVide() == true)
	{
		m_premisseG->modifierTexte(triplet);
	}
	else {
		m_premisseD->modifierTexte(triplet);
	}
}

void WidgetRegleDouble::ajouterSousPreuve(WidgetRegle *sousPreuve)
{
	// Si le gauche est pris, mettre à droite
	if(m_sousPreuveG == NULL)
	{
		m_sousPreuveG = sousPreuve;
	}
	else {
		m_sousPreuveD = sousPreuve;
	}
}

void WidgetRegleDouble::ajouterSousPreuveG(WidgetRegle *sousPreuve)
{	
	m_sousPreuveG = sousPreuve;
	
	m_grid->addWidget(m_sousPreuveG, 0, 0, 1, 2, Qt::AlignBottom);
}

void WidgetRegleDouble::ajouterSousPreuveD(WidgetRegle *sousPreuve)
{	
	m_sousPreuveD = sousPreuve;
	
	m_grid->addWidget(m_sousPreuveD, 0, 2, 1, 2, Qt::AlignBottom);
}

string WidgetRegleDouble::toString()
{
	if(m_sousPreuveG == NULL || m_sousPreuveD == NULL)
	{
		WidgetRegle::erreurFermeturePreuve();
		return "";
	}
	return m_sousPreuveG->nomRegle() + " " + m_premisseG->toString() + " " + m_sousPreuveG->toString() + " " + m_sousPreuveD->nomRegle() + " " + m_premisseD->toString() + " " + m_sousPreuveD->toString();
}