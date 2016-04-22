all:
	mkdir -p build
	
	clear
	@echo Yacc
	bison -d test.y -o build/test.tab.c
	mv build/test.tab.h build/test.h
	mv build/test.tab.c build/test.y.c

	@echo Lex
	flex -o build/lex.yy.c test.lex
	mv build/lex.yy.c build/test.lex.c

	@echo Compilation
	gcc -c build/test.lex.c -o build/test.lex.o
	gcc -c build/test.y.c -o build/test.y.o
	gcc -o test build/test.lex.o build/test.y.o -ll -lm
	
launch:
	@echo Execution
	./test
	
	
launch_file:
	@echo Execution avec fichier
	./test entree.txt
