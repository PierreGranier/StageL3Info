#include "widgetnomregle.h"

using namespace std;

WidgetNomRegle::WidgetNomRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	 this->setMinimumSize(parent->size());

	m_nomRegle = QString::fromStdString(nomRegle);

	// QGridLayout *layout = new QGridLayout(this);

	// layout->addWidget(new QLabel("-----------", this), 0, 0);
	// layout->addWidget(new QLabel(m_nomRegle, this), 0, 1);
	// layout->addWidget(new QLabel("-----------", this), 0, 2);

	m_buffer = new QImage(size(), QImage::Format_RGB32);
	m_buffer->fill(Qt::white);

	m_bufferPainter = new QPainter(m_buffer);
	m_bufferPainter->setPen(Qt::black);
	m_bufferPainter->setRenderHint(QPainter::Antialiasing, true);

	m_bufferPainter->drawLine(0, 20, this->width()/2-m_nomRegle.size()/2, 20);
	m_bufferPainter->drawText(this->width()/2-m_nomRegle.size()/2+100000000000, 25, m_nomRegle);
	m_bufferPainter->drawLine(this->width()/2+m_nomRegle.size()/2, 20, this->width(), 20);
}

WidgetNomRegle::~WidgetNomRegle()
{

}

void WidgetNomRegle::paintEvent(QPaintEvent *event) {
	QPainter p(this);
	p.drawImage(0, 0, *m_buffer);
}
