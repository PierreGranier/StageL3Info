#ifndef mainwindow_h
#define mainwindow_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include "container.h"

class MainWindow : public QMainWindow
{
	private:
		bool m_leftButtonClick;
		QWidget *m_top;
		QVBoxLayout *m_box;
		QScrollArea *m_zoneConteneur;
		
	public:
		MainWindow();
		~MainWindow();
		
		void createMenus();
};

#endif
