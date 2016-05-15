#ifndef widgetracine_h
#define widgetracine_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <iostream>
#include <string>
#include "widgettriplet.h"
#include "widgetajouter.h"
#include "widgetregle.h"

class WidgetRacine : public QWidget
{
	protected:
		QGridLayout *m_grid;
		
		WidgetTriplet *m_conclusion;
		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_premisse;
		
	public:
		WidgetRacine(QWidget *parent);
		~WidgetRacine();
		
		std::string toString();
};

#endif