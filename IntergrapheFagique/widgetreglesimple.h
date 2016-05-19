#ifndef widgetreglesimple_h
#define widgetreglesimple_h

#include "widgetregle.h"

class WidgetRegleSimple : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisse;
		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_sousPreuve;
		
	public:
		WidgetRegleSimple(const std::string &nomRegle, QWidget *parent);
		~WidgetRegleSimple();
	
		std::string toString();
				
	public slots:	
		void ajouterSousPreuve(WidgetRegle *sousPreuve);
	   	
};

#endif