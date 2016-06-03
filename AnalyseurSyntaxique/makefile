CXX= g++ -std=c++11

all:
	mkdir -p build
	
	clear
	
	@echo Yacc
	bison -d verificateur.y -o verificateur.tab.cpp
	
	@echo Lex
	flex -o verficateur.yy.cpp verificateur.lex
	
	@echo Compilation
	$(CXX) -c verficateur.yy.cpp -o build/verficateur.yy.o
	$(CXX) -c verificateur.tab.cpp -o build/verificateur.tab.o
	$(CXX) -o verificateur build/verficateur.yy.o build/verificateur.tab.o -lfl -ll -lm
	
launch:
	@echo Execution
	./verificateur
	
clean:
	@echo Nettoyage
	rm -rf build/*
	rm -rf build
	rm -rf *.tab.*
	rm -rf *.yy.*
	rm verificateur
