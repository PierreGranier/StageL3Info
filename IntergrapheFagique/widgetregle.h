#ifndef widgetregle_h
#define widgetregle_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <iostream>
#include <string>
#include "widgetnomregle.h"
#include "widgettriplet.h"
#include "widgetajouter.h"
#include "widgetsupprimer.h"

class WidgetRegle : public QWidget
{
	protected:
		QGridLayout *m_grid;
		
		WidgetNomRegle *m_nomRegle;
		
	public:
		WidgetRegle(const std::string &nomRegle, QWidget *parent);
		virtual ~WidgetRegle();
		
		std::string nomRegle() const;
		virtual void modifierTriplet(const std::string &triplet) =0;
		virtual void ajouterSousPreuve(WidgetRegle *sousPreuve) =0;
		void supprimerSousPreuve();
		void erreurFermeturePreuve();
		virtual std::string toString() =0;
};

#endif