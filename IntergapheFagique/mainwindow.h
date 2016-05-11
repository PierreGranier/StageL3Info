#ifndef mainwindow_h
#define mainwindow_h

#include "QtWidgets/QtWidgets"
#include "container.h"

class MainWindow : public QMainWindow
{
	private:
		bool m_leftButtonClick;
		QWidget *m_top;
		QVBoxLayout *m_box;
		QDockWidget *m_dock1;
		QDockWidget *m_dock2;
		QScrollArea *m_zoneConteneur;
		
	public:
		MainWindow();
		~MainWindow();
};

#endif
