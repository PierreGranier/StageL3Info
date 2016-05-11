#ifndef container_h
#define container_h

#include "QtWidgets/QtWidgets"
/*#include "regles/aff.h"
#include "regles/seq.h"*/

class Container : public QWidget
{
	private:
		QVBoxLayout *m_box;
		
	public:
		Container(QWidget *parent);
		~Container() {};
		
		void dragEnterEvent(QDragEnterEvent *event);
		//void dragMoveEvent(QDragMoveEvent *event);
		void dropEvent(QDropEvent *event);
};

#endif
