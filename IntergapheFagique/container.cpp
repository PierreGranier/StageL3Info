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
	
	WidgetRegleAff *aff = new WidgetRegleAff(m_top);
	WidgetRegleSeq *seq = new WidgetRegleSeq(m_top);
	WidgetRegleCond *cond = new WidgetRegleCond(m_top);
	WidgetRegleConseq *conseq = new WidgetRegleConseq(m_top);
	WidgetRegleWhile *whileN = new WidgetRegleWhile(m_top);
	WidgetRegleWhileT *whileT = new WidgetRegleWhileT(m_top);
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