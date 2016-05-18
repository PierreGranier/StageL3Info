#ifndef container_h
#define container_h

#include <QtWidgets/QWidget>
#include <QtGui/QtGui>
#include <iostream>
#include <string>
#include "widgetracine.h"
#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"
#include "widgetregleconseq.h"
#include "widgetreglewhile.h"
#include "widgetreglewhilet.h"

class Container : public QWidget
{
	private:
		QVBoxLayout *m_ens;
		
		QImage *m_buffer;
		QPainter *m_bufferPainter;
		
		WidgetRacine *m_racine;
		
	public:
		Container(QWidget *parent);
		~Container();
		
		void paintEvent(QPaintEvent *event);
		
	public slots:
		void initialiser();
		void afficher() const;
};

#endif
