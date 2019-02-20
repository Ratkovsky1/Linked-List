#
# File:   CMakeLists.txt
# Author: Lukas Ratkovsky
#
# Created on 6. feb 2019, 23:04

cmake_minimum_required (VERSION 2.4)

PROJECT ("List")

SET(CMAKE_COLOR_MAKEFILE ON)
ADD_EXECUTABLE(
    ./build/list 
    ./source/source/linked_list.c 
    ./source/source/array_list.c
    ./source/source/item/string_item.c 
    ./test/source/test_array_list.c
    ./test/source/test_linked_list.c
    ./test/source/test_btree_list.c
    ./test/source/test_list.c

)
