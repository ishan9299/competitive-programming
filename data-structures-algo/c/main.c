#include <stdint.h>
#include <stdlib.h>

#include "linked_list.c"
#include "dynamic_fib.c"
#include "sorting.c"

#define ArraySize(Array) ((sizeof(Array))/(sizeof(Array)[0]))

int main() {
	struct node *head = 0;
	AppendToList(&head, 3);
	AppendToList(&head, 4);
	AppendToList(&head, 5);
	AppendToList(&head, 6);
	AppendToList(&head, 7);
	AppendToList(&head, 8);
	AppendToList(&head, 9);
	PushToList(&head, 2);
	PushToList(&head, 1);
	InsertAtList(&head, 4, 32);
	ReverseList(&head);
	DeleteList(&head);

	int32_t array[] = {3, 1, 4, 2, 5, 6, 9, 8, 0};
	QuickSortI32(array, ArraySize(array) - 1, 0);
}
