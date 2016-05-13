#ifndef widgetregleconseq_h
#define widgetregleconseq_h

#include "widgettriplet.h"
#include "widgetregle.h"

class WidgetRegleConseq : public WidgetRegle 
{
	private:
		WidgetAjouter *m_ajouter;
		
		WidgetRegle *m_premisse;
		
	public:
		WidgetRegleConseq(QWidget *parent);
		~WidgetRegleConseq();
		
		std::string toString();
};

#endif