#ifndef container_h
#define container_h

#include <QtWidgets/QWidget>
#include "widgetajouter.h"
#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"
#include "widgetregleconseq.h"

class Container : public QWidget
{
	private:
		QVBoxLayout *m_box;
		
	public:
		Container(QWidget *parent);
		~Container();
};

#endif
