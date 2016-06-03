#ifndef widgettriplet_h
#define widgettriplet_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <iostream>
#include <string>

class WidgetTriplet : public QWidget
{
	private:
		QHBoxLayout *m_hbox;
		
		QLineEdit *m_contenu;
		
	public:
		WidgetTriplet(QWidget *parent);
		~WidgetTriplet();
		
		bool estVide() const;
		void modifierTexte(std::string const &triplet);
		std::string toString();
};

#endif