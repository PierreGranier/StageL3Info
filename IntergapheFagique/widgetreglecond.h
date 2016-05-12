#ifndef widgetreglecond_h
#define widgetreglecond_h

#include "widgetregle.h"

class WidgetRegleAff : public WidgetRegle
{
	private:
		QLineEdit *m_premisseG;
		QLineEdit *m_premisseD;
		
		WidgetRegle *m_regleG;
		WidgetRegle *m_regleD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_AjouterD;
		
	public:
		WidgetRegleCond(QWidget *parent);
		~WidgetRegleCond();
		
		std::string toString();
};

#endif