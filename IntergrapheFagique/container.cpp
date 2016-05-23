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
