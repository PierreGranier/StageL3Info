MOC= /usr/lib/x86_64-linux-gnu/qt5/bin/moc

all:
	clear
	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 main.cpp mainwindow.cpp container.cpp widgetajouter.cpp moc_widgetajouter.cpp widgetregle.cpp widgetregleaxiome.cpp widgetreglesimple.cpp widgetregledouble.cpp moc_widgetreglesimple.cpp moc_widgetregledouble.cpp widgettriplet.cpp widgetnomregle.cpp -l Qt5Widgets -l Qt5Core -l Qt5Gui -o NomApp

moc:
	$(MOC) widgetajouter.h -o moc_widgetajouter.cpp
	$(MOC) widgetreglesimple.h -o moc_widgetreglesimple.cpp
	$(MOC) widgetregledouble.h -o moc_widgetregledouble.cpp

launch:
	./NomApp