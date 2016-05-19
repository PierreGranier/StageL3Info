#include "mainwindow.h"

MainWindow::MainWindow()
{
	// Widget prncipal
	
	m_top = new QWidget(this);
	setCentralWidget(m_top);
	
	// Nom et taille de la fenêtre
	
	this->setWindowTitle("Analyseur Syntaxical");
	this->resize(900, 600);
	this->setWindowIcon(QIcon("icone_triangle.png"));
	
	// Layout appliqué au top
	
	m_box = new QVBoxLayout(m_top);
	//m_top->setLayout(m_box);
	
	// Splitter
	
	m_splitter = new QSplitter(m_top);
	m_splitter->setOrientation(Qt::Vertical);
	m_box->addWidget(m_splitter);
	
	// Zone de la preuve
	
	m_zonePreuve = new QWidget(m_splitter);
	m_box->addWidget(m_zonePreuve);
	QVBoxLayout *layoutPreuve = new QVBoxLayout(m_zonePreuve);
		layoutPreuve->addWidget(new QLabel("Zone de construction de preuve", m_zonePreuve));
		// ZoneConteneur est une ScrollArea
		m_zoneConteneur = new QScrollArea(m_zonePreuve);
		// Widgets internes en pleine page
		m_zoneConteneur->setWidgetResizable(true);
		m_zoneConteneur->setAlignment(Qt::AlignHCenter);
		// Container dans la zoneConteneur
		m_conteneur = new Container(m_zoneConteneur);
		m_zoneConteneur->setWidget(m_conteneur);
		// ZoneContainer dans le layout Preuve
		layoutPreuve->addWidget(m_zoneConteneur);
	
	// Zone de la sortie de la vérification
	
	m_zoneSortie = new QWidget(m_splitter);
	m_box->addWidget(m_zoneSortie);
	QVBoxLayout *layoutSortie = new QVBoxLayout(m_zoneSortie);
		layoutSortie->addWidget(new QLabel("Sortie", m_zoneSortie));
		// ZoneConsole est une ScrollArea
		m_zoneConsole = new QScrollArea(m_zonePreuve);
		// Widgets internes en pleine page
		m_zoneConsole->setWidgetResizable(true);
		m_zoneConsole->setAlignment(Qt::AlignHCenter);
		// Console dans la ZoneConsole
		m_console = new Console(m_zoneConsole);
		m_zoneConsole->setWidget(m_console);
		// ZoneConsole dans le layout Sortie
		layoutSortie->addWidget(m_zoneConsole);

	// Dans le splitter
	
	m_splitter->addWidget(m_zonePreuve);
	m_splitter->addWidget(m_zoneSortie);
	
	// Actions, MenuBar, ToolBar, Signaux, StatusBar
	
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
	
	fileToolBar = addToolBar("Fichier");
		fileToolBar->addAction(m_nouveau);
		fileToolBar->addAction(m_verifier);
		
	/*const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
	QAction *newLetterAct = new QAction(newIcon, tr("&New Letter"), this);*/
}

void MainWindow::createSignals()
{
    connect(m_quitter, &QAction::triggered, this, &QMainWindow::close);
    connect(m_nouveau, &QAction::triggered, m_conteneur, &Container::initialiser);
    connect(m_nouveau, &QAction::triggered, m_console, &Console::vider);
    connect(m_verifier, &QAction::triggered, m_conteneur, &Container::verifier);
    connect(m_conteneur, &Container::analyseurSyntaxical, m_console, &Console::ecrire);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage("Prêt");
}

MainWindow::~MainWindow()
{
	delete m_top;
}
