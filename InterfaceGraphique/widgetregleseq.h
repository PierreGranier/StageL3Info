#ifndef widgetregleseq_h
#define widgetregleseq_h

#include "widgetregledouble.h"

class WidgetRegleSeq : public WidgetRegleDouble
{
	private:
		
	public:
		WidgetRegleSeq(QWidget *parent) : WidgetRegleDouble("SEQ", parent) {};
		~WidgetRegleSeq() {};
};

#endif