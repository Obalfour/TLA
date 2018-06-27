#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

static Node* newNode(char* value, char* type)
{
	Node* new = (Node*)malloc(sizeof(*new));
	new->nodeValue = value;
	new->children = malloc( MAXNODES * sizeof(*new->children));
	new->child = 0;
	new->nodeType = type;
}

void addNode(Node* parent, Node* son)
{
	parent->children[parent->child++] = son;
}

void addTerminalNode(Node* parent, nodeType type)
{
	parent->children[parent->child++] = newNode(type, NULL);
}

void putValue(Node* node, char* value)
{
	node->nodeValue = value;
}

char* getValue(Node * node)
{
	return node->value;
}
