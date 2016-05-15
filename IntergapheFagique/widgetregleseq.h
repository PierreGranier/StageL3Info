#ifndef widgetregleseq_h
#define widgetregleseq_h

#include "widgetregle.h"

class WidgetRegleSeq : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisseG;
		WidgetTriplet *m_premisseD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetRegle *m_brancheG;
		WidgetRegle *m_brancheD;
		
	public:
		WidgetRegleSeq(QWidget *parent);
		~WidgetRegleSeq();
		
		std::string toString();
};

#endif