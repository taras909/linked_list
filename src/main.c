/*
 * This file is part of the linked list distribution
 * Copyright (c) 2018 Taras Kharabara.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; See the GNU
 * General Public License for more details.
 *
 */

#include "list.h"


/**
  * The main procedure is used for testing purpose
  * and it is not a part of library.
  */



struct ASD
{
    int;
};

struct ASDB
{
    int a;
};

int main()
{
    struct ASD obj;
    struct ASDB obj1;
   printf("%d", sizeof(obj));
   printf("%d", sizeof(obj1));

    struct List list;
    struct List list1;
    init(&list1);
    push_back(&list1,(char*)"Hi",&string_func);
    push_back(&list1,(int*)2,&int_func);
    push_back(&list1,(int*)3,&int_func);
    push_back(&list1,(int*)4,&int_func);
    push_back(&list1,(int*)5,&int_func);

    print(&list1);
    set_instead(&list1,(char*)"Hi",string_func.is_equal,(char*)"Salut",&string_func);
    print(&list1);

    push_front(&list1,(int*)6,&int_func);
    insert_before(&list1,(char*)"Salut",string_func.is_equal,(int*)9696,&int_func);
    push_back(&list1,(int*)10000,&int_func);
    print(&list1);
    remove_node(&list1,(int*)6,int_func.is_equal);
    print(&list1);

    // printf("********************************************************\n");
    // set_instead(&list1,(int*)1,int_func.is_equal,(char*)"Aloha",&string_func);
    // set_instead(&list1,(char*)"Hi",string_func.is_equal,(char*)"Salut",&string_func);
    // insert_before(&list1,(int*)100,int_func.is_equal,(int*)999,&int_func);
    // print(&list1);
    // printf("********************************************************\n");
    // insert_before(&list1,(char*)"Salut",string_func.is_equal,(int*)666,&int_func);
    // print(&list1);
    // printf("********************************************************\n");

    // init(&list);

    // push_back(&list,(int*)1,&int_func);
    // push_back(&list,(int*)2,&int_func);
    // push_back(&list,(int*)3,&int_func);
    // push_back(&list,(int*)4,&int_func);
    // push_back(&list,(int*)5,&int_func);
    // push_front(&list,(int*)6,&int_func);
    // push_front(&list,"Hello",&string_func);
    // push_back(&list,"test",&string_func);
    // push_back(&list,(int*)7,&int_func);
    // push_back(&list,"blablablablablabla _ blablablablablabla",&string_func);


    // print(&list);
    // remove_node(&list,(int*)1,int_func.is_equal);
    // print(&list);
    // remove_node(&list,(int*)2,int_func.is_equal);
    // print(&list);
    // remove_node(&list,(char*)"blablablablablabla _ blablablablablabla",string_func.is_equal);
    // print(&list);
    // remove_node(&list,(char*)"test",string_func.is_equal);
    // print(&list);
    // remove_node(&list,(char*)"Hello",string_func.is_equal);
    // print(&list);

    return 0;
}

