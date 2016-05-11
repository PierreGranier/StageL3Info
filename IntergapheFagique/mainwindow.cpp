#include "mainwindow.h"

MainWindow::MainWindow() {
    m_leftButtonClick = false;
    
    m_top = new QWidget(this);
	
	setCentralWidget(m_top);
	
	// La box dans le top
	
	m_box = new QVBoxLayout(m_top);
	m_top->setLayout(m_box);
	
	// Le dock 1 dans la box - dans la window
	
	m_dock1 = new QDockWidget("Figures :", m_top);
	m_dock1->setFeatures(QDockWidget::DockWidgetMovable);
	
	QLabel *label1 = new QLabel("Figures :", m_dock1);
	label1->setMargin(20);
	m_dock1->setTitleBarWidget(label1);
	
	QListWidget *liste1 = new QListWidget(m_dock1);
	liste1->addItems(QStringList()
		<< "Triangle"
		<< "Carré"
		<< "Cercle");
	liste1->setSelectionMode(QAbstractItemView::SingleSelection); // pour drag&drop
	liste1->setDragEnabled(true); // pour drag&drop
	liste1->setDragDropMode(QAbstractItemView::DragDrop); // pour drag&drop (http://doc.qt.io/qt-4.8/qabstractitemview.html#DragDropMode-enum)
	liste1->setDropIndicatorShown(true); // pour drag&drop
	liste1->viewport()->setAcceptDrops(true); // pour drag&drop (ajouter un item dans la liste)
	m_dock1->setWidget(liste1);
	
	this->addDockWidget(Qt::LeftDockWidgetArea, m_dock1); // addDockWidget est définie dans QMainWindow (donc this)
	
	// Le dock 2 dans la box - dans la window
	
	m_dock2 = new QDockWidget("Couleurs :", m_top);
	m_dock2->setFeatures(QDockWidget::DockWidgetMovable);
	
	QLabel *label2 = new QLabel("Couleurs :", m_dock2);
	label2->setMargin(20);
	m_dock2->setTitleBarWidget(label2);
	
	QListWidget *liste2 = new QListWidget(m_dock2);
	liste2->setDragEnabled(true);
	liste2->addItems(QStringList()
		<< "Bleu"
		<< "Vert"
		<< "Rouge");
	liste2->setSelectionMode(QAbstractItemView::SingleSelection); // pour drag&drop
	liste2->setDragEnabled(true); // pour drag&drop
	liste2->setDragDropMode(QAbstractItemView::DragDrop); // pour drag&drop (http://doc.qt.io/qt-4.8/qabstractitemview.html#DragDropMode-enum)
	liste2->setDropIndicatorShown(true); // pour drag&drop
	liste2->viewport()->setAcceptDrops(true); // pour drag&drop (ajouter un item dans la liste)
	m_dock2->setWidget(liste2);
	
	addDockWidget(Qt::RightDockWidgetArea, m_dock2); // addDockWidget est définie dans QMainWindow (donc this)
	
	// Le container dans la zoneConteneur dans la box
	
	m_zoneConteneur = new QScrollArea(m_top);
	
	Container *conteneur = new Container(m_top);
	m_zoneConteneur->setWidget(conteneur);
	
	m_box->addWidget(m_zoneConteneur);
}

MainWindow::~MainWindow() {
	delete m_top;
}
