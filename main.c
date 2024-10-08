struct list_item {
    int val;
    struct list_item *next;
};

struct list {
    struct list_item *head;
};

typedef struct list_item list_item;
typedef struct list list;

void remove_elegant(list *l, list_item *target) {
    list_item **p = &l->head;
    while (*p != target) {
        p = &(*p)->next; 
    }
    p = target->next;
}
