/* 
 * File:   string_item.h
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 20:40
 */

#ifndef STRING_ITEM_H
#define STRING_ITEM_H

#include "item.h"

/**
 *
 */
extern const struct Item StringItem;

/**
 * 
 * @param data
 * @return 
 */
item* si_new(char* data);

/**
 * 
 */
void si_free(item* i);

/**
 * 
 * @return 
 */
char* si_to_string(item* i);

#endif /* STRING_ITEM_H */