#ifndef widgetregle_h
#define widgetregle_h

#include <QtWidgets/QtWidgets>
#include <iostream>
#include <string>

class WidgetRegle : public QWidget
{
	protected:
		QWidget *m_top;
		QGridLayout *m_grid;
		QLabel *m_nom;
		QLineEdit *m_conclusion;
		
	public:
		WidgetRegle(QWidget *parent);
		~WidgetRegle();
		
		std::string toString();
};

#endif