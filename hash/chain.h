typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef struct _ChainHash {
	int count;
	Node **table;	
} ChainHash;

void initialize_table(ChainHash *hash, int count);
Node *search_node(ChainHash *hash, int value);
int insert_node(ChainHash *hash, int value);
int delete_node(ChainHash *hash, int value);
void dump_table(ChainHash *hash);
void destroy_table(ChainHash *hash);
