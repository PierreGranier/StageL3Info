#ifndef widgetracine_h
#define widgetracine_h

#include "widgetreglesimple.h"

class WidgetRacine : public WidgetRegleSimple
{
	protected:
		
	public:
		WidgetRacine(QWidget *parent) : WidgetRegleSimple("", parent) {};
		~WidgetRacine() {};
		
		std::string toString();
};

#endif