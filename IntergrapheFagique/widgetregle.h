#ifndef widgetregle_h
#define widgetregle_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <iostream>
#include <string>
#include "widgetnomregle.h"
#include "widgettriplet.h"
#include "widgetajouter.h"

class WidgetRegle : public QWidget
{
	protected:
		QGridLayout *m_grid;
		
		WidgetNomRegle *m_nomRegle;
		
	public:
		WidgetRegle(const std::string &nomRegle, QWidget *parent);
		~WidgetRegle();
		
		std::string toString();
};

#endif