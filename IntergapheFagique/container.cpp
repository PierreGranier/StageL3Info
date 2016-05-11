#include "container.h"

Container::Container(QWidget *parent) : QWidget(parent) {
	this->resize(4000, 4000);
	this->setStyleSheet("background-color:white;");
	
	this->setAcceptDrops(true); // pour drag&drop
	
	// Ajout d'une figure test dans le container
	
	//this->addWidget(new Carre(this)); // can't add a widget to a widget
	
	/*m_box = new QVBoxLayout(this);
	m_box->setContentsMargins(0, 0, 0, 0);
	//m_box->setDirection(QBoxLayout::RightToLeft);
	this->setLayout(m_box); // set la disposition du widget
	
	Figure *triangle = new Triangle(this);
	Figure *carre = new Carre(this);
	Figure *rond = new Rond(this);
	m_box->addWidget(triangle);
	m_box->addWidget(carre);
	m_box->addWidget(rond);*/
	
	// insertWidget à l'indice 0 permet d'ajouter en haut
}

void Container::dragEnterEvent(QDragEnterEvent *event) {
	qDebug() << "dragEnterEvent";
	event->acceptProposedAction();
}

/*void Container::dragMoveEvent(QDragMoveEvent *event) {
	qDebug() << "dragMoveEvent";
	event->accept();
	//if(event->source() != this) event->accept();
	//else event->ignore();
}*/

void Container::dropEvent(QDropEvent *event) {
	qDebug() << "dropEvent";
	//qDebug() << event->source();
	QListWidget *listRecup = qobject_cast<QListWidget *>(event->source());
	//qDebug() << listRecup->currentItem()->text();
	QString nomItem = QString(listRecup->currentItem()->text());
	
	/*if(nomItem == "Triangle" || nomItem == "Carré" || nomItem == "Cercle") {
		Figure *figure;
		
		if(nomItem == "Triangle")
			figure = new Triangle(this);
		else if(nomItem == "Carré")
			figure = new Carre(this);
		else if(nomItem == "Cercle")
			figure = new Rond(this);
	
		figure->move(event->pos());
		figure->setPositionAbsolue(event->pos());
		figure->show();
	}*/
	
	//event->acceptProposedAction();
}
