#include <stdint.h>
#include <stdlib.h>

#include "linked_list.c"
#include "dynamic_fib.c"
#include "sorting.c"

#define ArraySize(Array) ((sizeof(Array))/(sizeof(Array)[0]))

struct node* mergeTwoLists(struct node* list1, struct node* list2){
	if (list1 == 0) {
		return list2;
	}

	if (list2 == 0) {
		return list1;
	}

	struct node *sorted = 0;
	if (list1->data < list2->data) {
		sorted = list1;
		list1 = list1->next;
		sorted->next = 0;
	} else if (list1->data > list2->data) {
		sorted = list2;
		list2 = list2->next;
		sorted->next = 0;
	}

	while(list1 && list2) {
		if (list1->data < list2->data) {
			sorted->next = list1;
			list1 = list1->next;
			sorted = sorted->next;
			sorted->next = 0;
		}
		if (list1->data > list2->data) {
			sorted->next = list2;
			list2 = list2->next;
			sorted = sorted->next;
			sorted->next = 0;
		}
	}

	if (list1) {
		sorted->next = list1;
	}

	if (list2) {
		sorted->next = list2;
	}

	return sorted;
}

int main() {
	struct node *list1 = 0;
	AppendToList(&list1, 3);
	AppendToList(&list1, 4);
	AppendToList(&list1, 5);
	AppendToList(&list1, 6);
	AppendToList(&list1, 7);
	AppendToList(&list1, 8);
	AppendToList(&list1, 9);
	PushToList(&list1, 2);
	PushToList(&list1, 1);
	InsertAtList(&list1, 4, 32);
	ReverseList(&list1);


	struct node *list2 = 0;
	AppendToList(&list2, 13);
	AppendToList(&list2, 14);
	AppendToList(&list2, 15);
	AppendToList(&list2, 16);
	AppendToList(&list2, 17);
	AppendToList(&list2, 18);
	AppendToList(&list2, 19);
	PushToList(&list2, 12);
	PushToList(&list2, 11);
	InsertAtList(&list2, 4, 32);

	struct node *sorted = mergeTwoLists(list1, list2);

	DeleteList(&list1);
	DeleteList(&list2);

	int32_t array[] = {3, 1, 4, 2, 5, 6, 9, 8, 0};
	QuickSortI32(array, ArraySize(array) - 1, 0);
}
