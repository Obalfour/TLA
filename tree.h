#define MAXNODES 4

typedef struct node {
	void* nodeValue;         
	struct node * * children;
	int child;   
 	char* nodeType;
}Node;

static Node* newNode(void* value, char* type);
void addNode(Node* parent, Node* son);
void addTerminalNode(Node* parent, char* type);
void* getValue(Node * node);

