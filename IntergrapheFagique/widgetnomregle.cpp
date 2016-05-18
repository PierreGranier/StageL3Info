#include "widgetnomregle.h"

using namespace std;

WidgetNomRegle::WidgetNomRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	this->setMinimumSize(parent->size());
	
	m_parent = parent;
	
	m_nomRegle = QString::fromStdString(nomRegle);

	// QGridLayout *layout = new QGridLayout(this);

	// layout->addWidget(new QLabel("-----------", this), 0, 0);
	// layout->addWidget(new QLabel(m_nomRegle, this), 0, 1);
	// layout->addWidget(new QLabel("-----------", this), 0, 2);



	// m_bufferPainter->drawLine(0, 20, this->width()/2-m_nomRegle.size()*4, 20);
	// m_bufferPainter->drawText(this->width()/2-m_nomRegle.size()*3-2, 24, m_nomRegle);
	// m_bufferPainter->drawLine(m_nomRegle.size(), 20, parent->width(), 20);
}

WidgetNomRegle::~WidgetNomRegle()
{

}

void WidgetNomRegle::paintEvent(QPaintEvent *event)
{
	this->resize(m_parent->size());
	
	if(m_nomRegle.toStdString() != "") 
	{
		m_buffer = new QImage(m_parent->width(), 30, QImage::Format_RGB32);
		m_buffer->fill(Qt::white);
		
		m_bufferPainter = new QPainter(m_buffer);
		m_bufferPainter->setPen(Qt::black);
		m_bufferPainter->setRenderHint(QPainter::Antialiasing, true);
		
		m_bufferPainter->drawLine(0, 20, this->width()/2-m_nomRegle.size()*4, 20);
		m_bufferPainter->drawText(this->width()/2+2-m_nomRegle.size()*3.5, 24, m_nomRegle);
		m_bufferPainter->drawLine(this->width()/2+2+m_nomRegle.size()*6, 20, m_parent->width(), 20);
		
		QPainter p(this);
		p.drawImage(0, 0, *m_buffer);
	}
}

string WidgetNomRegle::toString()
{
	return m_nomRegle.toStdString();
}