#ifndef widgetajouter_h
#define widgetajouter_h

#include <QtWidgets/QComboBox>
#include <iostream>
#include <string>


class WidgetRegle;

class WidgetAjouter : public QComboBox
{
	private:
			
	public:
		WidgetAjouter(QWidget *parent);
		~WidgetAjouter();
		WidgetRegle *genererWidgetRegle(const QString &nomRegle);
};

#endif