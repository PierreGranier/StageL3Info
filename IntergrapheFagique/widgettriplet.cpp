#include "widgettriplet.h"

using namespace std;

WidgetTriplet::WidgetTriplet(QWidget *parent) : QWidget(parent)
{
	m_hbox = new QHBoxLayout(this);
	
	m_precondition = new QLineEdit(this);
	// m_programmeVariable = new QLineEdit(this);
	// m_programmeValeur = new QLineEdit(this);
	// m_postcondition = new QLineEdit(this);
	
	// m_hbox->addWidget(new QLabel("{", this));
	m_hbox->addWidget(m_precondition);
	// m_hbox->addWidget(new QLabel("}", this));
	// m_hbox->addWidget(m_programmeVariable);
	// m_hbox->addWidget(new QLabel(":=", this));
	// m_hbox->addWidget(m_programmeValeur);
 	// m_hbox->addWidget(new QLabel("{", this));
  	// m_hbox->addWidget(m_postcondition);
	// m_hbox->addWidget(new QLabel("}", this));
	
	m_hbox->setSpacing(0);
	m_hbox->setContentsMargins(0, 0, 0, 0);
}

WidgetTriplet::~WidgetTriplet()
{
	
}

string WidgetTriplet::toString()
{
	return " " + m_precondition->text().toStdString();
}