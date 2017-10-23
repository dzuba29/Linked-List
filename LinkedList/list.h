#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

struct linked_list{

	int data;
	linked_list *next;
};

void print_list(linked_list *&list);

void push_list(linked_list *&list, int element);

void push_after(unsigned int k, linked_list *&list, int element);

void push_tail(linked_list *&list, int element);

void push_before(unsigned int k, linked_list *&list, int element);

void remove(unsigned int k, linked_list *&list);

void remove_first(linked_list *&list);

void remove_tail(unsigned int size, linked_list *&list);

void erase_list(linked_list *&list);

int list_size(linked_list *&list, unsigned int &count_list);

int acces_node(linked_list *&list, unsigned int k);

linked_list *acces_value(linked_list *&list, int element);

linked_list *copy_list(linked_list *&list);

void cut_list(linked_list *&list, linked_list *&list_1, linked_list *&list_2);

void bubble_sort(linked_list *&list);

#endif