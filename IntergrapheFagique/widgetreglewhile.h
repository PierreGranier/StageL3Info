#ifndef widgetreglewhile_h
#define widgetreglewhile_h

#include "widgetreglesimple.h"

class WidgetRegleWhile : public WidgetRegleSimple
{
    private:
		
    public:
		WidgetRegleWhile(QWidget *parent) : WidgetRegleSimple("WHILE", parent) {};
		~WidgetRegleWhile() {};
};

#endif