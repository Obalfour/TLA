#define MAXNODES 4

typedef enum
{
    IF_NODE,
    WHILE_NODE,
    LINE_NODE,
    ASSIGN_NODE_INT,
    ASSIGN_NODE_F,
    ASSIGN_NODE,
    MULTI_NODE1,
    MULTI_NODE2,
    KEYS_NODE,
    INTEGER_NODE,
    FLOAT_NODE,
    PLUS_NODE,
    SUB_NODE,
    DIV_NODE,
    PROD_NODE,
    MOD_NODE,
    LOG_NODE,
    SIN_NODE,
    COS_NODE,
    TAN_NODE,
    GRAPH_NODE
} nodeType;

typedef struct node {
	char* nodeValue;         
	struct node * * children;
	int child;   
 	nodeType nType;
}Node;

Node * newNode(char* value, nodeType type);
void addNode(Node* parent, Node* son);
void addTerminalNode(Node* parent, nodeType type);
void putValue(Node* node, char* value);
char* getValue(Node * node);
void printNextLines(Node * root);
void printCode(Node * root);

