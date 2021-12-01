#include <stdbool.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

Node *initialize_list(void);
bool is_empty_list(Node *head);
Node *search_node(Node *head, int value);
void insert_node(Node **head, int value);
void delete_node(Node **head, Node *node);
void print_list(Node *head);
void destroy_list(Node **head);
