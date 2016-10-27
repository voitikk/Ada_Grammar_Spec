echo Alex Voitik - Compiler Constructing....
yacc -d -v ada.y
lex ada.l
/usr/bin/gcc lex.yy.c y.tab.c -o ada -ll -ly

echo Running on "Stsimple.ada"...
./ada < STsimple.ada


