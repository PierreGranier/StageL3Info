#ifndef console_h
#define console_h

#include <QtWidgets/QWidget>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QLabel>
#include <iostream>
#include <string>

class Console : public QWidget
{
	private:
		QVBoxLayout *m_ens;

		QLabel *m_message;

	public:
		Console(QWidget *parent);
		~Console();

	public slots:
		void ecrire(const std::string &message);
};

#endif
