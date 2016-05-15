#ifndef widgetreglewhile_h
#define widgetreglewhile_h

#include "widgetregle.h"

class WidgetRegleWhile : public WidgetRegle
{
    private:
		WidgetTriplet *m_premisse;
		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_sousPreuve;
		
    public:
        WidgetRegleWhile(QWidget *parent);
        ~WidgetRegleWhile();
		
		std::string toString();		
};

#endif