#ifndef widgetracine_h
#define widgetracine_h

#include "widgetregleimple.h"

class WidgetRacine : public WidgetRegleSimple
{
	protected:
		
	public:
		WidgetRacine(QWidget *parent) : WidgetRegleSimple("Racine", parent) {};
		~WidgetRacine() {};
		
		std::string toString();
};

#endif