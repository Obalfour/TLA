include Makefile.inc

all: clean compiler 

compiler: 
		flex scanner.l
		yacc -d grammar.y 
		$(GCC) -o compiler lex.yy.c y.tab.c tree.c tree.h -ly $(GCCFLAGS)

clean: 
	rm -rf *.o y.tab.c y.tab.h compiler lex.yy.c test1.java

test1: 
	./compiler < test1.se > test1.java
	javac test1.java

.PHONY: all test1 clean compiler	