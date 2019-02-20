/* 
 * File:   list.h
 * Author: Lukas Ratkovsky
 *
 * Created on 6. feb 2019, 23:04
 */

#ifndef LIST_H
#define LIST_H

#include "./item/item.h"

/**
 */
const struct List {
    struct list*(*new)();
} List;

/**
 *
 */
typedef struct list {
    void *core;
    
    void (*add)(struct list *l, item *data);
    void (*remove)(struct list *l, int index);
    void (*removeAll)(struct list *l);
    void (*free)(struct list *l);
    void (*print)(struct list *l);
} list;

#endif /* LIST_H */