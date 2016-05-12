#ifndef widgetregleaff_h
#define widgetregleaff_h

#include "widgetregle.h"

class WidgetRegleAff : public WidgetRegle
{
	private:
		QLineEdit *m_premisse;
		
	public:
		WidgetRegleAff(QWidget *parent);
		~WidgetRegleAff();
		
		std::string toString();
};

#endif