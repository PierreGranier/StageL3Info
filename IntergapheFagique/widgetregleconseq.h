#ifndef widgetregleconseq_h
#define widgetregleconseq_h

#include "widgetregle.h"

class WidgetRegleConseq : public WidgetRegle 
{
	private:
		WidgetTriplet *m_premisse;
		
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_sousPreuve;
		
	public:
		WidgetRegleConseq(QWidget *parent);
		~WidgetRegleConseq();
		
		std::string toString();
};

#endif