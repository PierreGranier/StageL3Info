#include "mainwindow.h"

MainWindow::MainWindow()
{
	// Widget prncipal
	
	m_top = new QWidget(this);
	setCentralWidget(m_top);
	
	// Nom et taille de la fenêtre
	
	this->setWindowTitle("Analyseur Syntaxical");
	this->resize(900, 600);
	this->setWindowIcon(QIcon("icone_triangle2.png"));
	
	// Popup
	
	m_popup = new QMessageBox(this);
	m_popup->setIcon(QMessageBox::NoIcon);
	
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
		layoutPreuve->addWidget(new QLabel("Construction de preuve arborescente", m_zonePreuve));
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
		layoutSortie->addWidget(new QLabel("Sortie de l'analyseur lexical", m_zoneSortie));
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

MainWindow::~MainWindow()
{
	delete m_top;
}

void MainWindow::createActions()
{
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
	// Menu (Fichier -> Nouveau, Fichier -> Quitter, Preuve -> Règles, Preuve -> Vérifier)	

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
	connect(m_verifier, &QAction::triggered, m_console, &Console::vider);
    connect(m_verifier, &QAction::triggered, m_conteneur, &Container::verifierPreuve);
    connect(m_conteneur, &Container::verifierFichier, m_conteneur, &Container::executerAnalyseur);
    connect(m_conteneur, &Container::resultatAnalyseur, m_console, &Console::ecrire);
	
    connect(m_regles, &QAction::triggered, this, &MainWindow::regles);
    connect(m_syntaxe, &QAction::triggered, this, &MainWindow::syntaxe);
    connect(m_aide, &QAction::triggered, this, &MainWindow::aide);
    connect(m_propos, &QAction::triggered, this, &MainWindow::propos);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage("Prêt");
}

void MainWindow::regles()
{
	m_popup->setText("Regles");
	//QImage aff = QImage("../Images/Aff.png");
	// aff.load();
	
	QLabel  *label_img  = new QLabel(this);
	QPixmap *pixmap_img = new QPixmap("Images/Aff.png");
    label_img->setPixmap(*pixmap_img);
 
	QGridLayout *gridLayout = new QGridLayout;

	gridLayout->addWidget(label_img);
	
	m_popup->exec();
}

void MainWindow::syntaxe() const
{
	m_popup->setText("Syntaxe syntaxicale");
	m_popup->exec();
}

void MainWindow::aide() const
{
	m_popup->setText("A l'aiiiiide");
	m_popup->exec();
}

void MainWindow::propos() const
{
	m_popup->setText("A propos\n\nCet assistant de construction de preuve et analyseur lexical de preuve a été réalisé dans le cadre du projet de licence informatique (3ème année) à Angers.\n\nPierre GRANNIER--RICHARD\nThibaut ROPERCH");
	m_popup->exec();
}