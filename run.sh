echo Alex Voitik - Compiler Constructing....
yacc -d -v ada.y
lex ada.l
/usr/bin/gcc lex.yy.c y.tab.c -o ada -ll -ly
clear
./ada < $1".ada"


