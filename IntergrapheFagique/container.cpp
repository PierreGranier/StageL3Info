#include "container.h"

using namespace std;

Container::Container(QWidget *parent) : QWidget(parent)
{
	m_ens = new QVBoxLayout(this);
	
	m_ens->addStretch(1);
	
	this->initialiser();
}

Container::~Container()
{
	
}

void Container::paintEvent(QPaintEvent *event)
{
	m_buffer = new QImage(size(), QImage::Format_RGB32);
	m_buffer->fill(Qt::white);
	
	m_bufferPainter = new QPainter(m_buffer);
	m_bufferPainter->setPen(Qt::black);
	m_bufferPainter->setRenderHint(QPainter::Antialiasing, true);
		
	QPainter p(this);
	p.drawImage(0, 0, *m_buffer);
}

void Container::initialiser()
{
	delete m_racine;
	m_racine = new WidgetRacine(this);
	m_ens->addWidget(m_racine);
}

void Container::ouvrirPreuve(/*const std::string &fichier*/)
{
	// Initialisation de la preuve de type PreuveLineaire (type héritant de string)
	
	ifstream fichierPreuve("test.txt", ios::in);
	string chainePreuve;
	getline(fichierPreuve, chainePreuve);
	// getline(fichierPreuve, string chainePreuve);
	PreuveLineaire preuve = chainePreuve;
	
	// Initialisation de la pile FILO contenant les WidgetRegle à créer
	
	stack<WidgetRegle*> regles;
	regles.push(m_racine);
	
	// Lecture de la preuve linéaire et ajout des WidgetRegle comme il faut
	
	while(!preuve.empty() && !regles.empty())
	{
		WidgetRegle *newWidget;
		
		if(preuve.commencePar("AFF"))
			newWidget = new WidgetRegleAff(this);
		else if(preuve.commencePar("SEQ"))
			newWidget = new WidgetRegleSeq(this);
		else if(preuve.commencePar("COND"))
			newWidget = new WidgetRegleCond(this);
		else if(preuve.commencePar("CONSEQ"))
			newWidget = new WidgetRegleConseq(this);
		else if(preuve.commencePar("WHILE"))
			newWidget = new WidgetRegleWhile(this);
		else if(preuve.commencePar("WHILET"))
			newWidget = new WidgetRegleWhileT(this);
		
		// Enlève la règle à la preuve linéaire
		// preuve.tronquerRegle();
		// Edition du triplet du premier WidgetRegle de la pile
		// regles.top()->modifierTriplet(preuve.triplet());
		// Enlève le triplet à la preuve linéaire
		// preuve.tronquerTriplet();
		// Ajout du WidgetRegle créé au premier WidgetRegle de la pile
		regles.top()->ajouterSousPreuve(newWidget);
		// Ajout du WidgetRegle créé à la pile
		regles.push(newWidget);
		
		// Nettoyage de la pile : enlève les WidgetRegle pleins
		
		// Affichage de la tronche de la pile
		stack<WidgetRegle*> save = regles; cout << "Avant nettoyage : " << endl; while(!save.empty()) { cout << "|" << save.top()->toString() << ">" << endl; save.pop(); }

		while(regles.top()->estPlein())
		{
			regles.pop();
		}
		
		// Affichage de la tronche de la pile
		save = regles; cout << "Après nettoyage : " << endl; while(!save.empty()) { cout << "|" << save.top()->toString() << ">" << endl; save.pop(); }
	}
	
	if(preuve.empty()) cout << "Ligne preuve vide" << endl;
	if(regles.empty()) cout << "Pile preuves vide" << endl;
}

void Container::verifierPreuve() const
{
	// Créé le fichier et l'envoie dans un signal
	
	string res = m_racine->toString();
	ofstream fichierRes("fichierRes.txt", ios::out);
	if(fichierRes)
	{
		//cout << m_racine->toString() << endl;
		fichierRes << res << endl;
		fichierRes << endl;
		fichierRes.close();
	}
	else
	{
		cout << "Erreur lors de l'ouverture du fichier" << endl;
	}

    // cout << m_racine->toString() << endl;
	emit verifierFichier("../IntergrapheFagique/fichierRes.txt");
}

void Container::executerAnalyseur(const string &fichier) const
{
	// Execute le programme avec le fichier créé et envoie le résultat dans un signal

	QString prog = "verificateur";
	
	string resAnalyseur = "../IntergrapheFagique/resAnalyseur.txt";
	
    string commande= "cd ../AnalyseurSyntaxical/ ; ./verificateur " + fichier + ">" + resAnalyseur; //#CoursD'Unix 4Ever
    // string commande= "START ../AnalyseurSyntaxical/verificateur.exe " + fichier + "1>" + resAnalyseur; //#WindowsDaubé
	
    system(commande.c_str());
	
	// Maintenant on lit le fichier pour écrire le résultat de l'Analyseur dans la console
	
	ifstream fichierResAnalyseur(resAnalyseur, ios::in);
	if(fichierResAnalyseur)
	{
		// {1>0} x:=1 {1>0}		Ouais heu c'est pour des tests
		
		string res;
		string resFinal = "";
		
		emit resultatAnalyseur("Exécution de l'analyseur syntaxique...\n\n");
		
		while(!fichierResAnalyseur.eof())
		{
			getline(fichierResAnalyseur, res);
			emit resultatAnalyseur(res+"\n");
			resFinal += res;
		}
		
		if(resFinal.compare("") == 0)
		{
			emit resultatAnalyseur("Aucune erreur, la preuve est vérifiée.");
		}
		else
		{
			emit resultatAnalyseur("Une ou plusieurs erreurs ont été trouvée(s).");
		}
		
		fichierResAnalyseur.close();
	}
	
	else 
	{
		cout << "Erreur lors de l'ouverture du fichier" << endl;
	}
}
