#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	this->setMinimumSize(600, 600);
	// this->setStyleSheet("background-color:white;");
	
	/*QWidget *m_top = new QWidget(0);
	QVBoxLayout *ens = new QVBoxLayout(m_top);
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
	m_top->show();*/
	
	QVBoxLayout *ens = new QVBoxLayout(this);
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
	
	// ens->setContentsMargins(50,50,50,50);
	// getzfzeffze - size et tout
}

Container::~Container()
{
	
}