#include "mainwindow.h"

MainWindow::MainWindow()
{
	m_top = new QWidget(this);
	
	setCentralWidget(m_top);
	
	// La box dans le top
	
	m_box = new QVBoxLayout(m_top);
	m_top->setLayout(m_box);
	
	// Le container dans la zoneConteneur dans la box
	
	m_zoneConteneur = new QScrollArea(m_top);
	
	Container *conteneur = new Container(m_top);
	m_zoneConteneur->setWidget(conteneur);
	
	m_box->addWidget(m_zoneConteneur);
}

void MainWindow::createToolBar() {
	/*menuBar()->addAction("Fichier");
	QMenu* menuSave= menuBar()->addMenu("Others");
		QAction* saveDataAction = menuSave->addAction("Bob");
	QMenuBar * fileMenu = menuBar();
		fileMenu->addMenu("File");*/
		
	this->createToolBar();
	fileToolBar = addToolBar("File");
	fileToolBar->addAction("Importer");
	fileToolBar->addAction("Quitter");
}

MainWindow::~MainWindow() {
	delete m_top;
}
