#ifndef widgetregleaff_h
#define widgetregleaff_h

#include "widgetregleaxiome.h"

class WidgetRegleAff : public WidgetRegleAxiome
{
    private:
		
    public:
		WidgetRegleAff(QWidget *parent) : WidgetRegleAxiome("AFF", parent) {};
		~WidgetRegleAff() {};
};

#endif