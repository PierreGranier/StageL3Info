#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	this->setMinimumSize(500, 500);
	this->setStyleSheet("background-color:white;");
	
	QWidget *m_top = new QWidget(this);
	
	QHBoxLayout *ens = new QHBoxLayout(m_top);
	
	WidgetAjouter *afficher = new WidgetAjouter(m_top);
	
	ens->addWidget(afficher);
	ens->setContentsMargins(50,50,50,50);
	// getzfzeffze - size et tout
}

Container::~Container()
{
}