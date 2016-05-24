#include "widgettriplet.h"

using namespace std;

WidgetTriplet::WidgetTriplet(QWidget *parent) : QWidget(parent)
{
	m_hbox = new QHBoxLayout(this);
	
	m_precondition = new QLineEdit(this);
	m_hbox->addWidget(m_precondition);
	m_hbox->setSpacing(0);
	m_hbox->setContentsMargins(0, 0, 0, 0);
}

WidgetTriplet::~WidgetTriplet()
{
	
}

bool WidgetTriplet::estVide() const
{
	if(m_precondition->text().toStdString().compare(""))
	{
		return true;
	}
	else return false;
}

void WidgetTriplet::modifierTexte(string const &triplet)
{
	m_precondition->setText(QString::fromStdString(triplet));
}

string WidgetTriplet::toString()
{
	return m_precondition->text().toStdString();
}