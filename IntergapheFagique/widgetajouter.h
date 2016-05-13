#ifndef widgetajouter_h
#define widgetajouter_h

#include <QtWidgets/QComboBox>
// #include <QtWidgets/QWidget>
#include <iostream>
#include <string>

class WidgetAjouter : public QComboBox
{
	private:
			
	public:
		WidgetAjouter(QWidget *parent);
		~WidgetAjouter();
};

#endif