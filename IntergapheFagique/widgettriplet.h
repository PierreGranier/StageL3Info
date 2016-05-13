#ifndef widgettriplet_h
#define widgettriplet_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>
#include <iostream>
#include <string>

class WidgetTriplet : public QWidget
{
	private:
		QWidget *m_top;
		QHBoxLayout *m_hbox;
		QLineEdit *m_precondition;
		QLineEdit *m_programme;
		QLineEdit *m_postcondition;
		
	public:
		WidgetTriplet();
		~WidgetTriplet();
		
		std::string toString();
};

#endif