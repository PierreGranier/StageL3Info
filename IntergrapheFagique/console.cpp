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

void Console::ecrire(const std::string &message)
{
	m_message->setText(QString::fromStdString(message));
}
