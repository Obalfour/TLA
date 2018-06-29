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

        case EQ_NODE:
		printCode(root->children[0]);
		printf(" == ");
		printCode(root->children[1]);        
        	break;

        case DIST_NODE:
		printCode(root->children[0]);
		printf(" != ");
		printCode(root->children[1]);        
        	break;

       	case LT_NODE:
		printCode(root->children[0]);
		printf(" < ");
		printCode(root->children[1]);       	
       		break;

       	case GT_NODE:
		printCode(root->children[0]);
		printf(" > ");
		printCode(root->children[1]);       	
       		break;

       	case LE_NODE:
		printCode(root->children[0]);
		printf(" <= ");
		printCode(root->children[1]);       	
       		break;

       	case GE_NODE:
		printCode(root->children[0]);
		printf(" >= ");
		printCode(root->children[1]);       	
       		break;

       	case PAUL_NODE:
       	printf("\tRandom r = new Random();\n");
       	printf("\tint Low = 0;\n");
       	printf("\tint High = 6;\n");
       	printf("\tString team1 = \"%s\";\n", root->children[0]->nodeValue );
       	printf("\tSystem.out.println(  team1  );\n");
       	printf("\tint Result = r.nextInt(High-Low) + Low;\n");
       	printf("\tSystem.out.println(  Result  );\n");
       	printf("\tString team2 = \"%s\";\n", root->children[1]->nodeValue );
       	printf("\tSystem.out.println(  team2  );\n");
       	printf("\tResult = r.nextInt(High-Low) + Low;\n");
       	printf("\tSystem.out.println(  Result  );\n");
       		break;

       	case MESSI_NODE:
       	printf("\tSystem.out.println( \"        ____\" );\n");
       	printf("\tSystem.out.println( \"       ( () )\" );\n");
       	printf("\tSystem.out.println( \"        \\\\  /\" );\n");
       	printf("\tSystem.out.println( \"         ||\" );\n");
       	printf("\tSystem.out.println( \"         ||\" );\n");
       	printf("\tSystem.out.println( \"        [__]\" );\n");
       	printf("\tSystem.out.println( \"       /)  (\\\\\" );\n");
       	printf("\tSystem.out.println( \"      (( () ))\" );\n");
       	printf("\tSystem.out.println( \"       \\\\\\\\__//\" );\n");
       	printf("\tSystem.out.println( \"        `..'\" );\n");
       	printf("\tSystem.out.println( \"         ||\" );\n");
       	printf("\tSystem.out.println( \"         ||\" );\n");
       	printf("\tSystem.out.println( \"        //\\\\\\\\\" );\n");
       	printf("\tSystem.out.println( \"     _ ((  `--'\" );\n"); 
       	printf("\tSystem.out.println( \"    (_) \\\\)\" );\n");
       	printf("\tSystem.out.println( \"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\\\"\" );\n"); 
       	printf("\tSystem.out.println( \"TRAEME LA COPA MESSI\" );\n");        	        	      	
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

