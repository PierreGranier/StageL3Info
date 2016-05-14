#ifndef widgetreglecond_h
#define widgetreglecond_h

#include "widgettriplet.h"
#include "widgetregle.h"

class WidgetRegleCond : public WidgetRegle
{
	private:
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetRegle *m_premisseG;
		WidgetRegle *m_premisseD;
		
	public:
		WidgetRegleCond(QWidget *parent);
		~WidgetRegleCond();
		
		std::string toString();
};

#endif