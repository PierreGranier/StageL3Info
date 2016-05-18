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
		virtual ~WidgetRegle();
		
		std::string nomRegle() const;
		virtual std::string toString() =0;
};

#endif