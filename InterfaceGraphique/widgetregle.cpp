#include "widgetregle.h"

using namespace std;

WidgetRegle::WidgetRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	m_grid = new QGridLayout(this);
	
	if(nomRegle.compare("") != 0)
	{
		m_nomRegle = new WidgetNomRegle(nomRegle, this);

		m_grid->addWidget(m_nomRegle, 2, 0, 1, 4, Qt::AlignLeft);
	}
	
	m_grid->setSpacing(3);
	m_grid->setContentsMargins(0, 0, 0, 0);
}

WidgetRegle::~WidgetRegle()
{
	
}

string WidgetRegle::nomRegle() const
{
	return m_nomRegle->toString();
}

void WidgetRegle::supprimerSousPreuve()
{
	delete(this);
}

void WidgetRegle::erreurFermeturePreuve()
{
	QMessageBox *popup = new QMessageBox(this);
	popup->setIcon(QMessageBox::Critical);
	popup->setText("Preuve non terminée. Veuillez clore les sous-preuves avec un axiome.");
	popup->exec();
}
