#include "widgetajouter.h"

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
}

WidgetAjouter::~WidgetAjouter() 
{
	
}