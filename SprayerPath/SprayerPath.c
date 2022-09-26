

#include <stdio.h>
#include <stdio.h>
int list[] = { 4, 4,34,23,5,6,2, 1, 2 };

struct ListNode {
	int val;
	struct ListNode* next;
};

void bubbleSort(int array[], int size) {

	for (int step = 0; step < size - 1; ++step) {
		int swapped = 0;

		for (int i = 0; i < size - step - 1; ++i) {

			if (array[i] > array[i + 1]) {

				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
			}
		}

		if (swapped == 0) {
			break;
		}

	}
}


void push(struct ListNode** head, int value) {

	//struct ListNode* current = head;
	//while (current->next != NULL) {
	//	current = current->next;
	//}

	///* now we can add a new variable */
	//current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	//current->next->val = value;
	//current->next->next = NULL;

		// allocate node
	struct ListNode* new_node
		= (struct ListNode*)malloc(sizeof(struct ListNode));

	// put in the data
	new_node->val = value;

	// link the old list
	// off the new node
	new_node->next = (*head);

	// move the head to point
	// to the new node
	(*head) = new_node;
}


void print_list(struct ListNode* head) {
	struct ListNode* current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* current = head;
	struct ListNode* nextNext;
	struct ListNode* ptr = current;

	if (current == NULL) {

	}
	while (current->next != NULL)
	{
		/* Compare current node with next node */
		if (current->val == current->next->val)
		{

			while (current->next != NULL) {

				if (current->val == current->next->val)
				{
					nextNext = current->next->next;
					free(current->next);
					current->next = nextNext;
				}
				else {
					break;
				}

			}

			nextNext = current->next;
			ptr->next = nextNext;
			free(current);
			current = nextNext;

		}
		else /* This is tricky: only advance if no deletion */
		{
			ptr = current;
			current = current->next;
		}
	}
	return head;
}
int main()
{
	int size = sizeof(list) / sizeof(list[0]);
	bubbleSort(list, size);

	struct ListNode* head = NULL;
	for (int i = 0; i < size; i++) {
		push(&head, list[i]);
	}
	print_list(head);
	printf("\n");
	print_list(deleteDuplicates(head));

}