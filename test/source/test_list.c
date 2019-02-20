/* 
 * File:   test_list.c
 * Author: Lukas Ratkovsky
 *
 * Created on 12. feb 2019, 21:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/test_array_list.h"
#include "../header/test_linked_list.h"
#include "../header/test_btree_list.h"

long nanos(struct timespec ts) {
    return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

void execute_test(int (test) ()) {
    struct timespec start, stop;

    timespec_get(&start, TIME_UTC);
    test();
    timespec_get(&stop, TIME_UTC);
    printf("\ntime: %luns\n", nanos(stop) - nanos(start));
    printf("time: %6.3lfµs\n", (double)((nanos(stop) - nanos(start))/1000));
    printf("time: %6.3lfms\n\n", (double)((nanos(stop) - nanos(start))/1000000));
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    //@TETS
    execute_test(test_linked_list);
    //@TEST
    execute_test(test_array_list);
    //@TEST
    execute_test(test_btree_list);

    return (EXIT_SUCCESS);
}

