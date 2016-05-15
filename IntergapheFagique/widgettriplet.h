#ifndef widgettriplet_h
#define widgettriplet_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <iostream>
#include <string>

class WidgetTriplet : public QWidget
{
	private:
		QWidget *m_top;
		QHBoxLayout *m_hbox;
		
		QLineEdit *m_precondition;
		QLineEdit *m_programmeVariable;
		QLineEdit *m_programmeValeur;
		QLineEdit *m_postcondition;
		
	public:
		WidgetTriplet(QWidget *parent);
		~WidgetTriplet();
		
		std::string toString();
};

#endif