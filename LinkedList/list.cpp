#include "list.h"
void print_list(linked_list *&list){

	if (!list) throw "empty struct";
	linked_list *temp = list;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}

	std::cout << std::endl;
}

void push_list(linked_list *&list, int element){ //add first element

	linked_list *q = new linked_list;
	q->data = element;
	q->next = list;
	list = q;
}

void push_after(unsigned int k, linked_list *&list, int element){ // add after n-element

	if (!list) throw "empty struct";
	linked_list *temp = list;
	for (unsigned int i = 0; i < k - 1; i++)
		temp = temp->next;
	linked_list *w = new linked_list;
	w->data = element;
	w->next = temp->next;
	temp->next = w;
}

void push_tail(linked_list *&list, int element){ // add tail

	if (!list) throw "empty struct";
	linked_list *temp = list;
	linked_list *w = new linked_list;
	w->data = element;
	while (temp->next)
		temp = temp->next;
	w->next = temp->next;
	temp->next = w;
}

void push_before(unsigned int k, linked_list *&list, int element){ // add before n-element

	if (!list) throw "empty struct";
	linked_list *temp = list;
	for (unsigned int i = 0; i < k - 2; i++)
		temp = temp->next;
	linked_list *w = new linked_list;
	w->data = element;
	w->next = temp->next;
	temp->next = w;
}

void remove(unsigned int k, linked_list *&list){ // remove n-element

	if (!list) throw "empty struct";
	if (k == 0)
	{
		linked_list *temp = list;
		list = list->next;
		delete temp;
	}
	linked_list *temp = list;
	temp = list;
	linked_list *w = new linked_list;
	for (unsigned int i = 0; i < k - 2; i++)
		temp = temp->next;
	w = temp->next;
	temp->next = w->next;
	delete w;


}

void remove_first(linked_list *&list){

	if (!list) throw "empty struct";
	linked_list *temp = list;
	list = list->next;
	delete temp;

}

void remove_tail(unsigned int size, linked_list *&list){ //remove tail element

	if (!list) throw "empty struct";
	linked_list *temp = list;
	linked_list *w = new linked_list;
	while (temp->next->next)

		temp = temp->next;
	w = temp->next;
	temp->next = w->next;
	delete w;


}

void erase_list(linked_list *&list){ //erase all nodes 

	if (!list) throw "empty struct";
	while (list)
		remove_first(list);
}

int list_size(linked_list *&list, unsigned int &count_list){ //sizeof list

	if (!list) throw "empty struct";
	count_list = 0;
	linked_list *temp = list;
	while (temp)
	{
		temp = temp->next;
		count_list++;
	}
	return count_list;
}

int acces_node(linked_list *&list, unsigned int k){ //search index of node

	if (!list) throw "empty struct";
	linked_list *temp = list;
	for (unsigned int i = 0; i < k - 1; i++)
	{
		temp = temp->next;
	}
	return temp->data;
}

linked_list *acces_value(linked_list *&list, int element){ //search node

	if (!list) throw "empty struct";
	linked_list *start = list;
	linked_list *buffer = 0;
	int count = 0;
	while (start != 0)
	{
		if (start->data == element)
		{
			push_list(buffer, count);

		}
		count++;
		start = start->next;
	}

	return buffer;

}

linked_list *copy_list(linked_list *&list){ //copy with all nodes

	if (!list) throw "empty struct";
	linked_list *temp = list;
	linked_list* new_list = new linked_list;
	linked_list* new_first = new_list;
	new_list->data = temp->data;
	temp = temp->next;
	while (temp)
	{
		new_list->next = new linked_list;
		new_list = new_list->next;
		new_list->data = temp->data;
		temp = temp->next;

	}
	new_list->next = 0;
	return new_first;

}

void cut_list(linked_list *&list, linked_list *&list_1, linked_list *&list_2){ //cut list %2

	if (!list) throw "empty struct";
	linked_list *temp = list;
	list_1 = new linked_list;
	list_2 = new linked_list;

	linked_list *temp_list1 = list_1;
	linked_list *temp_list2 = list_2;
	linked_list *out_list = temp_list1;
	linked_list *out_list2 = temp_list2;


	while (temp)
	{
		if (temp->data % 2)
		{
			temp_list2->data = temp->data;
			temp_list2->next = new linked_list;
			out_list2 = temp_list2;
			temp_list2 = temp_list2->next;

		}
		else
		{
			temp_list1->data = temp->data;
			temp_list1->next = new linked_list;
			out_list = temp_list1;
			temp_list1 = temp_list1->next;

		}
		temp = temp->next;

	}
	out_list->next = 0;
	out_list2->next = 0;

}

void bubble_sort(linked_list *&list){ //worst sort

	if (!list) throw "empty struct";
	linked_list *start = list;
	linked_list *end = list;
	while (end->next)
	{
		end = end->next;
	}

	while (start != end)
	{
		linked_list *temp = start;
		linked_list *temp2 = start;

		while (temp != end)
		{
			if (temp->data > temp->next->data)
			{
				int buffer;
				buffer = temp->data;
				temp->data = temp->next->data;
				temp->next->data = buffer;
			}
			temp2 = temp;
			temp = temp->next;
		}
		end = temp2;
	}



}
