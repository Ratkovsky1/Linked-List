/* 
 * File:   test_linked_list.c
 * Author: Lukas Ratkovsky
 *
 * Created on 9. feb 2019, 21:20
 */

#include <stdio.h>
#include <stdlib.h>
#include "../header/test_linked_list.h"
#include "../../source/header/linked_list.h"
#include "../../source/header/item/string_item.h"

/*
 * Test
 */
int test_linked_list() {

    list *l = LinkedList.new();
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