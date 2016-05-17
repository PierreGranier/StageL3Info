#ifndef widgetreglewhilet_h
#define widgetreglewhilet_h

#include "widgetreglesimple.h"

class WidgetRegleWhileT : public WidgetRegleSimple
{
    private:
		
    public:
		WidgetRegleWhileT(QWidget *parent) : WidgetRegleSimple("WHILET", parent) {};
		~WidgetRegleWhileT() {};
};

#endif