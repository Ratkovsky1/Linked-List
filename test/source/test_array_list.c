/* 
 * File:   test_array_list.c
 * Author: Lukas Ratkovsky
 *
 * Created on 12. feb 2019, 21:49
 */

#include <stdio.h>
#include <stdlib.h>
#include "../header/test_array_list.h"
#include "../../source/header/array_list.h"
#include "../../source/header/item/string_item.h"

/*
 * 
 */
int test_array_list() {

    list *l = ArrayList.new();
    l->print(l);
    printf("\n\n");
    l->add(l, StringItem.new("ahoj"));
    l->add(l, StringItem.new("svete"));
    l->add(l, StringItem.new("hello"));
    l->add(l, StringItem.new("world"));
    l->print(l);
    printf("\n\n");
    l->removeAll(l);
    l->print(l);
    l->free(l);

    return (EXIT_SUCCESS);
}

