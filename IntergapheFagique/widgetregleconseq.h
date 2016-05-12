#ifndef widgetregleconseq_h
#define widgetregleconseq_h

#include "widgetregle.h"

class WidgetRegleConseq : public WidgetRegle 
{
	private:
		QLineEdit *m_premisse;
		
		WidgetRegle *m_regle;
		
		WidgetAjouter *m_ajouter;
		
	public:
		WidgetRegleConseq(QWidget *parent);
		~WidgetRegleConseq();
		
		std::string toString();
};

#endif