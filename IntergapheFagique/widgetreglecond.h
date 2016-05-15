#ifndef widgetreglecond_h
#define widgetreglecond_h

#include "widgetregle.h"

class WidgetRegleCond : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisseG;
		WidgetTriplet *m_premisseD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetRegle *m_sousPreuveG;
		WidgetRegle *m_sousPreuveD;
		
	public:
		WidgetRegleCond(QWidget *parent);
		~WidgetRegleCond();
		
		std::string toString();
};

#endif