CXX= g++ -std=c++11

all:
	mkdir -p build
	
	clear
	
	@echo Yacc
	bison -d verificateur.y -o verificateur.tab.c
	
	@echo Lex
	flex verificateur.lex
	
	@echo Compilation
	$(CXX) -c lex.yy.c -o build/lex.yy.o
	$(CXX) -c verificateur.tab.c -o build/verificateur.tab.o
	$(CXX) -o verificateur build/lex.yy.o build/verificateur.tab.o -lfl -ll -lm
	
launch:
	@echo Execution
	./verificateur
	
	
launch_file:
	@echo Execution avec fichier
	./verificateur entree.txt
	
clean:
	@echo Nettoyage
	rm -rf build/*
	rm -rf build
	rm -rf *.tab.*
	rm -rf *.yy.c
	rm verificateur
