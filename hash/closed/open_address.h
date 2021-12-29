typedef enum _Status {
	OCCUPIED, EMPTY, DELETED
} Status;

typedef struct _Bucket {
	int value;
	Status status;
} Bucket;

typedef struct _ClosedHash {
	int count;
	Bucket *table;
} ClosedHash;

void initialize_table(ClosedHash *hash, int count);
Bucket *search_value(ClosedHash *hash, int value);
int insert_value(ClosedHash *hash, int value);
int delete_value(ClosedHash *hash, int value);
void dump_table(ClosedHash *hash);
void destroy_table(ClosedHash *hash);
