/* 
 * File:   linked_list.c
 * Author: Lukas Ratkovsky
 *
 * Created on 6. feb 2019, 23:04
 */

#include <stdlib.h>
#include <stdio.h>
#include "../header/linked_list.h"

/**
 */
const struct List LinkedList = {
    .new = &ll_new
};

/**
 * Private function that initialize list pointers.
 * @param l
 */
void ll_init_items(list* l) {
    ll_core *core = l->core;
    core->first = NULL;
    core->last = NULL;
}

/**
 * Private function that initialize list functions.
 * @param l
 */
void ll_init_functions(list* l) {
    l->add = &ll_add;
    l->removeAll = &ll_remove_all;
    l->free = &ll_free;
    l->print = &ll_print_list;
}

/**
 * Private function that initialize whole list. If list is not NULL.
 * @param l
 */
void ll_init(list* l) {
    if (l != NULL) {
        ll_init_items(l);
        ll_init_functions(l);
    }
}

/**
 * Function that return new pointer to new list. If fail return NULL;
 * @return 
 */
list* ll_new() {
    list *l = (list*) calloc(1, sizeof (list));
    l->core = (ll_core*) calloc(1, sizeof(ll_core));
    ll_init(l);
    return l;
}

/**
 * Add new item after last item.
 * @param l
 * @param i
 */
void ll_add(struct list *l, item *i) {
    ll_core* core = l->core;
    if (core->last == NULL) {
        core->first = i;
    } else {
        core->last->next = i;
    }
    core->last = i;
}

/**
 * 
 * @param l
 */
void ll_remove(list *l, int index) {
    
}

/**
 * Remove all items from list.
 * @param l
 */
void ll_remove_all(list *l) {
    item *iterator = ((ll_core*)l->core)->first;
    item *aux = NULL;
    while (iterator != NULL) {
        iterator->free(iterator);
        aux = iterator;
        iterator = iterator->next;
        free(aux);
    }
    ll_init_items(l);
}

/**
 * Remove all items from list. And free list. 
 * @param l
 */
void ll_free(list *l) {
    ll_remove_all(l);
    free(l->core);
    free(l);
}

/**
 * Print list to stdout.
 * @param l
 */
void ll_print_list(list *l) {
    int i = 1;
    ll_core* core = l->core;
    item *iterator = core->first;
    printf("--------- LINKED LIST --------\n");
    while (iterator != NULL) {
        printf("Item index: %d, adress: %d, data : %s\n", i, iterator, iterator->toString(iterator));
        i++;
        iterator = iterator->next;
    }
    printf("------------------------------\n");
}