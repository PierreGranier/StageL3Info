#ifndef widgetreglewhile_h
#define widgetreglewhile_h

#include "widgettriplet.h"
#include "widgetregle.h"

class WidgetRegleWhile : public WidgetRegle
{
    private:
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_premisse;
		
    public:
        WidgetRegleWhile(QWidget *parent);
        ~WidgetRegleWhile();
		
		std::string toString();		
};

#endif