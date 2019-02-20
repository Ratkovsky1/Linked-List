/* 
 * File:   array_list.c
 * Author: Lukas Ratkovsky
 *
 * Created on 12. feb 2019, 23:04
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../header/array_list.h"

#define CHUNK_SIZE 8

/**
 */
const struct List ArrayList = {
    .new = &al_new
};

/**
 * Private function that initialize list pointers.
 * @param l
 */
void al_init_items(list* l, int chunk_size) {
    al_core *core = l->core;
    core->first = (item*) calloc(chunk_size, sizeof (item));
    core->activ = core->first;
    core->last = core->first + chunk_size;
}

/**
 * Private function that initialize list functions.
 * @param l
 */
void al_init_functions(list* l) {
    l->add = &al_add;
    l->removeAll = &al_remove_all;
    l->free = &al_free;
    l->print = &al_print_list;
}

/**
 * Private function that initialize whole list. If list is not NULL.
 * @param l
 */
void al_init(list* l) {
    if (l != NULL) {
        al_init_items(l, CHUNK_SIZE);
        al_init_functions(l);
    }
}

_Bool al_is_full(list *l) {
    al_core *core = l->core;
    return core->activ == core->last;
}

/**
 * Function that return new pointer to new list. If fail return NULL;
 * @return 
 */
list* al_new() {
    list *l = (list*) calloc(1, sizeof (list));
    l->core = (al_core*) calloc(1, sizeof(al_core));
    al_init(l);
    return l;
}

/**
 * Add new item after last item.
 * @param l
 * @param i
 */
void al_add(struct list *l, item *i) {
    //TODO promyslet jak budou prvky alokovany
    if (al_is_full(l)) {
        ;
    } else {
        al_core *core = l->core;
        core->activ->data = i->data;
        core->activ->toString = i->toString;
        core->activ->next = i->next;
        core->activ->free = i->free;
        core->activ++;
        free(i);
    }
}

void al_remove(list *l, int index) {
    //TODO
}

/**
 * Remove all items from list.
 * @param l
 */
void al_remove_all(list *l) {
    al_core *core = l->core;
    for (item* iterator = core->first; iterator < core->activ; iterator++) {
        iterator->free(iterator);
    }
    free(core->first);
    al_init_items(l, CHUNK_SIZE);
}

/**
 * Remove all items from list. And free list. 
 * @param l
 */
void al_free(list *l) {
    al_remove_all(l);
    al_core *core = l->core;
    free(core->first);
    free(l->core);
    free(l);
}

/**
 * Print list to stdout.
 * @param l
 */
void al_print_list(list *l) {
    printf("--------- ARRAY LIST ---------\n");
    al_core *core = l->core;
    for (item* iterator = core->first; iterator < core->activ; iterator++) {
        printf("Item index: %d, adress: %d, data : %s\n", iterator  - core->first, iterator, iterator->toString(iterator));
    }
    printf("------------------------------\n");
}