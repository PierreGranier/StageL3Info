# Projet L3 : Logique de Hoare

## LEX ET YACC

### Yacc
bison -d test.y	-o build/test.tab.c
mv build/test.tab.h build/test.h
mv build/test.tab.c build/test.y.c

### Lex
    flex -o build/lex.yy.c test.lex
    mv build/lex.yy.c build/test.lex.c

### Compilation
    gcc -c build/test.lex.c -o build/test.lex.o
    gcc -c build/test.y.c -o build/test.y.o
    gcc -o test build/test.lex.o build/test.y.o -ll -lm

### Execution
./test


## LEX TOUT SEUL

    flex -o build/lex.yy.c test.lex
    mv build/lex.yy.c build/test.lex.c
    gcc -c build/test.lex.c -o build/test.lex.o
    gcc -o test build/test.lex.o -ll -lm
    ./test
