#ifndef widgetregleaff_h
#define widgetregleaff_h

#include "widgetregle.h"

class WidgetRegleAff : public WidgetRegle
{
	private:
		
	public:
		WidgetRegleAff(QWidget *parent);
		~WidgetRegleAff();
		
		std::string toString();
};

#endif