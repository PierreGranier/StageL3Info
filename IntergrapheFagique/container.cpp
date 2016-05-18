#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *ens = new QVBoxLayout(this);
	
	ens->addStretch(1);
	
	ens->addWidget(new WidgetRacine(this));
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