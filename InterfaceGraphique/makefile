MOC= /usr/lib/x86_64-linux-gnu/qt5/bin/moc

all:
	clear
	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 main.cpp mainwindow.cpp container.cpp moc_container.cpp console.cpp widgetajouter.cpp widgetsupprimer.cpp moc_widgetajouter.cpp widgetregle.cpp widgetregleaxiome.cpp widgetreglesimple.cpp widgetregledouble.cpp widgettriplet.cpp widgetnomregle.cpp -l Qt5Widgets -l Qt5Core -l Qt5Gui -o NomApp


# mainwindow.o : mainwindow.cpp mainwindow.h
# 	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 $< -c -l Qt5Widgets -l Qt5Core -l Qt5Gui

# container.o : container.cpp container.h
# 	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 $< -c -l Qt5Widgets -l Qt5Core -l Qt5Gui

# console.o : console.cpp console.h
# 	g++ -Wall -fPIC --std=c++11 -I/usr/include/qt5 $< -c -l Qt5Widgets -l Qt5Core -l Qt5Gui

moc:
	$(MOC) widgetajouter.h -o moc_widgetajouter.cpp
	$(MOC) container.h -o moc_container.cpp

launch:
	./NomApp