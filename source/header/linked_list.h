/* 
 * File:   linked_list.h
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 14:15
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "./list.h"

/**
 */
extern const struct List LinkedList;

typedef struct ll_core {
    item *first;
    item *last;
} ll_core;

/**
 *
 * @return 
 */
list* ll_new();

/**
 * 
 * @param l
 * @param data
 */
void ll_add(struct list *l, item *data);

/**
 * @param l
 */
void ll_remove(list *l, int index);

/**
 * 
 * @param l
 */
void ll_remove_all(list *l);

/**
 * 
 * @param l
 */
void ll_free(list *l);

/**
 * 
 * @param l
 */
void ll_print_list(list *l);

#endif /* LINKED_LIST_H */