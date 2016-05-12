#ifndef widgetreglewhilet_h
#define widgetreglewhilet_h

#include "widgetregle.h"

class WidgetRegleWhileT : public WidgetRegle
{
    private:
 		QLineEdit *m_premisseG;
		QLineEdit *m_premisseD;
		
		WidgetRegle *m_regleG;
		WidgetRegle *m_regleD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_AjouterD;       
		
    public:
        WidgetRegleWhileT(QWidget *parent);
        ~WidgetRegleWhileT();
		
		std::string toString();		
};

#endif