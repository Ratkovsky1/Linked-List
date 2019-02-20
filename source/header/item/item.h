/* 
 * File:   item.h
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 20:26
 */

#ifndef ITEM_H
#define ITEM_H

/**
 * 
 */
const struct Item {
   struct item*(*new)();
} Item;

/**
 *
 */
typedef struct item {
    void *data;
    struct item *next;
    
    void (*free)(struct item *i);
    char* (*toString)(struct item *i);
} item;


#endif /* ITEM_H */