# Ada_Grammar_Spec

Compile with the following:

$ lex ada.l
//this compiles the lex file
$ yacc -d -v ada.y
//this compiles the yacc file
$ /usr/bin/gcc lex.yy.c y.tab.c -o test -ll -ly
//creates an executable named "test"
$ ./test
//executes
