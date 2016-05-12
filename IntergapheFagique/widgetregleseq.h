#ifndef widgetregleseq_h
#define widgetregleseq_h

#include "widgetregle.h"

class WidgetRegleSeq : public WidgetRegle
{
	private:
		QLineEdit *m_premisseG;
		QLineEdit *m_premisseD;
		
		WidgetRegle *m_regleG;
		WidgetRegle *m_regleD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_AjouterD;
		
	public:
		WidgetRegleSeq(QWidget *parent);
		~WidgetRegleSeq();
		
		std::string toString();
};

#endif