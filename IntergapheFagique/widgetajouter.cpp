#include "widgetajouter.h"

WidgetAjouter::WidgetAjouter(QWidget *parent) : QComboBox(parent)
{
	this->addItem("Ajouter une règle");
	this->addItem("AFF");
	this->addItem("SEQ");
	this->addItem("COND");
	this->addItem("CONSEQ");
	this->addItem("WHILE");
	this->addItem("WHILET");
	
	// this->setStyleSheet("background-color:gray;border:1px solid black;color:white;padding:5px 0;text-align: center;");
}

WidgetAjouter::~WidgetAjouter() 
{
	
}