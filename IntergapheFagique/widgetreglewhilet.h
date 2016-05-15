#ifndef widgetreglewhilet_h
#define widgetreglewhilet_h

#include "widgetregle.h"

class WidgetRegleWhileT : public WidgetRegle
{
    private:		
		WidgetTriplet *m_premisse;
		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_souspreuve;
		
    public:
        WidgetRegleWhileT(QWidget *parent);
        ~WidgetRegleWhileT();
		
		std::string toString();		
};

#endif