#include "console.h"

using namespace std;

Console::Console(QWidget *parent) : QWidget(parent)
{
	this->setStyleSheet("background:white");

	m_ens = new QVBoxLayout(this);

	m_message = new QLabel(this);
	m_message->setWordWrap(true);
	m_ens->addWidget(m_message);

	m_ens->addStretch(1);

	m_ens->setSpacing(0);
	// m_ens->setContentsMargins(0, 0, 0, 0);
}

Console::~Console()
{

}

void Console::vider()
{
	m_message->setText("");
}

void Console::ecrire(const string &message)
{
	m_message->setText(m_message->text() + QString::fromStdString(message));
}
