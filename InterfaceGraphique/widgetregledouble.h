#ifndef widgetregledouble_h
#define widgetregledouble_h

#include "widgetregle.h"

class WidgetRegleDouble : public WidgetRegle
{
	private:
		WidgetTriplet *m_premisseG;
		WidgetTriplet *m_premisseD;
		
		WidgetAjouter *m_ajouterG;
		WidgetAjouter *m_ajouterD;
		
		WidgetSupprimer *m_supprimerG;
		WidgetSupprimer *m_supprimerD;
		
		WidgetRegle *m_sousPreuveG;
		WidgetRegle *m_sousPreuveD;
		
	public:
		WidgetRegleDouble(const std::string &nomRegle, QWidget *parent);
		~WidgetRegleDouble();
		
		void modifierTriplet(const std::string &triplet);
		bool estPlein() const;
		void ajouterSousPreuve(WidgetRegle *sousPreuve);
		std::string toString();
		
	public slots:
		void ajouterSousPreuveG(WidgetRegle *sousPreuve);
		void ajouterSousPreuveD(WidgetRegle *sousPreuve);
};

#endif