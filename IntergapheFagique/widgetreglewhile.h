#ifndef widgetreglewhile_h
#define widgetreglewhile_h

#include "widgetregle.h"

class WidgetRegleWhile : public WidgetRegle
{
    private:
 		QLineEdit *m_premisseG;
		QLineEdit *m_premisseD;
		
		WidgetRegle *m_regleG;
		WidgetRegle *m_regleD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_AjouterD;       
		
    public:
        WidgetRegleWhile(QWidget *parent);
        ~WidgetRegleWhile();
		
		std::string toString();		
};

#endif