#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node * newNode(char* value, nodeType type)
{
	Node* new = (Node*)malloc(sizeof(*new));
	new->nodeValue = value;
	new->children = malloc( MAXNODES * sizeof(*new->children));
	new->child = 0;
	new->nType = type;
	return new;
}

void addNode(Node* parent, Node* son)
{
	parent->children[parent->child++] = son;
}

void addTerminalNode(Node* parent, nodeType type)
{
	parent->children[parent->child++] = newNode(NULL,type);
}

void putValue(Node* node, char* value)
{
	node->nodeValue = value;
}

char* getValue(Node * node)
{
	return node->nodeValue;
}

void printNextLines(Node * root){
	int i;
    Node *prev = root;

    for(i=0; i<prev->child ;i++){
		root = prev->children[i];
		printCode(root);
    }

    free(prev);
    return;
}

void printCode(Node * root)
{
    if(root == NULL){
    	return;
    }
    
    switch (root->nType)
    {

        case IF_NODE:
        printf("if(");
        printCode(root->children[0]);
        printf(")\n");
        printCode(root->children[1]);
            break;

        case WHILE_NODE:
        printf("while(");
        printCode(root->children[0]);
        printf(")\n");
        printCode(root->children[1]);
            break;

        case LINE_NODE:
        printCode(root->children[0]);
        printf(";\n");
            break;

        case ASSIGN_NODE_INT:
        printf("int %s = ", root->nodeValue);
        printCode(root->children[0]);
        printf(";\n");        
        	break;

        case ASSIGN_NODE_F:
        printf("float %s = ", root->nodeValue);
        printCode(root->children[0]);
        printf(";\n"); 
            break;

        case ASSIGN_NODE:
        printf("%s = ", root->nodeValue);
        printCode(root->children[0]);
        printf(";\n");
            break;

        case MULTI_NODE1:
        printCode(root->children[0]);        
            break;

        case MULTI_NODE2:
        printCode(root->children[0]);
        printCode(root->children[1]);
            break;            

        case KEYS_NODE:
        printf("{\n");
        printCode(root->children[1]);
        printf("}\n");
            break;    

		case INTEGER_NODE:
		printf("%s", root->nodeValue);
            break;

		case FLOAT_NODE:
		printf("%s", root->nodeValue);
            break;

		case PLUS_NODE:
		printCode(root->children[0]);
		printf(" = ");
		printCode(root->children[1]);
            break;

		case SUB_NODE:
		printCode(root->children[0]);
		printf(" - ");
		printCode(root->children[1]);
            break;

		case DIV_NODE:
		printCode(root->children[0]);
		printf(" / ");
		printCode(root->children[1]);
            break;

		case PROD_NODE:
		printCode(root->children[0]);
		printf(" * ");
		printCode(root->children[1]);
            break;

		case MOD_NODE:
		printf("  Math.abs( (float) %s ) ", root->children[0]->nodeValue );
            break;

		case LOG_NODE:
		printf("  Math.log( (float) %s ) ", root->children[0]->nodeValue );
            break;

		case SIN_NODE:
		printf("  Math.sin( (float) %s ) ", root->children[0]->nodeValue );
            break;

		case COS_NODE:
		printf("  Math.cos( (float) %s ) ", root->children[0]->nodeValue );
            break;

		case TAN_NODE:
		printf("  Math.tan( (float) %s ) ", root->children[0]->nodeValue );
            break;

		case GRAPH_NODE:
		//TO DO
            break;

        default:
            break;
    }
}

