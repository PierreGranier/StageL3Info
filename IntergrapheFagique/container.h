#ifndef container_h
#define container_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QInputDialog>
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include "widgetracine.h"
#include "widgetregleaff.h"
#include "widgetregleseq.h"
#include "widgetreglecond.h"
#include "widgetregleconseq.h"
#include "widgetreglewhile.h"
#include "widgetreglewhilet.h"
#include "preuvelineaire.h"

class Container : public QWidget
{
	Q_OBJECT
	
	private:
		QVBoxLayout *m_ens;
		
		QImage *m_buffer;
		QPainter *m_bufferPainter;
		
		WidgetRacine *m_racine;
		
	public:
		Container(QWidget *parent);
		~Container();
		
		void paintEvent(QPaintEvent *event);
		
	public slots:
		void initialiser();
		void ouvrirPreuve(/*const std::string &fichier*/);
		void lirePreuve();
		void creerPreuve(const std::string &chaine);
		void verifierPreuve() const;
		void executerAnalyseur(const std::string &fichier) const;
		
	signals:
		void verifierFichier(const std::string &fichier) const;
		void resultatAnalyseur(const std::string &message) const;	
};

#endif
