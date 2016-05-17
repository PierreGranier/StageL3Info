#ifndef widgetajouter_h
#define widgetajouter_h

#include <QtWidgets/QComboBox>
#include <iostream>
#include <string>

class WidgetRegle;

class WidgetAjouter : public QComboBox
{
	Q_OBJECT
	
	private:
			
	public:
		WidgetAjouter(QWidget *parent);
		~WidgetAjouter();
	
	public slots:	
		WidgetRegle *genererWidgetRegle(const QString &nomRegle);
		
	signals:
		void envoyerWidgetRegle(WidgetRegle *sousPreuve);	
};

#endif