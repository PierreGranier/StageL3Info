#include "widgettriplet.h"

using namespace std;

WidgetTriplet::WidgetTriplet(QWidget *parent) : QWidget(parent)
{
	m_hbox = new QHBoxLayout(this);
	
	m_contenu = new QLineEdit(this);
	m_hbox->addWidget(m_contenu);
	m_hbox->setSpacing(0);
	m_hbox->setContentsMargins(0, 0, 0, 0);
}

WidgetTriplet::~WidgetTriplet()
{
	
}

bool WidgetTriplet::estVide() const
{
	if(m_contenu->text().toStdString().empty())
	{
		return true;
	}
	else return false;
}

void WidgetTriplet::modifierTexte(string const &triplet)
{
	m_contenu->setText(QString::fromStdString(triplet));
}

string WidgetTriplet::toString()
{
	return m_contenu->text().toStdString();
}