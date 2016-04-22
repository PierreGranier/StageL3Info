all:
	mkdir -p build
	
	clear
	
	@echo Yacc
	bison -d test.y -o test.tab.c
	
	@echo Lex
	flex test.lex

	@echo Compilation
	gcc -c	lex.yy.c	-o build/lex.yy.o
	gcc -c	test.tab.c	-o build/test.tab.o
	gcc	-o	hoare build/lex.yy.o	build/test.tab.o -lfl -ll -lm
	
launch:
	@echo Execution
	./hoare
	
	
launch_file:
	@echo Execution avec fichier
	./hoare entree.txt
	
clean:
	@echo Nettoyage
	rm -rf build/*
	rm -rf *.tab.*
	rm -rf *.yy.c
