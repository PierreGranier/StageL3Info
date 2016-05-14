#ifndef widgetregleseq_h
#define widgetregleseq_h

#include "widgettriplet.h"
#include "widgetregle.h"

class WidgetRegleSeq : public WidgetRegle
{
	private:
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetRegle *m_premisseG;
		WidgetRegle *m_premisseD;
		
	public:
		WidgetRegleSeq(QWidget *parent);
		~WidgetRegleSeq();
		
		std::string toString();
};

#endif