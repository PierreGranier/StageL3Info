#include "widgettriplet.h"

using namespace std;

WidgetTriplet::WidgetTriplet(QWidget *parent) : QWidget(parent)
{
	m_top = new QWidget(this);
	// m_top->setFixedWidth(300);
	
	m_hbox = new QHBoxLayout(m_top);
	
	m_precondition = new QLineEdit(m_top);
	m_programme = new QLineEdit(m_top);
	m_postcondition = new QLineEdit(m_top);
	
	m_hbox->addWidget(m_precondition);
	m_hbox->addWidget(m_programme);
   	m_hbox->addWidget(m_postcondition);
}

WidgetTriplet::~WidgetTriplet()
{
	// delete m_top;
}

string WidgetTriplet::toString()
{
	return m_precondition.??? + " " + m_programme.??? + " " + m_postcondition.???;
}