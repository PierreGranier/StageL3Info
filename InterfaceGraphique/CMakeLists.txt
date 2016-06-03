project(NomApp)

# Compilation :  cmake CMakeLists.txt  ; make --file=Makefile -j2

cmake_minimum_required(VERSION 2.8.11)

add_definitions(-Wall -std=c++11 -fPIC)

# Find the Qt libraries
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_AUTOMOC ON)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

# Sources

set(Regles_SRCS widgetregle.cpp widgetregleaxiome.cpp widgetreglesimple.cpp widgetregledouble.cpp)
set(Widgets_SRCS ${Regles_SRCS} widgetajouter.cpp widgetsupprimer.cpp widgettriplet.cpp widgetnomregle.cpp)

set(NomApp_SRCS main.cpp mainwindow.cpp container.cpp console.cpp ${Widgets_SRCS})
# qt5_automoc(${NomApp_SRCS})
add_executable(NomApp ${NomApp_SRCS})

# Use the Widgets module from Qt 5.
target_link_libraries(NomApp Qt5::Widgets)
target_link_libraries(NomApp Qt5::Core)
target_link_libraries(NomApp Qt5::Gui)

# target_link_libraries(NomApp ${Qt5Widgets_LIBRARIES} ${Qt5Core_LIBRARIES} ${Qt5Gui_LIBRARIES})

# target_link_libraries(NomApp ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS NomApp RUNTIME DESTINATION bin)
