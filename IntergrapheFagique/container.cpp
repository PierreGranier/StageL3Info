#include "container.h"

using namespace std;

Container::Container(QWidget *parent) : QWidget(parent)
{
	m_ens = new QVBoxLayout(this);
	
	m_ens->addStretch(1);
	
	this->initialiser();
}

Container::~Container()
{
	
}

void Container::paintEvent(QPaintEvent *event)
{
	// this->setStyleSheet("background-color:white;");
	
	m_buffer = new QImage(size(), QImage::Format_RGB32);
	m_buffer->fill(Qt::white);
	
	m_bufferPainter = new QPainter(m_buffer);
	m_bufferPainter->setPen(Qt::black);
	m_bufferPainter->setRenderHint(QPainter::Antialiasing, true);
		
	QPainter p(this);
	p.drawImage(0, 0, *m_buffer);
}

void Container::initialiser()
{
	delete m_racine;
	m_racine = new WidgetRacine(this);
	m_ens->addWidget(m_racine);
}

void Container::verifier() const
{
	string res = m_racine->toString();
	ofstream fichierRes("fichierRes.txt", ios::out);
	if(fichierRes)
	{
		//cout << m_racine->toString() << endl;
		fichierRes << res << endl;
		fichierRes << endl;
		fichierRes.close();
	}
	else
	{
		cout << "Erreur lors de l'ouverture du fichier" << endl;
	}
    //cout << m_racine->toString() << endl;
}
