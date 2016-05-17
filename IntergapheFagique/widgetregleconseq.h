#ifndef widgetregleconseq_h
#define widgetregleconseq_h

#include "widgetreglesimple.h"

class WidgetRegleConseq : public WidgetRegleSimple
{
	private:
		
	public:
		WidgetRegleConseq(QWidget *parent) : WidgetRegleSimple("CONSEQ", parent) {};
		~WidgetRegleConseq() {};
};

#endif