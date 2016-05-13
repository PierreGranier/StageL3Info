#ifndef widgetreglewhilet_h
#define widgetreglewhilet_h

#include "widgettriplet.h"
#include "widgetregle.h"

class WidgetRegleWhileT : public WidgetRegle
{
    private:		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_premisse;
		
    public:
        WidgetRegleWhileT(QWidget *parent);
        ~WidgetRegleWhileT();
		
		std::string toString();		
};

#endif