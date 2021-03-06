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
	this->setWindowIcon(QIcon("Images/icone_v4.png"));
	
	// Layout appliqué au top
	
	m_box = new QVBoxLayout(m_top);
	
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
	m_splitter->setStretchFactor(0, 1);
	
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
	m_ouvrir = new QAction("Ouvrir", this);
		m_ouvrir->setIcon(QIcon("Images/menu_ouvrir.png"));
	m_quitter = new QAction("Quitter", this);
		m_quitter->setIcon(QIcon("Images/menu_fermer.png"));
	m_regles = new QAction("Règles de construction", this);
		m_regles->setIcon(QIcon("Images/3p_v2.png"));
	m_verifier = new QAction("Vérifier la preuve", this);
		m_verifier->setIcon(QIcon("Images/menu_verifier.png"));
	m_aide = new QAction("Aide", this);
	m_propos = new QAction("À propos", this);
}

void MainWindow::createMenuBar()
{
	// Menu (Fichier -> Nouveau, Fichier -> Quitter, Preuve -> Règles, Preuve -> Vérifier)
	
	QMenu *fichier = menuBar()->addMenu("Fichier");
		fichier->addAction(m_nouveau);
		fichier->addAction(m_ouvrir);
		fichier->addSeparator();
		fichier->addAction(m_quitter);
	QMenu *preuve = menuBar()->addMenu("Preuve");
		preuve->addAction(m_regles);
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
		fileToolBar->addAction(m_ouvrir);
	fileToolBar = addToolBar("Preuve");
		fileToolBar->addAction(m_verifier);
}

void MainWindow::createSignals()
{
	connect(m_quitter, &QAction::triggered, this, &QMainWindow::close);
	
	connect(m_nouveau, &QAction::triggered, m_conteneur, &Container::initialiser);
	connect(m_nouveau, &QAction::triggered, m_console, &Console::vider);
	connect(m_ouvrir, &QAction::triggered, m_conteneur, &Container::initialiser);
	connect(m_ouvrir, &QAction::triggered, m_console, &Console::vider);
	connect(m_ouvrir, &QAction::triggered, this, &MainWindow::ouvrir);
	//connect(m_ouvrirFichier, &QPushButton::triggered, m_conteneur, &Container::ouvrirPreuve);
	//connect(m_ouvrirTexte, &QPushButton::triggered, m_conteneur, &Container::lirePreuve);

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
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("Règles de construction");
	
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
	gridLayout->addWidget(new QLabel("<h2>Règles de construction</h2><hr><br/>", m_popup), 0, 0, 1, 2);
	gridLayout->addWidget(wid_aff, 1, 0, Qt::AlignRight);
	gridLayout->addWidget(label_aff, 1, 1);
	gridLayout->addWidget(wid_seq, 2, 0, Qt::AlignRight);
	gridLayout->addWidget(label_seq, 2, 1);
	gridLayout->addWidget(wid_cond, 3, 0, Qt::AlignRight);
	gridLayout->addWidget(label_cond, 3, 1);
	gridLayout->addWidget(wid_conseq, 4, 0, Qt::AlignRight);
	gridLayout->addWidget(label_conseq, 4, 1);
	gridLayout->addWidget(wid_while, 5, 0, Qt::AlignRight);
	gridLayout->addWidget(label_while, 5, 1);
	gridLayout->addWidget(wid_whilet, 6, 0, Qt::AlignRight);
	gridLayout->addWidget(label_whilet, 6, 1);
	gridLayout->setSpacing(30);
	
	m_popup->exec();
}

void MainWindow::aide()
{
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("Aide");
	
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
	
	QLabel *label_exemple = new QLabel(m_popup);
	QLabel *wid_exemple = new QLabel("<h2>Exemple complexe<h2><hr>");
	QLabel *label_explication = new QLabel("<h3>Explication<h3>");
	QLabel *label_aide = new QLabel("Contrairement à ce qui est indiqué dans l'onglet \"Règle de construction\" ");
	
	QPixmap *pixmap_exemple = new QPixmap("Images/exemple.png");
	
	label_exemple->setPixmap(*pixmap_exemple);
	
	gridLayout->addWidget(wid_exemple, 0, 0, 1, 2);
	gridLayout->addWidget(label_exemple, 1, 1);
	gridLayout->addWidget(label_explication, 2, 0);
	gridLayout->addWidget(label_aide, 2, 1);
	
	gridLayout->setSpacing(20);
	
	m_popup->exec();
}

void MainWindow::propos()
{
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("À propos");

	QLabel *icone = new QLabel(m_popup);

	QLabel* texte= new QLabel("<h2>À propos</h2><hr><br/>Cet assistant de construction de preuve et analyseur lexical de preuve<br/>"
		"a été réalisé dans le cadre d'un projet de troisième année de licence informatique<br/>"
		"à l'Université d'Angers.<br/><br/><b>Auteurs :</b><br/>"
		"<br/>Pierre GRANNIER--RICHARD<br/>Thibaut ROPERCH<br/><br/>"
		"<b>Projet :</b><br/><br/>"
		"<a href='https://PierreGranier.github.io/StageL3Info'>https://PierreGranier.github.io/StageL3Info</a><br/><br/>"
		"© 2016");
		texte->setOpenExternalLinks(true);
		
	QPixmap icone_img = QPixmap("Images/icone_v4.png");
	icone->setPixmap(icone_img);
	
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
		gridLayout->addWidget(icone, 0, 0);
		gridLayout->addWidget(texte, 0, 1, Qt::AlignTop);
		gridLayout->setSpacing(30);
	m_popup->exec();
}

void MainWindow::ouvrir()
{
	m_popup = new QDialog(this);
	m_popup->setWindowTitle("Ouvrir une preuve");
	
	QGridLayout *gridLayout = new QGridLayout;
	m_popup->setLayout(gridLayout);
		QLabel *phrase = new QLabel("Veuillez choisir le format de preuve à ouvrir", m_popup);
		QPushButton *ouvrirFichier = new QPushButton("Ouvrir le fichier", m_popup);
			ouvrirFichier->setMinimumWidth(90);
			connect(ouvrirFichier, &QPushButton::clicked, m_conteneur, &Container::ouvrirPreuve);
			connect(ouvrirFichier, &QPushButton::clicked, m_popup, &QDialog::close);
		QPushButton *ouvrirTexte = new QPushButton("Entrer une preuve", m_popup);
			ouvrirTexte->setMinimumWidth(90);
			connect(ouvrirTexte, &QPushButton::clicked, m_conteneur, &Container::lirePreuve);
			connect(ouvrirTexte, &QPushButton::clicked, m_popup, &QDialog::close);
		gridLayout->addWidget(phrase, 0, 0, 1, 2);
		gridLayout->addWidget(ouvrirFichier, 1, 0);
		gridLayout->addWidget(ouvrirTexte, 1, 1);
		gridLayout->setSpacing(10);
	m_popup->exec();
}
