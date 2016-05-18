#ifndef widgetnomregle_h
#define widgetnomregle_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QtGui/QtGui>
#include <iostream>
#include <string>

class WidgetNomRegle : public QWidget
{
	private:
		QString m_nomRegle;
		QWidget *m_parent;
		QImage *m_buffer;
		QPainter *m_bufferPainter;
		
	public:
		 WidgetNomRegle(const std::string &nomRegle, QWidget *parent);
		~WidgetNomRegle();
		
		 void paintEvent(QPaintEvent *event);
};

#endif
