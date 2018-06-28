%{
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
%}

%union{
	Node * node;
	char * string;
	float f;
	int i;
}

%token<i> NUMBER
%token<string> VARIABLE
%token<f> DEC
%token<node> INTEGER FLOAT
%token<node> IF WHILE
%token<node> OP_ASSIGN OP_SUM OP_SUB OP_MUL OP_DIV OP_MODULO OP_PLUS_ONE OP_SUB_ONE
%token<node> OP_OR OP_AND OP_NEG OP_EQ OP_DIST OP_LT OP_GT OP_LE OP_GE
%token<node> LOG SIN COS TAN GRAFICAR

%right OP_ASSIGN
%left OP_SUM OP_SUB
%left OP_MUL OP_DIV
%left OP_NEG OP_AND OP_OR
%left LOG
%left GRAFICAR

%type<node> begin conditional ciclo line multilines expr

%start begin

%%

begin: line
	{
		Node root = $1;
//		printProgram(root);
printf(public class Welcome1{public static void main( String[] args ){System.out.println( "Welcome to Java Programming!" );}});
	};

conditional: IF '(' expr ')' line ';'
	{
		$$ = newNode(NULL,if);
		addNode($$,$3);
		addNode($$,$5);
	};

ciclo: WHILE '(' expr ')' line ';'
	{
		$$ = newNode(NULL,while);
		addNode($$,$3);
		addNode($$,$5);
	};

line: expr ';'
	{
		$$ = newNode(NULL,";");
		addNode($$,$1);
	};
	| INTEGER VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode(NULL,"=");
		addNode($$,$4);
	}
	| FLOAT VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode(NULL,"=");
		addNode($$,$4);
	}
	| VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode(NULL,"=");
		addNode($$,$3);
	}
	| '{' multilines '}'
	{
		$$ = newNode(NULL,"multi");
		addNode($$,$2);
	};
	| conditional
	{
		$$=$1;
	}
	| ciclo
	{
		$$=$1;
	}

multilines: line
	{
		$$ = newNode(NULL,"multi");
		addNode($$,$1);
	}
	| line multilines
	{
		$$ = newNode(NULL,"multi");
		addNode($$,$1);
		addNode($$,$2);
	};

expr: NUMBER
	{
		$$ = newNode($1,"int");
	}
	| DEC
	{
		$$ = newNode($1,"float");
	}
	| expr OP_SUM expr
	{
		$$ = newNode(NULL,'+');
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_SUB expr
	{
		$$ = newNode(NULL,'-');
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_DIV expr
	{
		$$ = newNode(NULL,'/');
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_MUL expr
	{
		$$ = newNode(NULL,'*');
		addNode($$,$1);
		addNode($$,$3);
	}
	| OP_MODULO '(' expr ')'
	{
		$$ = newNode(NULL,"mod");
		addNode($$,$3);
	}
	| LOG '(' expr ')'
	{
		$$ = newNode(NULL,"log");
		addNode($$,$3);
	}
	| SIN '(' expr ')'
	{
		$$ = newNode(NULL,"sin");
		addNode($$,$3);
	}
	| COS '(' expr ')'
	{
		$$ = newNode(NULL,"cos");
		addNode($$,$3);
	}
	| TAN '(' expr ')'
	{
		$$ = newNode(NULL,"tan");
		addNode($$,$3);
	};

%%

void yyerror(const char * s)
{
	fprintf(stderr, "Error: That operation is not supported on Se Language \n", s, linenum);
	exit(1);
}	

int main(void){
	yyparse();
}	