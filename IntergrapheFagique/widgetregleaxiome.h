#ifndef widgetregleaxiome_h
#define widgetregleaxiome_h

#include "widgetregle.h"

class WidgetRegleAxiome : public WidgetRegle
{
	private:
		QLabel *m_premisse;
		
	public:
		WidgetRegleAxiome(QWidget *parent);
		~WidgetRegleAxiome();
		
		std::string toString();
};

#endif