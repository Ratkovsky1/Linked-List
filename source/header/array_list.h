/* 
 * File:   array_list.h
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 14:15
 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include "./list.h"

/**
 */
extern const struct List ArrayList;

/**
 */
typedef struct al_core {
    item *first;
    item *activ;
    item *last;
} al_core;

/**
 * 
 * @return 
 */
list* al_new();

/**
 * 
 * @param l
 * @param data
 */
void al_add(struct list *l, item *data);

/**
 * @param l
 */
void al_remove(list *l, int index);

/**
 * 
 * @param l
 */
void al_remove_all(list *l);

/**
 * 
 * @param l
 */
void al_free(list *l);

/**
 * 
 * @param l
 */
void al_print_list(list *l);

#endif /* ARRAY_LIST_H */