#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	// this->setMinimumSize(600, 600);
	// this->setStyleSheet("background-color:white;");
	
	QVBoxLayout *ens = new QVBoxLayout(this);
	
	ens->addWidget(new WidgetRacine(this));
	ens->addWidget(new WidgetRegleSeq(this));
	ens->addWidget(new WidgetRegleAff(this));
	ens->addWidget(new WidgetRegleWhile(this));

	// ens->setContentsMargins(50,50,50,50);
	// getzfzeffze - size et tout
}

Container::~Container()
{
	
}