#include "widgetajouter.h"

WidgetAjouter::WidgetAjouter(QWidget *parent) : QComboBox(parent)
{
   m_top = new QWidget(this);
   
   this->addItem("Ajouter");
   this->addItem("AFF");
   this->addItem("SEQ");
   this->addItem("COND");
   this->addItem("CONSEQ");
   this->addItem("WHILE");
   this->addItem("WHILET");
	
}

WidgetAjouter::~WidgetAjouter() 
{
    delete(m_top);
}