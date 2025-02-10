#include "linkedList.h"

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int *sorted(const int arr[], unsigned int n)
{
	int *sorted = malloc(n * sizeof(int));
	if (!sorted)
	{
		exit(1);
	}

	for (unsigned int i = 0; i < n; i++)
	{
		sorted[i] = arr[i];
	}
	qsort(sorted, n, sizeof(int), compare);
	return sorted;
}

LinkedListNode *createLinkedListNode(const int data)
{
	LinkedListNode *node = malloc(sizeof(LinkedListNode));
	if (!node)
	{
		exit(1);
	}

	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

LinkedListNode *createLinkedList(const int nodes[], const unsigned int nodeCount)
{
	LinkedListNode *head = createLinkedListNode(234); // dummy head

	if (!nodes || nodeCount == 0)
	{
		return head;
	}

	// Sort the nodes
	int *nodesSorted = sorted(nodes, nodeCount);

	// Create the head node

	// Create aux node to iterate
	LinkedListNode *current = head;

	for (int i = 0; i < nodeCount; i++)
	{
		LinkedListNode *newNode = createLinkedListNode(nodesSorted[i]);
		newNode->prev = current;

		current->next = newNode;
		current = newNode;
	}

	free(nodesSorted);
	nodesSorted = NULL;

	return head;
}

void insertLinkedListNode(LinkedListNode *const head, const int data)
{
	if (head == NULL)
	{
		return;
	}

	LinkedListNode *newNode = createLinkedListNode(data);
	if (head->next == NULL)
	{
		head->next = newNode;
		newNode->prev = head;
		return;
	}

	LinkedListNode *current = head;

	while (current->next != NULL && current->next->data < data)
	{
		current = current->next;
	}

	if (current->next)
	{
		current->next->prev = newNode;
		newNode->next = current->next;
	}

	current->next = newNode;
	newNode->prev = current;
}

void printLinkedListRecurse(const LinkedListNode *const head)
{
	if (head == NULL)
	{
		return;
	}

	printf("%d ", head->data);
	printLinkedListRecurse(head->next);
}

void printLinkedList(const LinkedListNode *const head)
{
	printf("List: ");
	printLinkedListRecurse(head->next);
	printf("\n");
}

void freeLinkedList(LinkedListNode **head)
{
	if (!head || !(*head))
	{
		return;
	}

	freeLinkedList(&(*head)->next);

	if ((*head))
	{
		free(*head);
		*head = NULL;
	}
	
}
