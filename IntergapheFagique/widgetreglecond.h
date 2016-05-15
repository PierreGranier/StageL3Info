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
		
		WidgetRegle *m_souspreuveG;
		WidgetRegle *m_souspreuveD;
		
	public:
		WidgetRegleCond(QWidget *parent);
		~WidgetRegleCond();
		
		std::string toString();
};

#endif