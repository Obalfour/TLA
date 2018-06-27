%{
#include "y.tab.h"
#include <strings.h>
#include <stdlib.h>
%}
%%

[-]?[0-9]+ 				return NUMBER;
[-]?[0-9]+[,][0-9]+			return DEC;
[a-zA-Z][a-zA-Z0-9]*			return VARIABLE;

integer					return INTEGER;
float					return FLOAT;

if					return IF;
 	
while					return WHILE;

"="					return OP_ASSIGN;
"+"					return OP_SUM;
"-"					return OP_SUB;
"/"					return OP_DIV;
"*"					return OP_MUL;
mod					return OP_MODULO;

"++"					return OP_PLUS_ONE;
"--"					return OP_SUB_ONE;
	
or					return OP_OR;
and					return OP_AND;
neg					return OP_NEG;

op_eq					return OP_EQ;	
op_dist					return OP_DIST;
op_lt					return OP_LT;
op_gt					return OP_GT;
op_le					return OP_LE;
op_ge					return OP_GE;

log     				return LOG;
sin    					return SIN;
cos    					return COS;
tan    					return TAN;

graph					return GRAFICAR;
