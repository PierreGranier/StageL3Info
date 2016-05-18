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

		QAction *m_nouveau;
		QAction *m_quitter;
		QAction *m_regles;
		QAction *m_syntaxe;
		QAction *m_verifier;
		QAction *m_aide;
		QAction *m_propos;

		QToolBar *fileToolBar;
		
	public:
		MainWindow();
		~MainWindow();
		
		void createActions();
		void createToolBar();
		void createStatusBar();
};

#endif
