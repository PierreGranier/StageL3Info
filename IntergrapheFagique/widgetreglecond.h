#ifndef widgetreglecond_h
#define widgetreglecond_h

#include "widgetregledouble.h"

class WidgetRegleCond : public WidgetRegleDouble
{
	private:
		
	public:
		WidgetRegleCond(QWidget *parent) : WidgetRegleDouble("COND", parent) {};
		~WidgetRegleCond() {};
};

#endif