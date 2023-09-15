#include <stdbool.h>

#define INITIAL_CAPACITY 10
#define LOAD_FACTOR_THRESHOLD 0.7
#define GROW_BY 2

typedef struct IHM_Item
{
    int key;
    int value;
    struct IHM_Item *next;
} IHM_Item;

typedef struct IntHashMap
{
    int len;
    int cap;
    IHM_Item **table;
} IntHashMap;

IntHashMap *IHM_new();
bool IHM_set(IntHashMap *m, int key, int value);
int *IHM_get(IntHashMap *m, int key);
void IHM_delete(IntHashMap *m, int key);
void IHM_free(IntHashMap *m);

static int hash(int key, int capacity);
static bool resize(IntHashMap *m);