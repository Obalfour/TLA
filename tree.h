#define MAXNODES 4

typedef struct nodeStruct{
	char* nodeValue;         
	struct nodeStruct * * children;
	int child;   
 	char* nodeType;
}Node;

static Node* newNode(char* value, char* type);
void addNode(Node* parent, Node* son);
void addTerminalNode(Node* parent, char* type);
char* getValue(Node * node);

