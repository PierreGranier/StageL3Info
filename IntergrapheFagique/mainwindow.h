#ifndef mainwindow_h
#define mainwindow_h

#include <QtWidgets/QtWidgets>
#include "container.h"

class MainWindow : public QMainWindow
{
	private:
		QWidget *m_top;
		QVBoxLayout *m_box;
		QScrollArea *m_zoneConteneur;
		QPushButton *m_verifier;
		QToolBar *fileToolBar;
		
	public:
		MainWindow();
		~MainWindow();
		
		void createToolBar();
};

#endif