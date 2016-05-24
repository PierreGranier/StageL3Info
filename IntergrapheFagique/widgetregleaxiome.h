#ifndef widgetregleaxiome_h
#define widgetregleaxiome_h

#include "widgetregle.h"

class WidgetRegleAxiome : public WidgetRegle
{
	private:
		QLabel *m_premisse;
		
		WidgetSupprimer *m_supprimer;
		
	public:
		WidgetRegleAxiome(const std::string &nomRegle, QWidget *parent);
		~WidgetRegleAxiome();
		
		void modifierTriplet(const std::string &triplet);
		bool estPlein() const;
		void ajouterSousPreuve(WidgetRegle *sousPreuve);
		std::string toString();
};

#endif