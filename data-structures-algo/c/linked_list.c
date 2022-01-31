struct node {
	int32_t data;
	struct node *next;
};

void
AppendToList(struct node **head, int32_t data) {
	if (*head == 0) {
		struct node *head_alias;
		head_alias = (struct node *)malloc(sizeof(struct node));
		head_alias->data = data;
		head_alias->next = 0;
		*head = head_alias;
	} else {
		struct node *travel = *head;
		struct node *temp;
		while (travel->next != 0) {
			travel = travel->next;
		}
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = 0;
		travel->next = temp;
	}
}

void
PushToList(struct node **head, int32_t data) {
	if (*head != 0) {
		struct node *temp =
			(struct node *)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = *head;
		*head = temp;
	}
}

void
InsertAtList(struct node **head, uint32_t position, int32_t data) {
	uint32_t index = 0;
	struct node *temp =
		(struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = 0;
	struct node *current = *head;
	struct node *next = 0;
	while(current->next != 0) {
		next = current->next;
		if (index == position - 1) {
			current->next = temp;
			temp->next = next;
		}
		index++;
		current = next;
	}
}

void
DeleteList(struct node **head) {
	struct node *current = *head;
	struct node *next = 0;
	while (current) {
		next = current->next;
		free(current);
		current = next;
	}
}

void
ReverseList(struct node **head) {
	struct node *previous = 0;
	struct node *current = *head;
	struct node *next = 0;
	while(current != 0) {
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}

int32_t
MidElementsList(struct node **head) {
	struct node *fast = *head;
	struct node *slow = *head;
	int32_t data = 0;
	while(fast->next != 0) {
		if (fast->next->next != 0) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast->next == 0) {
				data = slow->data;
				break;
			} else if (fast->next->next == 0) {
				data = slow->next->data;
				break;
			}
		}
	}
	return data;
}
