/* 
 * File:   string_item.c
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 20:26
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../header/item/string_item.h"

/**
 */
const struct Item StringItem = {
    .new = &si_new
};

/**
 * 
 * @param data
 * @return 
 */
item* si_new(char* data) {
    int data_len = strlen(data);
    item *i = (item*) calloc(1, sizeof (item));
    i->data = (char*) calloc(data_len + 1, sizeof (char));
    strncpy(i->data, data, data_len + 1);
    
    i->free = &si_free;
    i->toString = &si_to_string;
    return i;
}

/**
 * 
 * @param i
 */
void si_free(item* i) {
    free(i->data);
    i->data = NULL;
}

/**
 * 
 * @param i
 * @return 
 */
char* si_to_string(item* i) {
    return i->data;
}