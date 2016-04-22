project(logiquehoare)

add_definitions(-Wall) # facultatif std=c++11

add_executable(logiquehoare main.cpp)

install(TARGETS logiquehoare RUNTIME DESTINATION bin)
