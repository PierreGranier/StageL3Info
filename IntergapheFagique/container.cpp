#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	this->setMinimumSize(800, 600);
	this->setStyleSheet("background-color:white;");
		
	QVBoxLayout *ens = new QVBoxLayout(this);
	
	WidgetAjouter *afficher = new WidgetAjouter(this);
	WidgetRegleAff *aff = new WidgetRegleAff(this);
	WidgetRegleSeq *seq = new WidgetRegleSeq(this);
	WidgetRegleCond *cond = new WidgetRegleCond(this);
	WidgetRegleConseq *conseq = new WidgetRegleConseq(this);
	
	ens->addWidget(afficher);
	ens->addWidget(aff);
	ens->addWidget(seq);
	ens->addWidget(cond);
	ens->addWidget(conseq);
}

Container::~Container()
{
}