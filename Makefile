include Makefile.inc

all: clean compiler 

compiler: 
		flex pattern.l
		yacc -d grammar.y 
		$(GCC) -o compiler lex.yy.c y.tab.c tree.c -ly $(GCCFLAGS)

clean: 
	rm -rf *.o y.tab.c y.tab.h compiler lex.yy.c test1.java

test1: 
	./compiler < test1.se > test1.java
	javac test1.java
	java test1

test2: 
	./compiler < test2.se > test1.java
	javac test1.java
	java test1

test3: 
	./compiler < test3.se > test1.java
	javac test1.java
	java test1		

.PHONY: all test1 clean compiler	