%{
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

extern int yylineno;

void yyerror(const char *s);
int yylex();

%}

%union{
	struct node * node;
	char * string;
	float f;
	int i;
}

%error-verbose

%token<i> NUMBER
%token<string> VARIABLE
%token<f> DEC
%token<node> INTEGER FLOAT
%token<node> IF WHILE MESSI PAUL
%token<node> OP_ASSIGN OP_SUM OP_SUB OP_MUL OP_DIV OP_MODULO OP_PLUS_ONE OP_SUB_ONE
%token<node> OP_OR OP_AND OP_NEG OP_EQ OP_DIST OP_LT OP_GT OP_LE OP_GE
%token<node> LOG SIN COS TAN GRAFICAR

%right OP_ASSIGN
%left OP_SUM OP_SUB
%left OP_MUL OP_DIV OP_MOD
%left OP_NEG
%left OP_AND
%left OP_OR

%type<node> begin conditional ciclo line multilines expr graphed condition future

%start begin

%%

begin: line
	{
		Node * root = $1;
		printf("import java.lang.Math;\n\n");
		printf("import java.lang.Random;\n\n");
		printf("public class test1 {\n");
		printf("\t public static void main(String[] args) {\n");
		printCode(root);
		printf("\t}\n}\n");

//		printf("public class test1{public static void main( String[] args ){System.out.println( \"Welcome to Java Programming!\" );}}");
	};

future: PAUL VARIABLE VARIABLE
	{
		$$ = newNode(NULL,PAUL_NODE);
		addNode($$,newNode($2, STRING_NODE);
		addNode($$,newNode($3, STRING_NODE);
	};	

graphed: GRAFICAR '(' expr ')' ';'
	{
		$$ = newNode(NULL,GRAPH_NODE);
		addNode($$,$3);
	};	

conditional: IF '(' condition ')' line ';'
	{
		$$ = newNode(NULL,IF_NODE);
		addNode($$,$3);
		addNode($$,$5);
	};

ciclo: WHILE '(' condition ')' line ';'
	{
		$$ = newNode(NULL,WHILE_NODE);
		addNode($$,$3);
		addNode($$,$5);
	};

condition: expr OP_EQ expr
	{
		$$ = newNode(NULL,EQ_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_DIST expr
	{
		$$ = newNode(NULL,DIST_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_LT expr 
	{
		$$ = newNode(NULL,LT_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_GT expr 
	{
		$$ = newNode(NULL,GT_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_LE expr
	{
		$$ = newNode(NULL,LE_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_GE expr
	{
		$$ = newNode(NULL,GE_NODE);
		addNode($$,$1);
		addNode($$,$3);
	};

line: expr ';'
	{
		$$ = newNode(NULL,LINE_NODE);
		addNode($$,$1);
	}
	| INTEGER VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode($2,ASSIGN_NODE_INT);
		addNode($$,$4);
	}
	| FLOAT VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode($2,ASSIGN_NODE_F);
		addNode($$,$4);
	}
	| VARIABLE OP_ASSIGN expr ';'
	{
		$$ = newNode($1,ASSIGN_NODE);
		addNode($$,$3);
	}
	| '{' multilines '}'
	{
		$$ = newNode(NULL,KEYS_NODE);
		addNode($$,$2);
	}
	| conditional
	{
		$$=$1;
	}
	| MESSI ';'
	{
		$$ = newNode(NULL,MESSI_NODE);
	}
	| future ';'
	{
		$$ = $1;
	}
	| ciclo
	{
		$$=$1;
	}
	| graphed
	{
		$$=$1;
	};

multilines: line
	{
		$$ = newNode(NULL,MULTI_NODE1);
		addNode($$,$1);
	}
	| line multilines
	{
		$$ = newNode(NULL,MULTI_NODE2);
		addNode($$,$1);
		addNode($$,$2);
	};

expr: NUMBER
	{
		int someInt = $1;
		char str[12];
		sprintf(str, "%d", someInt);
		$$ = newNode(str,INTEGER_NODE);
	}
	| DEC
	{
		float f = $1;
   		char c[50]; //size of the number
    	sprintf(c, "%g", f);
		$$ = newNode(c,FLOAT_NODE);
	}
	| expr OP_SUM expr
	{
		$$ = newNode(NULL,PLUS_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_SUB expr
	{
		$$ = newNode(NULL,SUB_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_DIV expr
	{
		$$ = newNode(NULL,DIV_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| expr OP_MUL expr
	{
		$$ = newNode(NULL,PROD_NODE);
		addNode($$,$1);
		addNode($$,$3);
	}
	| OP_MODULO '(' expr ')'
	{
		$$ = newNode(NULL,MOD_NODE);
		addNode($$,$3);
	}
	| LOG '(' expr ')'
	{
		$$ = newNode(NULL,LOG_NODE);
		addNode($$,$3);
	}
	| SIN '(' expr ')'
	{
		$$ = newNode(NULL,SIN_NODE);
		addNode($$,$3);
	}
	| COS '(' expr ')'
	{
		$$ = newNode(NULL,COS_NODE);
		addNode($$,$3);
	}
	| TAN '(' expr ')'
	{
		$$ = newNode(NULL,TAN_NODE);
		addNode($$,$3);
	};

%%

void yyerror(const char * s)
{
	fprintf(stderr, "Error %s. The line %d is not supported on Se Language\n", s, yylineno-1);
}

int yywrap(){
	return 1;
}

int main(void){
	yyparse();
}	