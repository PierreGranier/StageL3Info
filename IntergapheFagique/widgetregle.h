#ifndef widgetregle_h
#define widgetregle_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <iostream>
#include <string>
#include "widgettriplet.h"
#include "widgetajouter.h"

class WidgetRegle : public QWidget
{
	protected:
		QWidget *m_top;
		QGridLayout *m_grid;
		
		QLabel *m_nom;
		
		WidgetTriplet *m_conclusion;
		
	public:
		WidgetRegle(QWidget *parent);
		~WidgetRegle();
		
		std::string toString();
};

#endif