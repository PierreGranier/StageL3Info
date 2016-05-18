#include "mainwindow.h"

MainWindow::MainWindow()
{
	// Widget prncipal
	
	m_top = new QWidget(this);
	setCentralWidget(m_top);
	
	// Nom et taille de la fenêtre
	
	this->setWindowTitle("Analyseur Syntaxical");
	this->resize(900, 600);
	
	// Layout appliqué au top
	
	m_box = new QVBoxLayout(m_top);
	m_top->setLayout(m_box);
	
	// ZoneConteneur est une ScrollArea dans la box
	
	m_zoneConteneur = new QScrollArea(m_top);
	m_box->addWidget(m_zoneConteneur);
	
	// Widgets internes en pleine page
	
	m_zoneConteneur->setWidgetResizable(true);
	
	// Container dans la zoneConteneur
	
	Container *conteneur = new Container(m_zoneConteneur);
	m_zoneConteneur->setWidget(conteneur);
	// m_zoneConteneur->setAlignment(Qt::AlignHCenter);
	
	// Bouton de vérification dans la box
	
	m_bouttonVerifier = new QPushButton("Vérifier la preuve", m_top);
	m_box->addWidget(m_bouttonVerifier);
	
	// Console de sortie

		// Les box qui se redimensionnent ! :)
	
	// Actions, ToolBar, Statusbar
	
	this->createActions();
	this->createToolBar();
	this->createStatusBar();
	
	// ?
	
	setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createActions()
{
	// Menu (Fichier -> Nouveau, Fichier -> Quitter, Preuve -> Règles, Preuve -> Vérifier)

	//menuBar()->addAction("GTFE");

	QMenu *fichier = menuBar()->addMenu("Fichier");
		m_nouveau = fichier->addAction("Nouveau");
		m_quitter = fichier->addAction("Quitter");
	QMenu *preuve = menuBar()->addMenu("Preuve");
		m_regles = preuve->addAction("Règles de construction");
		m_syntaxe = preuve->addAction("Syntaxe de la preuve");
		m_verifier = preuve->addAction("Vérifier la preuve");
	QMenu *pi = menuBar()->addMenu("?");
		m_aide = pi->addAction("Aide");
		m_propos = pi->addAction("A propos");
}

void MainWindow::createToolBar()
{
	// Icones (Nouveau, Vérifier la preuve)

	fileToolBar = addToolBar("File");
	fileToolBar->addAction("Importer");
	QAction* quit= fileToolBar->addAction("Quitter"); // TODO stocker l'action qui en attribut
	
	// http://doc.qt.io/qt-4.8/qdialog.html

	/*const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
	QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
	newLetterAct->setShortcuts(QKeySequence::New);
	newLetterAct->setStatusTip(tr("Create a new form letter"));
	connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
	fileMenu->addAction(newLetterAct);
	fileToolBar->addAction(newLetterAct);*/


	connect(quit, &QAction::triggered, this, &QMainWindow::close);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage("Prêt");
}

MainWindow::~MainWindow()
{
	delete m_top;
}
