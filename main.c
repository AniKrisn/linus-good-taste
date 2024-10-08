struct list_item {
    int val;
    struct list_item *next;
};

struct list {
    struct list_item *head;
};

typedef struct list_item list_item;
typedef struct list list;

// 2 notes: 
// incorporates as a node so doesn't need to separately check if head
// indirect pointer p is modifiable, so we don't need prev and cur
void remove_elegant(list *l, list_item *target) {
    list_item **p = &l->head;
    while (*p != target) {
        p = &(*p)->next; 
    }
    p = target->next; // removes the target
}


static inline list_item **find_indirect(list *l, list_item *target) {
    list_item **p = &l->head;
    while (*p != target) {
        p = &(*p)->next;
    }
    return p;
}

void insert_before(list *l, list_item *before, list_item *item) {
    list_item **p = find_indirect(l, before);
    *p = item; // this updates pointer to the new item, effectively inserting it into the list 
    item->next = before; // sets location of newly inserted item
}

// since find_indirect incorporates head into list structure, if before points to head, then the new item will be inserted at the start of the list