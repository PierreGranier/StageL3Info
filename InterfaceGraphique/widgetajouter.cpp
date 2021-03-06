#include "widgetajouter.h"

#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"
#include "widgetregleconseq.h"
#include "widgetreglewhile.h"
#include "widgetreglewhilet.h"

using namespace std;

WidgetAjouter::WidgetAjouter(QWidget *parent) : QComboBox(parent)
{
	this->addItem("Ajouter une règle");
	this->addItem("AFF");
	this->addItem("SEQ");
	this->addItem("COND");
	this->addItem("CONSEQ");
	this->addItem("WHILE");
	this->addItem("WHILET");
	
	QObject::connect(this, &WidgetAjouter::currentTextChanged, this, &WidgetAjouter::genererWidgetRegle);
}

WidgetAjouter::~WidgetAjouter() 
{
	
}

void WidgetAjouter::genererWidgetRegle(const QString &nomRegle) 
{
	WidgetRegle *newWidget;
	
	if(nomRegle == "AFF")
		newWidget = new WidgetRegleAff(this);
	else if(nomRegle == "SEQ")
		newWidget = new WidgetRegleSeq(this);
	else if(nomRegle == "COND")
		newWidget = new WidgetRegleCond(this);
	else if(nomRegle == "CONSEQ")
		newWidget = new WidgetRegleConseq(this);
	else if(nomRegle == "WHILE")
		newWidget = new WidgetRegleWhile(this);
	else if(nomRegle == "WHILET")
		newWidget = new WidgetRegleWhileT(this);
	else newWidget = NULL;
	
	if(newWidget != NULL)
		emit envoyerWidgetRegle(newWidget);
}