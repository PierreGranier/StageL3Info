#ifndef widgetAjouter_h
#define widgetAjouter_h

#include <QtWidgets/QComboBox>
#include <QtWidgets/QWidget>
#include <iostream>
#include <string>

class WidgetAjouter : public QComboBox
{
	private:
		QWidget *m_top;
			
	public:
		WidgetAjouter(QWidget *parent);
		~WidgetAjouter();
};

#endif