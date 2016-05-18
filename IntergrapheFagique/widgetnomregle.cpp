#include "widgetnomregle.h"

using namespace std;

WidgetNomRegle::WidgetNomRegle(const string &nomRegle, QWidget *parent) : QWidget(parent)
{
	// this->setMinimumWidth(QWIDGETSIZE_MAX);

	m_nomRegle = QString::fromStdString(nomRegle);

	QGridLayout *layout = new QGridLayout(this);

	layout->addWidget(new QLabel("-----------------------------", this), 0, 0);
	layout->addWidget(new QLabel(m_nomRegle, this), 0, 1);
	layout->addWidget(new QLabel("-----------------------------", this), 0, 2);

	/*m_buffer = new QImage(size(), QImage::Format_RGB32);
	m_buffer->fill(Qt::white);

	m_bufferPainter = new QPainter(m_buffer);
	m_bufferPainter->setPen(Qt::black);
	m_bufferPainter->setRenderHint(QPainter::Antialiasing, true);

	m_bufferPainter->drawText(5, 10, m_nomRegle);
	m_bufferPainter->drawLine(0, 20, QWIDGETSIZE_MAX, 20);*/
}

WidgetNomRegle::~WidgetNomRegle()
{

}

void WidgetNomRegle::paintEvent(QPaintEvent *event) {
	/*cout << m_nomRegle.toStdString() << endl;

	QPainter p(this);
	p.drawImage(0, 0, *m_buffer);*/
}
