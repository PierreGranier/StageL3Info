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
	QObject::connect(m_supprimerG, &QPushButton::clicked, this, &WidgetRegleDouble::supprimerSousPreuve);
	QObject::connect(m_supprimerD, &QPushButton::clicked, this, &WidgetRegleDouble::supprimerSousPreuve);
}

WidgetRegleDouble::~WidgetRegleDouble()
{
	
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

void WidgetRegleDouble::ajouterSousPreuveG(WidgetRegle *sousPreuve)
{
	m_sousPreuveG = sousPreuve;
	
	/*m_grid->removeWidget(m_ajouterG);
	m_grid->removeWidget(m_supprimerG);
	
	m_ajouterG->setVisible(false);
	m_supprimerG->setVisible(false);*/
	
	m_grid->addWidget(m_sousPreuveG, 0, 0, 1, 2, Qt::AlignBottom);
}

void WidgetRegleDouble::ajouterSousPreuveD(WidgetRegle *sousPreuve)
{
	m_sousPreuveD = sousPreuve;
	
	/*m_grid->removeWidget(m_ajouterD);
	m_grid->removeWidget(m_supprimerD);
	
	m_ajouterD->setVisible(false);
	m_supprimerD->setVisible(false);*/
	
	m_grid->addWidget(m_sousPreuveD, 0, 2, 1, 2, Qt::AlignBottom);
}

void WidgetRegleDouble::supprimerSousPreuve()
{
	/*
	m_grid->removeWidget(m_nomRegle);
	m_grid->removeWidget(m_premisseG);
	m_premisseD->setVisible(false);
	
	m_nomRegle->setVisible(false);
	m_premisseG->setVisible(false);
	m_premisseD->setVisible(false);
	
	m_grid->addWidget(m_ajouterG, 0, 0, 1, 2, Qt::AlignBottom);
	m_grid->addWidget(m_supprimerG, 0, 2, 1, 2, Qt::AlignBottom);
	m_grid->addWidget(m_ajouterD, 0, 0, 1, 2, Qt::AlignBottom);
	m_grid->addWidget(m_supprimerD, 0, 2, 1, 2, Qt::AlignBottom);
	
	m_ajouterG->setVisible(true);
	m_supprimerG->setVisible(true);
	m_ajouterD->setVisible(true);
	m_supprimerD->setVisible(true);
	*/
	
	delete(this);
}