#ifndef widgetreglesimple_h
#define widgetreglesimple_h

#include "widgetregle.h"

class WidgetRegleSimple : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisse;
		
		WidgetAjouter *m_ajouter;
		WidgetSupprimer *m_supprimer;
		
		WidgetRegle *m_sousPreuve;
		
	public:
		WidgetRegleSimple(const std::string &nomRegle, QWidget *parent);
		~WidgetRegleSimple();
		
		void modifierTriplet(const std::string &triplet);
		bool estPlein() const;
		std::string toString();
		
	public slots:
		void ajouterSousPreuve(WidgetRegle *sousPreuve);
};

#endif