#ifndef mainwindow_h
#define mainwindow_h

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMessageBox>
#include "container.h"
#include "console.h"

class MainWindow : public QMainWindow
{
	private:
		QWidget *m_top;
		QVBoxLayout *m_box;
		
		QWidget *m_zonePreuve;
		QWidget *m_zoneSortie;
		QSplitter *m_splitter;
		
		QScrollArea *m_zoneConteneur;
		Container *m_conteneur;
		
		QScrollArea *m_zoneConsole;
		Console *m_console;
		
		QAction *m_nouveau;
		QAction *m_quitter;
		QAction *m_regles;
		QAction *m_syntaxe;
		QAction *m_verifier;
		QAction *m_aide;
		QAction *m_propos;
		
		QToolBar *fileToolBar;
		
		QMessageBox *m_popup;
		
	public:
		MainWindow();
		~MainWindow();
		
		void createActions();
		void createMenuBar();
		void createToolBar();
		void createSignals();
		void createStatusBar();
		
	public slots:
		void regles();
		void syntaxe() const;
		void aide() const;
		void propos() const;
};

#endif
