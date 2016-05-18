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
	
	m_conteneur = new Container(m_zoneConteneur);
	m_zoneConteneur->setWidget(conteneur);
	m_zoneConteneur->setAlignment(Qt::AlignHCenter);
	
	// Bouton de vérification dans la box
	
	m_bouttonVerifier = new QPushButton("Vérifier la preuve", m_top);
	m_box->addWidget(m_bouttonVerifier);
	
	// Console de sortie
	
		// Les box qui se redimensionnent ! :)
	
	// Actions, ToolBar, Signaux, StatusBar
	
	this->createActions();
	this->createMenuBar();
	this->createToolBar();
	this->createSignals();
	this->createStatusBar();
	
	// Marche pas sur Linux
	
	setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createActions()
{
	// Menu (Fichier -> Nouveau, Fichier -> Quitter, Preuve -> Règles, Preuve -> Vérifier)	
	
	m_nouveau = new QAction("Nouveau", this);
	m_quitter = new QAction("Quitter", this);
	m_regles = new QAction("Règles de construction", this);
	m_syntaxe = new QAction("Syntaxe de la preuve", this);
	m_verifier = new QAction("Vérifier la preuve", this);
	m_aide = new QAction("Aide", this);
	m_propos = new QAction("A propos", this);
}
void MainWindow::createMenuBar()
{
	//menuBar()->addAction("GTFE");
	
	QMenu *fichier = menuBar()->addMenu("Fichier");
		fichier->addAction(m_nouveau);
		fichier->addAction(m_quitter);
	QMenu *preuve = menuBar()->addMenu("Preuve");
		preuve->addAction(m_regles);
		preuve->addAction(m_syntaxe);
		preuve->addAction(m_verifier);
	QMenu *pi = menuBar()->addMenu("?");
		pi->addAction(m_aide);
		pi->addAction(m_propos);
}

void MainWindow::createToolBar()
{
	// Icones (Nouveau, Vérifier la preuve)
	
	fileToolBar = addToolBar("Bob");
		fileToolBar->addAction(m_nouveau);
		fileToolBar->addAction(m_verifier);
		fileToolBar->addAction(m_quitter);
	
	QAction* quitter = fileToolBar->addAction("Quittedzeer");
	
	// http://doc.qt.io/qt-4.8/qdialog.html

	/*const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
	QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);
	newLetterAct->setShortcuts(QKeySequence::New);
	newLetterAct->setStatusTip(tr("Create a new form letter"));
	connect(newLetterAct, &QAction::triggered, this, &MainWindow::newLetter);
	fileMenu->addAction(newLetterAct);
	fileToolBar->addAction(newLetterAct);*/
}

void MainWindow::createSignals()
{
	// connect(m_nouveau, &QAction::triggered, m_conteneur, &Container::initialiser);
	// connect(quitter, &QAction::triggered, this, &QMainWindow::close);
	// connect(m_verifier, &QAction::triggered, m_conteneur, &Container::afficher);
	// connect(m_quitter, &QAction::triggered, this, &QMainWindow::close);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage("Prêt");
}

MainWindow::~MainWindow()
{
	delete m_top;
}
