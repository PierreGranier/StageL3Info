#include "widgetajouter.h"

WidgetAjouter::WidgetAjouter(QWidget *parent) : QComboBox(parent) {
    m_top = new QWidget(this);
    
	
    QComboBox *ajouter = new QComboBox(m_top);
    ajouter->addItem("Ajouter");
    ajouter->addItem("AFF");
    ajouter->addItem("SEQ");
    ajouter->addItem("COND");
    ajouter->addItem("CONSEQ");
    ajouter->addItem("WHILE");
    ajouter->addItem("WHILET");
	
}

WidgetAjouter::~WidgetAjouter() 
{
    delete(m_top);
}