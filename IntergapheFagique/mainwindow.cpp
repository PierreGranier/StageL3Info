#include "mainwindow.h"

MainWindow::MainWindow()
{
	m_top = new QWidget(this);
	
	setCentralWidget(m_top);
	
	// Layout appliqué au top
	
	m_box = new QVBoxLayout(m_top);
	m_top->setLayout(m_box);
	
	// zoneConteneur est une ScrollArea
	
	m_zoneConteneur = new QScrollArea(m_top);
	
	// Un container dans la zoneConteneur
	
	Container *conteneur = new Container(m_zoneConteneur);
	m_zoneConteneur->setWidget(conteneur);
	
	// La zoneConteneur dans la box
	
	m_box->addWidget(m_zoneConteneur);
	
	// Toolbar haute horizontale
	
	this->createToolBar();
}

void MainWindow::createToolBar() {
	/*menuBar()->addAction("Fichier");
	QMenu* menuSave= menuBar()->addMenu("Others");
		QAction* saveDataAction = menuSave->addAction("Bob");
	QMenuBar * fileMenu = menuBar();
		fileMenu->addMenu("File");*/
	
	fileToolBar = addToolBar("File");
	fileToolBar->addAction("Importer");
	fileToolBar->addAction("Quitter");
}

MainWindow::~MainWindow() {
	delete m_top;
}
