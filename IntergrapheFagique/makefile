MOC= /usr/lib/x86_64-linux-gnu/qt5/bin/moc

all:
	clear
	$(MOC) widgetajouter.h -o moc_widgetajouter.cpp
	$(MOC) widgetreglesimple.h -o moc_widgetreglesimple.cpp
	$(MOC) widgetregledouble.h -o moc_widgetregledouble.cpp
	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 main.cpp mainwindow.cpp container.cpp widgetajouter.cpp moc_widgetajouter.cpp widgetracine.cpp widgettriplet.cpp widgetregle.cpp widgetregledouble.cpp widgetreglesimple.cpp moc_widgetreglesimple.cpp moc_widgetregledouble.cpp widgetregleaff.cpp -l Qt5Widgets -l Qt5Core -l Qt5Gui -o NomApp

launch:
	./NomApp