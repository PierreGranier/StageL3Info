#ifndef widgetregledouble_h
#define widgetregledouble_h

#include "widgetregle.h"

class WidgetRegleDouble : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisseG;
		WidgetTriplet *m_premisseD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetRegle *m_sousPreuveG;
		WidgetRegle *m_sousPreuveD;
		
	public:
		WidgetRegleDouble(const std::string &nomRegle, QWidget *parent);
		~WidgetRegleDouble();
		
		std::string toString();
		
	public slots:	
		void ajouterSousPreuveG(WidgetRegle *sousPreuve);
		void ajouterSousPreuveD(WidgetRegle *sousPreuve);
};

#endif