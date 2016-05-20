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
		void erreurFermeturePreuve();
		virtual std::string toString() =0;
};

#endif