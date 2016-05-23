#include "mainwindow.h"

MainWindow::MainWindow()
{
	// Widget prncipal
	
	m_top = new QWidget(this);
	setCentralWidget(m_top);
	
	// Nom et taille de la fenêtre
	
	this->setWindowTitle("Analyseur Syntaxical");
	this->resize(900, 600);
	this->move(0,0);
	this->setWindowIcon(QIcon("Images/icone_v2.png"));
	
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
		m_nouveau->setIcon(QIcon("Images/menu_nouveau.png"));
	// m_ouvrir = new QAction("Ouvrir", this);
		// m_ouvrir->setIcon(QIcon("Images/menu_ouvrir.png"));
	m_quitter = new QAction("Quitter", this);
	m_regles = new QAction("Règles de construction", this);
	m_syntaxe = new QAction("Syntaxe de la preuve", this);
	m_verifier = new QAction("Vérifier la preuve", this);
		m_verifier->setIcon(QIcon("Images/menu_verifier.png"));
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
	// Icones (Nouveau, Ouvrir, Vérifier la preuve)
	
	fileToolBar = addToolBar("Fichier");
		fileToolBar->addAction(m_nouveau);
		// fileToolBar->addAction(m_ouvrir);
	fileToolBar = addToolBar("Preuve");
		fileToolBar->addAction(m_verifier);	
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
	connect(m_aide, &QAction::triggered, this, &MainWindow::aide);
	connect(m_propos, &QAction::triggered, this, &MainWindow::propos);
}

void MainWindow::createStatusBar()
{
	statusBar()->showMessage("Prêt");
}

void MainWindow::regles()
{
	// Popup
	
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("Règle de construction");
	
	// m_popup->setText("Regles");
	// QImage aff = QImage("../Images/Aff.png");
	// aff.load();
	
	QLabel *label_aff = new QLabel(m_popup);
	QLabel *label_seq = new QLabel(m_popup);
	QLabel *label_cond = new QLabel(m_popup);
	QLabel *label_conseq = new QLabel(m_popup);
	QLabel *label_while = new QLabel(m_popup);
	QLabel *label_whilet = new QLabel(m_popup);
	
	QLabel *wid_aff = new QLabel("Aff");
	QLabel *wid_seq = new QLabel("Seq");
	QLabel *wid_cond = new QLabel("Cond");
	QLabel *wid_conseq = new QLabel("Conseq");
	QLabel *wid_while = new QLabel("While");
	QLabel *wid_whilet = new QLabel("WhileT");
	
	
	QPixmap *pixmap_aff = new QPixmap("Images/Aff.png");
	QPixmap *pixmap_seq = new QPixmap("Images/Seq.png");
	QPixmap *pixmap_cond = new QPixmap("Images/Cond.png");
	QPixmap *pixmap_conseq = new QPixmap("Images/Conseq.png");
	QPixmap *pixmap_while = new QPixmap("Images/While.png");
	QPixmap *pixmap_whilet = new QPixmap("Images/WhileT.png");
	
	
	label_aff->setPixmap(*pixmap_aff);
	label_seq->setPixmap(*pixmap_seq);
	label_cond->setPixmap(*pixmap_cond);
	label_conseq->setPixmap(*pixmap_conseq);
	label_while->setPixmap(*pixmap_while);
	label_whilet->setPixmap(*pixmap_whilet);
	
 
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
	gridLayout->addWidget(wid_aff, 0, 0, Qt::AlignRight);
	gridLayout->addWidget(label_aff, 0, 1);
	gridLayout->addWidget(wid_seq, 1, 0, Qt::AlignRight);
	gridLayout->addWidget(label_seq, 1, 1);
	gridLayout->addWidget(wid_cond, 2, 0, Qt::AlignRight);
	gridLayout->addWidget(label_cond, 2, 1);
	gridLayout->addWidget(wid_conseq, 3, 0, Qt::AlignRight);
	gridLayout->addWidget(label_conseq, 3, 1);
	gridLayout->addWidget(wid_while, 4, 0, Qt::AlignRight);
	gridLayout->addWidget(label_while, 4, 1);
	gridLayout->addWidget(wid_whilet, 5, 0, Qt::AlignRight);
	gridLayout->addWidget(label_whilet, 5, 1);
	gridLayout->setSpacing(30);
	
	
	
	m_popup->exec();
	
	// QTextEdit *zoneTexte1 = new QTextEdit;
	
	
	// zoneTexte->setWindowTitle("Règle de construction");
	// zoneTexte->setText("coucou");
	
}

void MainWindow::aide()
{
	// Popup
	
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("Aide");
	
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
	
	QLabel *exempleSimple = new QLabel("Exemple (règle AFF) : {x+1 = 43} y:=x+1 {y = 43}");
	
	gridLayout->addWidget(exempleSimple, 0, 0);
	// gridLayout->addWidget(exempleComplexe, 1, 0);
	gridLayout->setSpacing(20);
	
	m_popup->exec();
}

void MainWindow::propos()
{
	// Popup
	
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("À propos");
	
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
		// gridLayout->addWidget(new QLabel("A propos\n\nCet assistant de construction de preuve et analyseur lexical de preuve a été réalisé dans le cadre du projet de licence informatique (3ème année) à Angers.\n\nPierre GRANNIER--RICHARD\nThibaut ROPERCH"), 0, 1);
		// gridLayout->addWidget(new QPixmap("Images/icone_v2.png"), 0, 0);
	gridLayout->setSpacing(30);
	
	m_popup->exec();
}