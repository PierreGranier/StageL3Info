#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	this->setMinimumSize(500, 500);
	this->setStyleSheet("background-color:white;");
	
	QWidget *m_top = new QWidget(this);
	
	QHBoxLayout *ens = new QHBoxLayout(this);
	
	WidgetAjouter *afficher = new WidgetAjouter(this);
	
	ens->addWidget(afficher);
	//ens->setContentsMargins(50,50,50,50);
	// getzfzeffze - size et tout
	
	WidgetRegleAff *aff = new WidgetRegleAff(this);
	WidgetRegleSeq *seq = new WidgetRegleSeq(this);
	WidgetRegleCond *cond = new WidgetRegleCond(this);
	WidgetRegleConseq *conseq = new WidgetRegleConseq(this);
	WidgetRegleWhile *whileN = new WidgetRegleWhile(this);
	WidgetRegleWhileT *whileT = new WidgetRegleWhileT(this);
	ens->addWidget(aff);
	ens->addWidget(seq);
	ens->addWidget(cond);
	ens->addWidget(conseq);
	ens->addWidget(whileN);
	ens->addWidget(whileT);
}

Container::~Container()
{
}